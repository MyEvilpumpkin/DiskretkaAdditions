#pragma once
#include "SpecialType.h"
#include "N.h"
#include <string>

// Описание натурального числа
class Z : public SpecialType {
	// Поля
	N number;  // Натуральное число
	bool sign; // Знак числа (false - отрицательное, true - положительное)
public:
	// Конструкторы и деструкторы
	Z();                  // Конструктор по умолчанию
	Z(const int);         // Конструктор преобразования int в Z (только для дебага)
	Z(const std::string); // Конструктор преобразования std::string в Z
	Z(const Z&);          // Конструктор копирования
	Z(Z&&) noexcept;      // Конструктор копирования с переносом
	~Z();                 // Деструктор по умолчанию

	// Перегрузка операторов
	Z& operator = (const Z&);     // Перегрузка оператора присваивания
	Z& operator = (Z&&) noexcept; // Перегрузка оператора присваивания с переносом

	// Переопределение функций базового класса
	void SetZero() override;               // Установка нуля
	void SetOne() override;                // Установка единицы
	bool IsZero() const override;          // Проверка на равенство с нулём
	bool IsOne() const override;           // Проверка на равенство с единицей
	std::string ToString() const override; // Преобразование Z в std::string
	void Normalize() override;             // Нормализация числа

	// Дружественные функции
	friend N ABS_Z_N(const Z&);            // Z-1
	friend int POZ_Z_D(const Z&);          // Z-2
	friend Z MUL_ZM_Z(const Z&);           // Z-3
	friend Z TRANS_N_Z(const N&);          // Z-4
	friend N TRANS_Z_N(const Z&);          // Z-5
	friend Z ADD_ZZ_Z(const Z&, const Z&); // Z-6
	friend Z SUB_ZZ_Z(const Z&, const Z&); // Z-7
	friend Z MUL_ZZ_Z(const Z&, const Z&); // Z-8
	friend Z DIV_ZN_Z(const Z&, const N&); // Z-9
	friend Z MOD_ZN_Z(const Z&, const N&); // Z-10

	// Дружественные классы
	friend class Q;
	friend class P;
};

// Модули
N ABS_Z_N(const Z&);            // Z-1
int POZ_Z_D(const Z&);          // Z-2
Z MUL_ZM_Z(const Z&);           // Z-3
Z TRANS_N_Z(const N&);          // Z-4
N TRANS_Z_N(const Z&);          // Z-5
Z ADD_ZZ_Z(const Z&, const Z&); // Z-6
Z SUB_ZZ_Z(const Z&, const Z&); // Z-7
Z MUL_ZZ_Z(const Z&, const Z&); // Z-8
Z DIV_ZN_Z(const Z&, const N&); // Z-9
Z MOD_ZN_Z(const Z&, const N&); // Z-10

