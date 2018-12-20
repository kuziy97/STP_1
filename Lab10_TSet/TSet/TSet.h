#pragma once
#include <set>
#include <algorithm>

template<class T>
class TSet : public std::set<T> {
public:
	bool soderzhit(T value) { 
		return this->find(value) != this->end();
	}

	TSet<T> obedinenie(TSet<T> value) { 
		TSet result;

		std::set_union(this->begin(), this->end(), value.begin(), value.end(), std::inserter(result, result.begin()));

		return result;
	}

	TSet<T> raznost(TSet<T> value) { 
		TSet result;

		std::set_difference(this->begin(), this->end(), value.begin(), value.end(), std::inserter(result, result.begin()));

		return result;
	}

	TSet<T> peresechenie(TSet<T> value) { 
		TSet result;

		std::set_intersection(this->begin(), this->end(), value.begin(), value.end(), std::inserter(result, result.begin()));

		return result;
	}

	T getElement(int index) {
		return *std::next(std::set<T>::begin(), index);
	}
};