#pragma once
#include <string>

class SpecialType {
public:
	virtual void SetZero() = 0;
	virtual void SetOne() = 0;
	virtual bool IsZero() const = 0;
	virtual bool IsOne() const = 0;
	virtual std::string ToString() const = 0;
	virtual void Normalize() = 0;
	virtual ~SpecialType() = 0 {}
};
