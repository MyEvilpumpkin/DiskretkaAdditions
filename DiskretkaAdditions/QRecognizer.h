#pragma once
#include <string>
#include <algorithm>


class QRecognizer {
	std::string str;
	int pos;
	bool status;
	void RemoveChar(char ch) { str.erase(remove(str.begin(), str.end(), ch), str.end()); }
	void Recognize() { RemoveChar(' ');  status = _q(); if (str.length() == 1 && str[0] == '0') status = true; }
	bool _q();
	bool _coef();
	bool _num();
	bool _first_digit();
	bool _other_digit();
	bool _digit();
public:
	QRecognizer(std::string str) : str(str), pos(0), status(false) { Recognize(); }
	void Update(std::string str) { this->str = str; pos = 0; status = false; Recognize(); }
	bool GetStatus() { return status; }
	std::string GetPreparedString() { RemoveChar('('); RemoveChar(')'); if (str[0] != '-' && str[0] != '+') str = '+' + str; return str; }
};
