#pragma once
#include <exception>

class IncorrectString : public std::exception {
public:
	IncorrectString() : std::exception("Incorrect String") { }
};

class DivisionByZero : public std::exception {
public:
	DivisionByZero() : std::exception("Division By Zero") {}
};

