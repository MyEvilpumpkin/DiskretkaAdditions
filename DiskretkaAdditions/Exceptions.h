#pragma once
#include <exception>

class IncorrectString : public std::exception {
public:
	IncorrectString() : std::exception("Incorrect String") { }
};

class DivideByZero : public std::exception {
public:
	DivideByZero() : std::exception("Divide By Zero") {}
};

