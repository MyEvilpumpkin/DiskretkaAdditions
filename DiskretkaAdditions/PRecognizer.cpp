#include "PRecognizer.h"

using namespace std;

/*
<polyn>::=<first_part><other_part>
<first_part>::=<sign_or_nothing><value>
<sign_or_nothing>::=<sign>|_/\_
<sign>::=+|-
<value>::=<coef><mul><x>
<coef>::=<num>|_/\_
<num>::=<first_digit><other_digit>|0
<first_digit>::=1|2|3|4|5|6|7|8|9
<other_digit>::=<digit><other_digit>|_/\_
<digit>::=0|1|2|3|4|5|6|7|8|9
<mul>::=*|_/\_
<x>::=x<power>|_/\_
<power>::=^<num>|_/\_
<other_part>::=<sign><value><other_part>|\0
*/

bool PRecognizer::_polyn() {
	bool isCorrect = true;
	if (isCorrect)
		isCorrect = _first_part();
	if (isCorrect)
		isCorrect = _other_part();
	return isCorrect;
}

bool PRecognizer::_first_part() {
	bool isCorrect = true;
	if (_sign_or_nothing())
		isCorrect = _coef();
	else
		isCorrect = false;
	return isCorrect;
}

bool PRecognizer::_sign_or_nothing() {
	bool isCorrect = true;
	_sign();
	return isCorrect;
}

bool PRecognizer::_sign() {
	bool isCorrect = true;
	if (str[pos] == '+' || str[pos] == '-')
		pos++;
	else
		isCorrect = false;
	return isCorrect;
}

bool PRecognizer::_coef() {
	bool isCorrect = true;
	if (str[pos] == '(') {
		pos++;
		if (_num()) {
			if (str[pos] == '/') {
				pos++;
				isCorrect = _num();
			}
			if (isCorrect)
				if (str[pos] == ')')
					pos++;
				else
					isCorrect = false;
			if (isCorrect) {
				if (_mul())
					if (_x())
						isCorrect = _power();
					else
						isCorrect = false;
				else
					if (_x())
						isCorrect = _power();
			}
		}
		else
			isCorrect = false;
	}
	else {
		if (_num()) {
			if (str[pos] == '/') {
				pos++;
				isCorrect = _num();
			}
			if (isCorrect) {
				if (_mul())
					if (_x())
						isCorrect = _power();
					else
						isCorrect = false;
				else
					if (_x())
						isCorrect = _power();
			}
		}
		else
			if (_x())
				isCorrect = _power();
			else
				isCorrect = false;
	}
	return isCorrect;
}

bool PRecognizer::_num() {
	bool isCorrect = true;
	if (_first_digit())
		isCorrect = _other_digit();
	else
		isCorrect = false;
	return isCorrect;
}

bool PRecognizer::_first_digit() {
	bool isCorrect = true;
	if (str[pos] >= '1' && str[pos] <= '9')
		pos++;
	else
		isCorrect = false;
	return isCorrect;
}

bool PRecognizer::_other_digit() {
	bool isCorrect = true;
	if (_digit())
		_other_digit();
	return isCorrect;
}

bool PRecognizer::_digit() {
	bool isCorrect = true;
	if (str[pos] >= '0' && str[pos] <= '9')
		pos++;
	else
		isCorrect = false;
	return isCorrect;
}

bool PRecognizer::_mul() {
	bool isCorrect = true;
	if (str[pos] == '*')
		pos++;
	else
		isCorrect = false;
	return isCorrect;
}

bool PRecognizer::_x() {
	bool isCorrect = true;
	if (str[pos] == 'x')
		pos++;
	else
		isCorrect = false;
	return isCorrect;
}

bool PRecognizer::_power() {
	bool isCorrect = true;
	if (str[pos] == '^') {
		pos++;
		isCorrect = _num();
	}
	return isCorrect;
}

bool PRecognizer::_other_part() {
	bool isCorrect = true;
	if (_sign()) {
		isCorrect = _coef();
		if (isCorrect)
			isCorrect = _other_part();
	}
	else if (str[pos] != '\0')
		isCorrect = false;
	return isCorrect;
}
