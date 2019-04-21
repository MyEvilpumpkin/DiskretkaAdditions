#pragma once
#include <string>
#include <algorithm>
#include "Recognizer.h"

class NRecognizer : public Recognizer {
	void RemoveChar(char ch) override { str.erase(remove(str.begin(), str.end(), ch), str.end()); }
	void Recognize() override { RemoveChar(' ');  status = _n(); if (str.length() == 1 && str[0] == '0') status = true; }
	bool _n();
	bool _num();
	bool _first_digit();
	bool _other_digit();
	bool _digit();
public:
	NRecognizer(std::string str) : Recognizer(str) { Recognize(); }
	void Update(std::string str) override { this->str = str; pos = 0; status = false; Recognize(); }
	bool GetStatus() override { return status; }
	std::string GetPreparedString() override { return str; }
};

