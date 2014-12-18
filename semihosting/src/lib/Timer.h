//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

#ifndef TIMER_H_
#define TIMER_H_

#include "cmsis_device.h"
#include <lib/InterruptQueue.h>

#include <list>
#include <unordered_map>
#include <functional>

unsigned long SystemMillisLong();

double SystemMillisDouble();

void WaitMillis(unsigned long millis);

class SysTickTimer {
public:
	SysTickTimer(unsigned long ticks, const std::function<void(void)>& callback, bool once = false);
	
	/**
	 * Call from SysTick timer ISR only
	 */
	static void onTick(); 
	
	/**
	 * call from main loop periodically
	 */
	static void handleTimers();
	
private:
	unsigned long period_ticks;
	unsigned long next_expired_tick;
	std::function<void(void)> callback;
	bool once;
	
	static InterruptQueue<char, 100> interrupt_queue;
	static std::unordered_multimap<unsigned long, SysTickTimer*> timer_map;
	static unsigned long current_synchronized_tick;
	
	void insetSelfIntoQueue();
};

// ----------------------------------------------------------------------------

#endif // TIMER_H_
