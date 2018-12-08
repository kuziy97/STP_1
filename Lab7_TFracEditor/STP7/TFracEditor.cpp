#include <iostream>
#include "TFracEditor.h"

const std::string TFracEditor::ZERO = "0/1";
const char TFracEditor::DIVIDER = '/';

TFracEditor::TFracEditor() : fraction(ZERO) {

}

int TFracEditor::gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

void TFracEditor::reduction() {
	unsigned int average = fraction.find('/');
	if (average != -1) {
		char buf1[30], buf2[30];
		size_t n1 = fraction.copy(buf1, average, 0);
		size_t n2 = fraction.copy(buf2, fraction.length() - average - 1, average + 1);
		buf1[n1] = '\0';
		buf2[n2] = '\0';
		int num = atoi(buf1);
		int den = atoi(buf2);

		int g = gcd(num, den);
		num /= g;
		den /= g;
		if (den < 0) {
			num *= -1;
			den *= -1;
		}
		fraction = std::to_string(num) + "/" + std::to_string(den);
	}
}

bool TFracEditor::isZeroFraction() {
	return fraction == ZERO;
}

std::string TFracEditor::changeSign() {
	if (fraction[0] == '-') {
		fraction.erase(fraction.begin());
	}
	else if (fraction != ZERO) {
		fraction = "-" + fraction;
	}
	return fraction;
}

std::string TFracEditor::addDigit(int digit) {
	if (fraction == ZERO) {
		fraction = "";
	}
	fraction += std::to_string(digit);
	reduction();
	return fraction;
}

std::string TFracEditor::addZero() {
	return addDigit(0);
}

std::string TFracEditor::removeLastDigit() {
	fraction.pop_back();
	if (fraction == "-" || fraction.empty()) {
		fraction = ZERO;
	}
	return fraction;
}

std::string TFracEditor::clear() {
	return fraction = ZERO;
}

std::string TFracEditor::addDivider() {
	if (fraction.find(DIVIDER) == std::string::npos) {
		fraction = fraction + DIVIDER;
	}
	return fraction;
}

void TFracEditor::editFraction(Operations operation) {
	switch (operation) {
	case CHANGE_SIGN:
		changeSign();
		break;
	case ADD_ZERO:
		addZero();
		break;
	case REMOVE_LAST_DIGIT:
		removeLastDigit();
		break;
	case CLEAR:
		clear();
		break;
	case ADD_DIVIDER:
		addDivider();
		break;
	default:
		break;
	}
}

bool TFracEditor::fractionValidation(std::string frac) {
	bool isValid = false;
	if (!frac.empty() && (frac.find('/') != std::string::npos)) {
		unsigned int position = frac.find('/');

		std::string firstPart = frac;
		std::string secondPart = frac;

		std::string numerator = firstPart.erase(position, frac.length());
		std::string denominator = secondPart.erase(0, position);

		int digitsCounter = 0;
		for (char i : numerator) {
			if (isdigit(i)) digitsCounter++;
		}

		for (char i : denominator) {
			if (isdigit(i)) digitsCounter++;
		}

		if (digitsCounter != 0) {
			if (frac[0] == '-') {
				if (digitsCounter == frac.length() - 2) isValid = true;
			}
			else {
				if (digitsCounter == frac.length() - 1) isValid = true;
			}
		}
	}
	return isValid;
}

void TFracEditor::setFraction(std::string frac) {
	if (fractionValidation(frac)) {
		fraction = frac;
	}
	else {
		std::cout << "\nНеверный формат ввода!";
	}
}

std::string TFracEditor::getFraction() {
	return fraction;
}