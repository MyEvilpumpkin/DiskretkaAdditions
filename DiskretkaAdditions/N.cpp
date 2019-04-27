#include "N.h"
#include "NRecognizer.h"
#include "Exceptions.h"
#include "TemplateOperations.h"

N::N() : digits(nullptr), size((size_t)0) {

}

N::N(const std::string str) : N() {
	NRecognizer recognizer(str);
	bool status = recognizer.GetStatus();
	if (status) {
		std::string tempStr = recognizer.GetPreparedString();
		int pos = 0;
		while (tempStr[pos] != '\0') {
			renew<digit>(digits, size, size + 1);
			digits[size++] = tempStr[pos] - '0';
			pos++;
		}
		for (size_t i = 0; i < (size / 2); i++) {
			digit temp = digits[i];
			digits[i] = digits[size - 1 - i];
			digits[size - 1 - i] = temp;
		}
	}
	else
		throw IncorrectString();
}

N::N(const N& n) : N() {
	if (this != &n) {
		if (n.size) {
			size = n.size;
			digits = new digit[size];
			memcpy(digits, n.digits, size * sizeof(digit));
		}
	}
}

N::N(N&& n) noexcept : N() {
	if (this != &n) {
		size = n.size;
		n.size = 0;
		digits = n.digits;
		n.digits = nullptr;
	}
}

N::~N() {
	delete[] digits;
}

N& N::operator=(const N& n) {
	if (this != &n) {
		delete[] digits;
		size = 0;
		if (n.size) {
			size = n.size;
			digits = new digit[size];
			memcpy(digits, n.digits, size * sizeof(digit));
		}
	}
	return *this;
}

N& N::operator=(N&& n) noexcept {
	if (this != &n) {
		delete[] digits;
		size = 0;
		size = n.size;
		n.size = 0;
		digits = n.digits;
		n.digits = nullptr;
	}
	return *this;
}

void N::SetZero() {
	delete[] digits;
	digits = new digit[1];
	digits[0] = 0;
	size = 1;
}

void N::SetOne() {
	delete[] digits;
	digits = new digit[1];
	digits[0] = 1;
	size = 1;
}

bool N::IsZero() const {
	return (size == 1 && digits[0] == 0);
}

bool N::IsOne() const {
	return (size == 1 && digits[0] == 1);
}

std::string N::ToString() const {
	std::string str;
	for (int i = (int)size - 1; i >= 0; i--)
		str += (digits[i] + '0');
	return str;
}

void N::Normalize() {
	if (size > 1) {
		int i;
		bool flag = false;
		for (i = (int)size - 1; i >= 0 && !flag; i--)
			flag = digits[i];
		renew<digit>(digits, size, (size_t)i + (size_t)2);
		size = (size_t)i + (size_t)2;
	}
}

// N-1
int COM_NN_D(const N& n1, const N& n2) {
	if (n1.size > n2.size) // Если первое число больше второго
		return 2;
	else if (n1.size < n2.size) // Если второе число больше первого
		return 1;
	else {
		for (int i = (int)n1.size - 1; i >= 0; i--) // Цикл до последней числа
			if (n1.digits[i] > n2.digits[i]) // Если цифра первого числа больше цифры второго
				return 2;
			else if (n1.digits[i] < n2.digits[i]) // Наоборот
				return 1;
		return 0; // Если длины двух чисел и все их цифры оказались равны (числа равны)
	}
}

// N-2
bool NZER_N_B(const N& n) {
	return (n.size != 1 || n.digits[0] != 0); // Число равно 0, если в числе есть только один разряд и он равен 0
}

// N-3
N ADD_1N_N(const N& n) {
	N result = n;
	if (result.digits[0] != 9) // Если последний разряд числа не равен 9, то прибавляем к нему единицу
		result.digits[0]++;
	else { // Если последний разряд равен 9, то заменяем его и все последующие девятки на нули и прибавляем единицу к первой не девятке 
		size_t count = 0;
		while (result.digits[count] == 9)
			result.digits[count++] = 0;
		if (count == result.size) { // Если в числе все цифры девятки, то необходимо создать новый разряд
			renew<digit>(result.digits, result.size, result.size + 1);
			result.size++;
			result.digits[count] = 1; // Значение нового разряда равно единице
		}
		else
			result.digits[count]++; // Если в числе не все девятки, то первую не девятку увеличиваем на единицу
	}
	return result;
}

// N-4
N ADD_NN_N(const N& n1, const N& n2) {
	N result;
	bool temp = false;
	const N* first,* second;
	if (COM_NN_D(n1, n2) == 2) { // Если n1>n2
		first = &n1;
		second = &n2;
	}
	else { // Если n1<n2
		first = &n2;
		second = &n1;
	}
	result.digits = new digit[first->size];
	result.size = first->size;
	for (size_t i = 0; i < first->size; i++) {
		if (i < second->size) {
			result.digits[i] = first->digits[i] + second->digits[i] + temp; // Складываем соответствующие разряды
			temp = result.digits[i] > 9;
			result.digits[i] %= 10; // Определяем разряд
		}
		else if (temp) {
			result.digits[i] = first->digits[i] + temp; // Присваиваем соответствующие разряды
			temp = result.digits[i] > 9;
			result.digits[i] %= 10; // Определяем разряд
		}
		else
			result.digits[i] = first->digits[i];
	}
	if (temp) { // Создаем разряд, если нужно
		renew<digit>(result.digits, result.size, result.size + 1);
		result.size++;
		result.digits[result.size - 1] = temp;
	}
	return result;
}

// N-5
N SUB_NN_N(const N& n1, const N& n2) {
	N result;
	bool temp = false;
	int com = COM_NN_D(n1, n2);
	if (com == 2) { // Проверка на правильность введенных данных
		result.digits = new digit[n1.size]; // Выделение памяти под очередную цифру результата
		result.size = n1.size;
		for (size_t i = 0; i < n1.size; i++) { // Цикл до конца числа
			if (i < n2.size) { // Если счётчик меньше длины меньшего числа (числа "накладываются" друг на друга)
				result.digits[i] = n1.digits[i] - n2.digits[i] - temp; // Проводим обыкновенное вычитание
				temp = result.digits[i] < 0;
				if (temp)
					result.digits[i] += 10;
			}
			else {
				if (temp)
					if (n1.digits[i] == 0)
						result.digits[i] = 9;
					else {
						result.digits[i] = n1.digits[i] - temp;
						temp = false;
					}
				else
					result.digits[i] = n1.digits[i]; // Иначе мы ничего с цифрами не делаем, а просто "переписываем" их в результат
			}
		}
		result.Normalize(); // Отбрасываем образовавшиеся незначащие нули
	}
	else if (com == 1)
		throw SubtractionError();
	else
		result.SetZero();
	return result;
}

// N-6
N MUL_ND_N(const N& n, const unsigned int d) {
	N result;
	if (d > 9)
		throw NotADigit();
	if (!d)
		result.SetZero();
	else if (d == 1)
		result = n;
	else {
		result.size = n.size;
		result.digits = new digit[result.size];
		int temp = 0;
		for (size_t i = 0; i < n.size; i++) {
			result.digits[i] = n.digits[i] * d + temp; // Промежуточный результат = разряд * цифру + остаток
			temp = result.digits[i] / 10; // Определяем остаток
			result.digits[i] %= 10; // Определяем разряд
		}
		if (temp) { // Создаём ещё один разряд, если остаток не 0
			renew<digit>(result.digits, result.size, result.size + 1);
			result.size++;
			result.digits[result.size - 1] = temp;
		}
	}
	return result;
}

// N-7
N MUL_Nk_N(const N& n, const unsigned int k) {
	N result;
	if (!NZER_N_B(n))
		result.SetZero();
	else {
		result.size = n.size + k; // Инициализируем размер суммой длины исходного числа и заданной степени k
		result.digits = new digit[result.size]; // Выделяем память для нашего числа
		for (size_t i = 0; i < result.size; i++) // Цикл до конца числа
			if (i < k) // Если счётчик меньше степни k
				result.digits[i] = 0; // "Домножаем" наше число на 10
			else
				result.digits[i] = n.digits[i - k]; // Подставляем на новую позицию (на k больше) цифру исходного числа
	}
	return result;
}

// N-8
N MUL_NN_N(const N& n1, const N& n2) {
	N result;
	result.SetZero();
	if (NZER_N_B(n1) && NZER_N_B(n2))
		for (size_t i = 0; i < n2.size; i++) // К результату, изначально равному 0, в каждом шаге цикла прибавляется i-ая цифра первого сомножителя
			result = ADD_NN_N(result, MUL_Nk_N(MUL_ND_N(n1, n2.digits[i]), (const unsigned int)i));  // Умноженная на второй сомножитель и на 10^i
	return result;
}

// N-9
N SUB_NDN_N(const N& n1, const unsigned int d, const N& n2) {
	N result;
	if (d > 9)
		throw NotADigit();
	int com = COM_NN_D(n1, n2);
	result = SUB_NN_N(n1, MUL_ND_N(n2, d)); // Вычитаем из первого числа второе (домноженное на цифру)
	return result;
}

// N-10
int DIV_NN_Dk(const N& n1, const N& n2, int& k) {
	int result = 1, flag;
	k = 0;
	const N* first,* second;
	int com = COM_NN_D(n1, n2);
	if (com == 2) { // Если делимое - первое число
		first = &n1;
		second = &n2;
	}
	else { // Если делимое - второе число
		first = &n2;
		second = &n1;
	}
	if (second->IsZero())
		throw DivisionByZero();
	if (com) {
		k = (int)(first->size - second->size);
		N temp = MUL_Nk_N(*second, k);
		if (COM_NN_D(*first, temp) == 1)
			temp = MUL_Nk_N(*second, --k); // Вычисляем наибольшее произведение делителя и 10^k, меньшее делимого
		do
			flag = COM_NN_D(*first, MUL_ND_N(temp, ++result)); // Вычисляем произведение на цифру и сравниваем его с делимым
		while (flag != 1 && result < 9);
		if (flag == 1)
			result--; // Аналогично значению степени
	}
	return result;
}

// N-11
N DIV_NN_N(const N& n1, const N& n2) {
	N result; // Частное от деления
	result.SetZero();
	const N* first,* second;
	int com = COM_NN_D(n1, n2);
	if (com == 2) {
		first = &n1;
		second = &n2;
	}
	else {
		first = &n2;
		second = &n1;
	}
	if (second->IsZero())
		throw DivisionByZero();
	if (com) {
		N part = *first; // Временный остаток от деления
		int k = 0;
		if (NZER_N_B(*second))
			do {
				N tempRes; // Cоздание произведения первой цифры деления на 10^k
				tempRes.SetZero();
				tempRes.digits[0] = DIV_NN_Dk(part, *second, k); // Вычисляем первую цифру и степень десятки при делении
				N temp = MUL_Nk_N(tempRes, k); // Умножаем на 10^k
				result = ADD_NN_N(result, temp); // Умножаем на 10^k и добавляем временный результат к общему
				part = SUB_NN_N(part, MUL_NN_N(temp, *second)); // Вычисление временного остатка
			} while (COM_NN_D(part, *second) != 1);
	}
	else
		result.digits[0] = 1;
	return result;
}

// N-12
N MOD_NN_N(const N& n1, const N& n2) {
	N result;
	int com = COM_NN_D(n1, n2);
	if (com == 2)
		result = SUB_NN_N(n1, MUL_NN_N(DIV_NN_N(n1, n2), n2)); // Разность большего числа и произведения
	else if (com == 1)
		result = SUB_NN_N(n2, MUL_NN_N(DIV_NN_N(n1, n2), n1)); // Разность большего числа и произведения
	else
		result.SetZero();
	return result;
}

// N-13
N GCF_NN_N(const N& n1, const N& n2) {
	N result;
	N first = n1;
	N second = n2;
	while (NZER_N_B(first) && NZER_N_B(second)) // Пока оба числа - не нули
		if (COM_NN_D(first, second) > 1) // Если первое больше второго
			first = MOD_NN_N(first, second); // Находим остаток от деления первого на второе
		else
			second = MOD_NN_N(second, first); // Иначе - остаток от деления второго на первое
	if (COM_NN_D(first, second) != 2) // Если первое число - больше второго
		result = second;
	else
		result = first;
	return result;
}

// N-14
N LCM_NN_N(const N& n1, const N& n2) {
	return DIV_NN_N(MUL_NN_N(n1, n2), GCF_NN_N(n1, n2));
}

