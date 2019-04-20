#include "Q.h"
#include "QRecognizer.h"
#include "Exceptions.h"
#include "TemplateOperations.h"

Q::Q() : numerator(), denominator() {

}

Q::Q(const int num) : Q() {
	Z temp(num);
	numerator = temp;
	denominator.SetOne();
}

Q::Q(const std::string str) : Q() {
	QRecognizer recognizer(str);
	bool status = recognizer.GetStatus();
	if (status) {
		std::string tempStr = recognizer.GetPreparedString();
		size_t pos = 0;
		bool isDenom = false;
		numerator.sign = tempStr[pos] == '+';
		while (tempStr[pos + 1] != '\0') {
			if (tempStr[pos + 1] == '/')
				isDenom = true;
			if (tempStr[pos + 1] >= '0' && tempStr[pos + 1] <= '9')
				if (isDenom) {
					renew<digit>(denominator.digits, denominator.size, denominator.size + 1);
					denominator.digits[denominator.size++] = tempStr[pos + 1] - '0';
				}
				else {
					renew<digit>(numerator.number.digits, numerator.number.size, numerator.number.size + 1);
					numerator.number.digits[numerator.number.size++] = tempStr[pos + 1] - '0';
				}
			pos++;
		}
		if (!denominator.size)
			denominator.SetOne();
		else {
			for (size_t i = 0; i < (denominator.size / 2); i++) {
				digit temp = denominator.digits[i];
				denominator.digits[i] = denominator.digits[denominator.size - 1 - i];
				denominator.digits[denominator.size - 1 - i] = temp;
			}
		}
		if (!numerator.number.size)
			numerator.number.SetOne();
		else {
			for (size_t i = 0; i < (numerator.number.size / 2); i++) {
				digit temp = numerator.number.digits[i];
				numerator.number.digits[i] = numerator.number.digits[numerator.number.size - 1 - i];
				numerator.number.digits[numerator.number.size - 1 - i] = temp;
			}
		}
		Normalize();
	}
	else
		throw WrongString();
}

Q::Q(const Q& q) : Q() {
	if (this != &q) {
		numerator = q.numerator;
		denominator = q.denominator;
	}
}

Q::Q(Q&& q) noexcept : Q() {
	if (this != &q) {
		numerator = std::move(q.numerator);
		denominator = std::move(q.denominator);
	}
}

Q::~Q() {

}

Q& Q::operator=(const Q& q) {
	if (this != &q) {
		numerator = q.numerator;
		denominator = q.denominator;
	}
	return *this;
}

Q& Q::operator=(Q&& q) noexcept {
	if (this != &q) {
		numerator = std::move(q.numerator);
		denominator = std::move(q.denominator);
	}
	return *this;
}

void Q::SetZero() {
	numerator.SetZero();
	denominator.SetOne();
}

void Q::SetOne() {
	numerator.SetOne();
	denominator.SetOne();
}

bool Q::IsZero() const {
	return numerator.IsZero();
}

bool Q::IsOne() const {
	return (numerator.IsOne() && denominator.IsOne());
}

std::string Q::ToString() const {
	std::string str;
	if (!numerator.sign)
		str += "- ";
	str += numerator.number.ToString();
	if (!denominator.IsOne()) {
		str += '/';
		str += denominator.ToString();
	}
	return str;
}

void Q::Normalize() {
	N d = GCF_NN_N(numerator.number, denominator); // ����������� d �������� ���� (������ ��������� �����) � ����������� ����� 
	while (!d.IsOne()) { // �� ��� ��� ���� d �� ������ ������ 1  
		numerator.number = DIV_NN_N(numerator.number, d); // ��������� ��������� �� d
		denominator = DIV_NN_N(denominator, d); // ��������� ����������� �� d
		d = GCF_NN_N(numerator.number, denominator); // ����������� d �������� ���� (������ ��������� �����) � ����������� �����  
	}
}

// Q-1
Q RED_Q_Q(Q& q) {
	q.Normalize();
	return q;
}

// Q-2
bool INT_Q_B(Q& q) {
	return (RED_Q_Q(q).IsOne()); // ���������� ���������� ������������ � ���, ��� ����������� ����� = 1
}

// Q-3
Q TRANS_Z_Q(const Z& z) {
	Q result;
	result.numerator = z; // ������������ ��������� ���������� �������� ������ �����
	result.denominator.SetOne();
	return result;
}

// Q-4
Z TRANS_Q_Z(Q& q) {
	return Z(RED_Q_Q(q).numerator); // ���������� �������� ��������� ����������� ����� 
}

// Q-5
Q ADD_QQ_Q(Q& q1, Q& q2) {
	Q result;
	result.denominator = MUL_NN_N(q1.denominator, q2.denominator); // ������� ������������ � ���������� � �����������
	result.numerator = ADD_ZZ_Z(MUL_ZZ_Z(q1.numerator, TRANS_N_Z(q2.denominator)), MUL_ZZ_Z(q2.numerator, TRANS_N_Z(q1.denominator))); 
	return RED_Q_Q(result);
}

// Q-6
Q SUB_QQ_Q(Q& q1, Q& q2) {
	Q result;
	result.denominator = MUL_NN_N(q1.denominator, q2.denominator); // ������� ������������ � ���������� � �����������
	result.numerator = SUB_ZZ_Z(MUL_ZZ_Z(q1.numerator, TRANS_N_Z(q2.denominator)), MUL_ZZ_Z(q2.numerator, TRANS_N_Z(q1.denominator)));
	return RED_Q_Q(result);
}

// Q-7
Q MUL_QQ_Q(Q& q1, Q& q2) {
	Q result;
	result.denominator = MUL_NN_N(q1.denominator, q2.denominator); // ����������� ���������
	result.numerator = MUL_ZZ_Z(q1.numerator, q2.numerator); // ����������� �����������
	return RED_Q_Q(result);
}

// Q-8
Q DIV_QQ_Q(Q& q1, Q& q2) {
	Q result;
	if (!POZ_Z_D(q1.numerator) || !POZ_Z_D(q2.numerator)) // E��� ��������� = 0
		result.SetZero();
	else {
		result.numerator = MUL_ZZ_Z(q1.numerator, TRANS_N_Z(q2.denominator)); // ��������� ��������� ���������� ������������ ������� ��������� � ������� �����������
		result.denominator = MUL_NN_N(q1.denominator, TRANS_Z_N(q2.numerator)); // ��������� ����������� ���������� ������������ ������� ����������� � ������� ���������
	}
	return RED_Q_Q(result);
}

