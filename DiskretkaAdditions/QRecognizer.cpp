#include "QRecognizer.h"

bool QRecognizer::_q() {
	bool isCorrect = true;
	if (str[pos] == '+' || str[pos] == '-')
		pos++;
	isCorrect = _coef();
	if (str[pos] != '\0')
		isCorrect = false;
	return isCorrect;
}

bool QRecognizer::_coef() {
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
		}
		else
			isCorrect = false;
	}
	return isCorrect;
}

bool QRecognizer::_num() {
	bool isCorrect = true;
	if (_first_digit())
		isCorrect = _other_digit();
	else
		isCorrect = false;
	return isCorrect;
}

bool QRecognizer::_first_digit() {
	bool isCorrect = true;
	if (str[pos] >= '1' && str[pos] <= '9')
		pos++;
	else
		isCorrect = false;
	return isCorrect;
}

bool QRecognizer::_other_digit() {
	bool isCorrect = true;
	if (_digit())
		_other_digit();
	return isCorrect;
}

bool QRecognizer::_digit() {
	bool isCorrect = true;
	if (str[pos] >= '0' && str[pos] <= '9')
		pos++;
	else
		isCorrect = false;
	return isCorrect;
}

