#pragma once
#include <string>

template<class T>
T* renew(T*& obj, const size_t oldSize, const size_t newSize) {
	if (oldSize != newSize) {
		T* newObj;
		if (newSize > 0) {
			newObj = new T[newSize];
			if (oldSize > 0) {
				size_t size = oldSize < newSize ? oldSize : newSize;
				for (size_t i = 0; i < size; i++)
					newObj[i] = std::move(obj[i]);
			}
		}
		else
			newObj = nullptr;
		delete[] obj;
		obj = newObj;
	}
	return obj;
}

