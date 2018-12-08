#pragma once

#include <string>

enum Operations {
	CHANGE_SIGN,
	ADD_ZERO,
	REMOVE_LAST_DIGIT,
	CLEAR,
	ADD_DIVIDER
};

class TFracEditor {
private:
	std::string fraction;

	int gcd(int a, int b);

	void reduction();

	bool fractionValidation(std::string frac);

public:
	static const char DIVIDER;
	static const std::string ZERO;

	TFracEditor();

	bool isZeroFraction();

	std::string changeSign();

	std::string addDigit(int digit);

	std::string addZero();

	std::string removeLastDigit();

	std::string clear();

	std::string addDivider();

	void editFraction(Operations operation);

	void setFraction(std::string frac);

	std::string getFraction();
};
