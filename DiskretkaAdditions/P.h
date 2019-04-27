#pragma once
#include "SpecialType.h"
#include "Q.h"
#include <string>

// Описание натурального числа
class P : public SpecialType {
	// Поля
	Q* coefficients; // Указатель на адрес свободного коэффициента, представленного в виде рационального числа
	size_t power;    // Степень многочлена
public:
	// Конструкторы и деструкторы
	P();                  // Конструктор по умолчанию
	P(const std::string); // Конструктор преобразования std::string в P
	P(const P&);          // Конструктор копирования
	P(P&&) noexcept;      // Конструктор копирования с переносом
	~P();                 // Деструктор по умолчанию

	// Перегрузка операторов
	P& operator = (const P&);     // Перегрузка оператора присваивания
	P& operator = (P&&) noexcept; // Перегрузка оператора присваивания с переносом

	// Переопределение функций базового класса
	void SetZero() override;               // Установка нуля
	void SetOne() override;                // Установка единицы
	bool IsZero() const override;          // Проверка на равенство с нулём
	bool IsOne() const override;           // Проверка на равенство с единицей
	std::string ToString() const override; // Преобразование P в std::string
	void Normalize() override;             // Нормализация числа

	// Дружественные функции
	friend P ADD_PP_P(const P&, const P&);            // P-1
	friend P SUB_PP_P(const P&, const P&);            // P-2
	friend P MUL_PQ_P(const P&, const Q&);            // P-3
	friend P MUL_Pxk_P(const P&, const unsigned int); // P-4
	friend Q LED_P_Q(const P&);                       // P-5
	friend N DEG_P_N(const P&);                       // P-6
	friend Q FAC_P_Q(const P&);                       // P-7
	friend P MUL_PP_P(const P&, const P&);            // P-8
	friend P DIV_PP_P(const P&, const P&);            // P-9
	friend P MOD_PP_P(const P&, const P&);            // P-10
	friend P GCF_PP_P(const P&, const P&);            // P-11
	friend P DER_P_P(const P&);                       // P-12
	friend P NMR_P_P(const P&);                       // P-13
};

// Модули
P ADD_PP_P(const P&, const P&);            // P-1
P SUB_PP_P(const P&, const P&);            // P-2
P MUL_PQ_P(const P&, const Q&);            // P-3
P MUL_Pxk_P(const P&, const unsigned int); // P-4
Q LED_P_Q(const P&);                       // P-5
N DEG_P_N(const P&);                       // P-6
Q FAC_P_Q(const P&);                       // P-7
P MUL_PP_P(const P&, const P&);            // P-8
P DIV_PP_P(const P&, const P&);            // P-9
P MOD_PP_P(const P&, const P&);            // P-10
P GCF_PP_P(const P&, const P&);            // P-11
P DER_P_P(const P&);                       // P-12
P NMR_P_P(const P&);                       // P-13

