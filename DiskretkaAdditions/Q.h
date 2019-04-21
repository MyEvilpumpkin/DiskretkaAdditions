#pragma once
#include "SpecialType.h"
#include "Z.h"
#include <string>

// Описание натурального числа
class Q : public SpecialType {
	// Поля
	Z numerator;   // Числитель (целое число)
	N denominator; // Знаменатель (натуральное число)
public:
	// Конструкторы и деструкторы
	Q();                  // Конструктор по умолчанию
	Q(const int);         // Конструктор преобразования int в Q (только для дебага)
	Q(const std::string); // Конструктор преобразования std::string в Q
	Q(const Q&);          // Конструктор копирования
	Q(Q&&) noexcept;      // Конструктор копирования с переносом
	~Q();                 // Деструктор по умолчанию

	// Перегрузка операторов
	Q& operator = (const Q&);     // Перегрузка оператора присваивания
	Q& operator = (Q&&) noexcept; // Перегрузка оператора присваивания с переносом

	// Переопределение функций базового класса
	void SetZero() override;               // Установка нуля
	void SetOne() override;                // Установка единицы
	bool IsZero() const override;          // Проверка на равенство с нулём
	bool IsOne() const override;           // Проверка на равенство с единицей
	std::string ToString() const override; // Преобразование Q в std::string
	void Normalize() override;             // Нормализация числа

	// Дружественные функции
	friend Q RED_Q_Q(Q&);                  // Q-1
	friend bool INT_Q_B(Q&);               // Q-2
	friend Q TRANS_Z_Q(const Z&);          // Q-3
	friend Z TRANS_Q_Z(Q&);                // Q-4
	friend Q ADD_QQ_Q(const Q&, const Q&); // Q-5
	friend Q SUB_QQ_Q(const Q&, const Q&); // Q-6
	friend Q MUL_QQ_Q(const Q&, const Q&); // Q-7
	friend Q DIV_QQ_Q(const Q&, const Q&); // Q-8
};

// Модули
Q RED_Q_Q(Q&);                  // Q-1
bool INT_Q_B(Q&);               // Q-2
Q TRANS_Z_Q(const Z&);          // Q-3
Z TRANS_Q_Z(Q&);                // Q-4
Q ADD_QQ_Q(const Q&, const Q&); // Q-5
Q SUB_QQ_Q(const Q&, const Q&); // Q-6
Q MUL_QQ_Q(const Q&, const Q&); // Q-7
Q DIV_QQ_Q(const Q&, const Q&); // Q-8

