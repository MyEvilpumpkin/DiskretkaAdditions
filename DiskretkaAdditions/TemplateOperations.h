#pragma once
#include <string>

template<class T>
T* renew(T*& obj, const size_t oldSize, const size_t newSize) {
	T* newObj;
	if (newSize > 0) {
		newObj = new T[newSize];
		if (oldSize > 0)
			memcpy(newObj, obj, oldSize * sizeof(T));
	}
	else
		newObj = nullptr;
	delete[] obj;
	obj = newObj;
	return obj;
}