/*
 * MedianSet.h
 *
 *  Created on: Aug 25, 2014
 *      Author: jgdo
 */

#ifndef MEDIANSET_H_
#define MEDIANSET_H_

#include <set>

template<class T>
class MedianSet {
public:
	void clear() {
		left.clear();
		right.clear();
	}
	
	void insert(const T& t) {
		if (left.empty()) {
			left.insert(t);
		} else if (t < *left.rbegin()) {
			left.insert(t);
			
			if (left.size() > right.size() + 1) {
				T last = *left.rbegin();
				left.erase(--left.end());
				right.insert(last);
			}
		} else {
			right.insert(t);
			if (right.size() > left.size() + 1) {
				T first = *right.begin();
				right.erase(right.begin());
				left.insert(first);
			}
		}
	}
	
	const T median() const {
		if (left.size() > 3) {
			T sum = 0;
			auto itl = left.crbegin();
			sum += *itl++;
			sum += *itl++;
			sum += *itl++;
			
			auto itr = right.cbegin();
			sum += *itr++;
			sum += *itr++;
			sum += *itr++;
			
			return sum / (T) 6;
		} else {
			if (right.size() > left.size()) {
				return *right.cbegin();
			} else
				return *left.crbegin();
		}
	}
	
private:
	std::multiset<T> left, right;
};

#endif /* MEDIANSET_H_ */
