#include "../STP8/TComplexEditor.h"
#include "TComplexEditor.h"
#include "tcomplex.h"

const std::string TComplexEditor::ZERO = "0+i*0";
const std::string TComplexEditor::DIV_SIGN = "+i*";

TComplexEditor::TComplexEditor() : number("0"), isRealPartEditing(true) {
}


bool TComplexEditor::isZero() {
	return TComplex(number).getComplexStr() == TComplex(0, 0).getComplexStr();
}


std::string TComplexEditor::changeSign() {
	if (isRealPartEditing) {
		if (number[0] == '-') {
			number.erase(number.begin());
		}
		else {
			if (number[0] != '0') {
				number = "-" + number;
			}
		}
	}
	else {
		auto pos = number.find("i*");
		number[pos - 1] = (number[pos - 1] == '-') ? '+' : '-';
	}
	return number;
}


std::string TComplexEditor::addDigit(unsigned int digit) {
	auto pos = isRealPartEditing ? 0 : number.find('*') + 1;
	if (digit >= 0 && digit < 10) {
		if (number[pos] == '0') {
			number.pop_back();
		}
		number += (char)('0' + digit);
	}
	return number;
}


std::string TComplexEditor::addZero() {
	return addDigit(0);
}


std::string TComplexEditor::backspace() {
	number.pop_back();
	if (isRealPartEditing) {
		if (number == "-" || number.empty()) {
			number = "0";
		}
	}
	else {
		if (number.find('*')) {
			number.erase(number.end() - 2, number.end());
			isRealPartEditing = true;
		}
	}
	return number;
}


std::string TComplexEditor::clear() {
	number = "0";
	isRealPartEditing = true;
	return number;
}

std::string TComplexEditor::addSplit() {
	if (number.find(DIV_SIGN) == std::string::npos) {
		number = number + DIV_SIGN;
		isRealPartEditing = false;
	}
	return number;
}


void TComplexEditor::setNumber(std::string &num) {
	bool flag = true;
	uint32_t minus_c = 0, plus_c = 0;
	for (auto &i : num) {
		if ((i >= 48 && i <= 57) || i == 43 || i == 45) {
			if (i == 43) {
				minus_c++;
				if (minus_c > 2) {
					flag = false;
					break;
				}
			}
			else {
				if (i == 45) {
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
		number = TComplex(num).getComplexStr();
	else
		number = TComplex("0").getComplexStr();
}


std::string TComplexEditor::getNumber() const {
	return TComplex(number).getComplexStr();
}