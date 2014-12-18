/*
 * InterruptQueue.h
 *
 *  Created on: Aug 16, 2014
 *      Author: jgdo
 */

#ifndef INTERRUPTQUEUE_H_
#define INTERRUPTQUEUE_H_

template<class T, unsigned NumElements>
class InterruptQueue {
public:
	InterruptQueue() {
		queue_start = queue_end = 0;
	}
	
	~InterruptQueue() {
		for (; queue_end != queue_start; queue_end = next(queue_end)) {
			t(queue_end)->~T();
		}
	}
	
	template<typename ... Args>
	inline void append(Args&&... args) {
		// TODO: check overflow
		unsigned n = next(queue_start);
		new (t(n)) T(args...); // construct element at next position first
		queue_start = n; // than finally increment counter
	}
	
	inline T pop() {
		// TODO check if buffer not empty
		T elem = *t(queue_end);
		t(queue_end)->~T();
		queue_end = next(queue_end);
		return elem;
	}
	
	template<class Func>
	inline void popAndApply(Func& f) {
		// TODO check if buffer not empty
		f(*t(queue_end));
		t(queue_end)->~T();
		queue_end = next(queue_end);
	}
	
	inline int size() const {
		int s = queue_start - queue_end;
		if (s < 0)
			s += NumElements;
		return s;
	}
	
	inline bool empty() const {
		return size() == 0;
	}
	
private:
	unsigned queue_start, queue_end;

	inline unsigned next(unsigned current) {
		if (current < NumElements - 1)
			return current + 1;
		else
			return 0;
	}
	
	inline T* t(unsigned pos) {
		return ((T*) queue_buffer) + pos;
	}
	
	char queue_buffer[sizeof(T) * NumElements];
};

#endif /* INTERRUPTQUEUE_H_ */
