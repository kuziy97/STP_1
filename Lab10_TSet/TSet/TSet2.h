#pragma once
#include <iterator>
#include <set>
#include <algorithm>
#include <ostream>
using namespace std;
template<class T>
class TSet2 {
private:
	std::set<T> set;
public:
	void clear() {  
		set.clear();
	}

	void insert(T value) { 
		set.insert(value);
	}

	void erase(T value) { 
		set.erase(value);
	}

	bool empty() { 
		return set.empty();
	}

	bool soderzhit(T value) { 
		return set.find(value) != set.end();
	}

	TSet2<T> obedinenie(TSet2<T> value) {
		TSet2 result;

		std::set_union(set.begin(), set.end(), value.set.begin(), value.set.end(), std::inserter(result.set, result.set.begin()));

		return result;
	}

	TSet2<T> raznost(TSet2<T> value) {
		TSet2 result;

		std::set_difference(set.begin(), set.end(), value.set.begin(), value.set.end(), std::inserter(result.set, result.set.begin()));

		return result;
	}

	TSet2<T> peresechenie(TSet2<T> value) {
		TSet2 result;

		std::set_intersection(set.begin(), set.end(), value.set.begin(), value.set.end(), std::inserter(result.set, result.set.begin()));
		
		return result;
	}

	unsigned long size() {
		return set.size();
	}

	T getElement(int index) {
		return *std::next(set.begin(), index);
	}
};