#pragma once
#include "SpecialType.h"
#include <string>

// Определение типа digit
typedef char digit;

// Описание натурального числа
class N : public SpecialType {
	// Поля
	digit* digits; // Указатель на младший разряд числа
	size_t size;   // Количество разрядов в числе
public:
	// Конструкторы и деструкторы
	N();                   // Конструктор по умолчанию
	N(const unsigned int); // Конструктор преобразования unsigned int в N (только для дебага)
	N(const std::string);  // Конструктор преобразования std::string в N
	N(const N&);           // Конструктор копирования
	N(N&&) noexcept;       // Конструктор копирования с переносом
	~N();                  // Деструктор по умолчанию

	// Перегрузка операторов
	N& operator = (const N&);     // Перегрузка оператора присваивания
	N& operator = (N&&) noexcept; // Перегрузка оператора присваивания с переносом

	// Переопределение функций базового класса
	void SetZero() override;               // Установка нуля
	void SetOne() override;                // Установка единицы
	bool IsZero() const override;          // Проверка на равенство с нулём
	bool IsOne() const override;           // Проверка на равенство с единицей
	std::string ToString() const override; // Преобразование N в std::string
	void Normalize() override;             // Нормализация числа

	// Дружественные функции
	friend int COM_NN_D(const N&, const N&);           // N-1
	friend bool NZER_N_B(const N&);                    // N-2
	friend N ADD_1N_N(const N&);                       // N-3
	friend N ADD_NN_N(const N&, const N&);             // N-4
	friend N SUB_NN_N(const N&, const N&);             // N-5
	friend N MUL_ND_N(const N&, const int);            // N-6
	friend N MUL_Nk_N(const N&, const unsigned int);   // N-7
	friend N MUL_NN_N(const N&, const N&);             // N-8
	friend N SUB_NDN_N(const N&, const int, const N&); // N-9
	friend int DIV_NN_Dk(const N&, const N&, int&);    // N-10
	friend N DIV_NN_N(const N&, const N&);             // N-11
	friend N MOD_NN_N(const N&, const N&);             // N-12
	friend N GCF_NN_N(const N&, const N&);             // N-13
	friend N LCM_NN_N(const N&, const N&);             // N-14

	// Дружественные классы
	friend class Z;
	friend class Q;
};

// Модули
int COM_NN_D(const N&, const N&);           // N-1
bool NZER_N_B(const N&);                    // N-2
N ADD_1N_N(const N&);                       // N-3
N ADD_NN_N(const N&, const N&);             // N-4
N SUB_NN_N(const N&, const N&);             // N-5
N MUL_ND_N(const N&, const int);            // N-6
N MUL_Nk_N(const N&, const unsigned int);   // N-7
N MUL_NN_N(const N&, const N&);             // N-8
N SUB_NDN_N(const N&, const int, const N&); // N-9
int DIV_NN_Dk(const N&, const N&, int&);    // N-10
N DIV_NN_N(const N&, const N&);             // N-11
N MOD_NN_N(const N&, const N&);             // N-12
N GCF_NN_N(const N&, const N&);             // N-13
N LCM_NN_N(const N&, const N&);             // N-14

