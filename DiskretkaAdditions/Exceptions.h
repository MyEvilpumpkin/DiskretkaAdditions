#pragma once
#include <exception>

class WrongString : public std::exception {
public:
	WrongString() : std::exception("Wrong String") { }
};

class DivideByZero : public std::exception {
public:
	DivideByZero() : std::exception("Divide By Zero") {}
};

