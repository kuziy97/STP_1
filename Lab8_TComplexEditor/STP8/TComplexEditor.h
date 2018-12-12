#pragma once

#include <string>

using namespace std;

class TComplexEditor {
public:
	TComplexEditor();

	bool isZero();

	string changeSign();

	string addDigit(int digit);

	string addZero();

	string backspace();

	string clear();

	string addSplit();

	void set(string comp);

	int validation(string comp);

	string get() const;

	static const string ZERO;
	static const string DIV_SIGN;
private:
	string num;
	bool isRealPartEditing;
};