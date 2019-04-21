#pragma once
#include <string>

class Recognizer {
protected:
	std::string str;
	int pos;
	bool status;
	virtual void RemoveChar(char) = 0;
	virtual void Recognize() = 0;
public:
	Recognizer(std::string str) : str(str), pos(0), status(false) { }
	virtual void Update(std::string str) = 0;
	virtual bool GetStatus() = 0;
	virtual std::string GetPreparedString() = 0;
};

