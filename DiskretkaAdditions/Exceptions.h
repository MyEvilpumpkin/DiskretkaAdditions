#pragma once
#include <exception>

class IncorrectString : public std::exception {
public:
	IncorrectString() : std::exception("Ошибка: Введены некорректные данные") { }
};

class ArithmeticalError : public std::exception {
public:
	ArithmeticalError(const char* str) : std::exception(str) { }
};

class SubtractionError : public ArithmeticalError {
public:
	SubtractionError() : ArithmeticalError("Ошибка: Попытка вычитания большего натурального числа из меньшего") { }
};

class DivisionByZero : public ArithmeticalError {
public:
	DivisionByZero() : ArithmeticalError("Ошибка: Попытка деления на 0") { }
};

class DivisionByMore : public ArithmeticalError {
public:
	DivisionByMore() : ArithmeticalError("Ошибка: Попытка деления меньшего целого (по модулю) на большее натуральное") { }
};

class NotADigit : public ArithmeticalError {
public:
	NotADigit() : ArithmeticalError("Ошибка: Попытка умножения на число, а не на цифру") { }
};

class Error : public std::exception {
public:
	Error(const char* str) : std::exception(str) { }
};

