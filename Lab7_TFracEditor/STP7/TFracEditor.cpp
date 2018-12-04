#include "TFracEditor.h"
#include "fraction.h"

const std::string TFracEditor::ZERO = "0/1";
const char TFracEditor::DIV_SIGN = '/';

TFracEditor::TFracEditor() : number("0") {
}


bool TFracEditor::isZero() {
	return Fraction(number).getFracString() == TFracEditor::ZERO;
}


std::string TFracEditor::changeSign() {
	if (number[0] == '-') {
		number.erase(number.begin());
	}
	else {
		if (!isZero()) {
			number = "-" + number;
		}
	}
	return number;
}


std::string TFracEditor::addDigit(unsigned int digit) {
	if (digit >= 0 && digit < 10) {
		if (number == "0") {
			number = "";
		}
		number += (char)('0' + digit);
	}
	return number;
}


std::string TFracEditor::addZero() {
	return number.back() != DIV_SIGN ? addDigit(0) : number;
}


std::string TFracEditor::backspace() {
	number.pop_back();
	if (number == "-" || number.empty()) {
		number = "0";
	}
	return number;
}


std::string TFracEditor::clear() {
	number = "0";
	return number;
}

std::string TFracEditor::addSplit() {
	if (number.find(DIV_SIGN) == std::string::npos) {
		number = number + DIV_SIGN;
	}
	return number;
}


void TFracEditor::setNumber(std::string &num) {
	bool flag = true;
	uint32_t minus_c = 0, plus_c = 0;
	for (auto &i : num) {
		if ((i >= '0' && i <= '9') || i == '+' || i == '-' || i == '/') {
			if (i == '+') {
				minus_c++;
				if (minus_c > 2) {
					flag = false;
					break;
				}
			}
			else {
				if (i == '-') {
					plus_c++;
					if (plus_c > 2) {
						flag = false;
						break;
					}
				}
			}
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag)
		number = Fraction(num).getFracString();
	else
		number = Fraction("0").getFracString();

}


std::string TFracEditor::getNumber() const {
	return Fraction(number).getFracString();
}