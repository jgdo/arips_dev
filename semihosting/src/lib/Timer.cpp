//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

#include "Timer.h"
#include "cortexm/ExceptionHandlers.h"

static volatile unsigned long systemMillisCount = 0;

unsigned long SystemMillisLong() {
	return systemMillisCount;
}

double SystemMillisDouble() {
	return systemMillisCount + (double)((SysTick->LOAD - SysTick->VAL) * 1000L) / (double)SystemCoreClock;
}

void WaitMillis(unsigned long millis) {
	unsigned long currentMillis = SystemMillisLong();
	unsigned long target = currentMillis + millis;
	
	if (target < currentMillis) { // overflow -> wait until overflow in system timer occurs
		while (SystemMillisLong() >= currentMillis)
			;
	}
	
	while (SystemMillisLong() < target)
		;
}

InterruptQueue<char, 100> SysTickTimer::interrupt_queue;
std::unordered_multimap<unsigned long, SysTickTimer*> SysTickTimer::timer_map;
unsigned long SysTickTimer::current_synchronized_tick = 0;

SysTickTimer::SysTickTimer(unsigned long ticks, const std::function<void(void)>& callback, bool once) :
		period_ticks(ticks), next_expired_tick(ticks + current_synchronized_tick), callback(callback), once(once) {
	insetSelfIntoQueue();
}

void SysTickTimer::onTick() {
	interrupt_queue.append(0);
}

void SysTickTimer::handleTimers() {
	while (!interrupt_queue.empty()) {
		interrupt_queue.pop();
		
		current_synchronized_tick++;
		
		auto range = timer_map.equal_range(current_synchronized_tick);
		if (range.second != range.first) {
			std::list<SysTickTimer*> to_call;
			for (std::unordered_map<unsigned long, SysTickTimer*>::iterator iter = range.first; iter != range.second;
			        ++iter) {
				to_call.push_back(iter->second);
			}
			
			timer_map.erase(range.first, range.second);
			for (auto timer : to_call) {
				timer->callback();
				timer->next_expired_tick += timer->period_ticks;
				timer->insetSelfIntoQueue();
			}
		}
	}
}

void SysTickTimer::insetSelfIntoQueue() {
	timer_map.insert(std::pair<unsigned long, SysTickTimer*>(next_expired_tick, this));
}
// ----------------------------------------------------------------------------
extern "C" void SysTick_Handler(void) {
	systemMillisCount++;
	
	SysTickTimer::onTick();
}
