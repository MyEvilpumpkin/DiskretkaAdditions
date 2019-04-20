#pragma once
#include <string>

template<class T>
T* renew(T*& obj, const size_t oldSize, const size_t newSize) {
	if (oldSize != newSize) {
		T* newObj;
		if (newSize > 0) {
			newObj = new T[newSize];
			if (oldSize > 0)
				if (oldSize < newSize)
					memcpy(newObj, obj, oldSize * sizeof(T));
				else
					memcpy(newObj, obj, newSize * sizeof(T));
		}
		else
			newObj = nullptr;
		delete[] obj;
		obj = newObj;
	}
	return obj;
}

