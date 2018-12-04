#include "../STP6/TPNumberEditor.h"
#include "TPNumberEditor.h"
#include "TPNumber.h"

const std::string TPNumberEditor::ZERO = "0";
const char TPNumberEditor::DIV_SIGN = '.';

TPNumberEditor::TPNumberEditor() : number(TPNumberEditor::ZERO), base(10) {
}


bool TPNumberEditor::isZero() {
	return TPNumber(number, std::to_string(base)).getNumber() == 0.0;
}


std::string TPNumberEditor::changeSign() {
	if (number[0] == '-') {
		number.erase(number.begin());
	}
	else {
		if (number != TPNumberEditor::ZERO) {
			number = "-" + number;
		}
	}
	return number;
}


std::string TPNumberEditor::addDigit(unsigned int digit) {
	if (digit < base) {
		if (number == TPNumberEditor::ZERO) {
			number = "";
		}
		number += (char)(digit < 10 ? '0' + digit : 'A' + digit - 10);
	}
	return number;
}


std::string TPNumberEditor::addZero() {
	return addDigit(0);
}


std::string TPNumberEditor::backspace() {
	number.pop_back();
	if (number == "-" || number.empty()) {
		number = TPNumberEditor::ZERO;
	}
	return number;
}


std::string TPNumberEditor::clear() {
	number = TPNumberEditor::ZERO;
	return number;
}

std::string TPNumberEditor::addSplit() {
	if (number.find(DIV_SIGN) == std::string::npos) {
		number = number + DIV_SIGN;
	}
	return number;
}


void TPNumberEditor::setNumber(std::string &num) {
	bool flag = true;
	uint32_t minus_c = 0, plus_c = 0;
	for (auto &i : num) {
		if ((i >= '0' && i < '9') || i == '+' || i == '-' || i == '.' || (i >= 'A' && i <= 'F')) {
			if (i == '+') {
				if (i != 0) {
					flag = false;
					break;
				}
			}
			else {
				if (i == '-') {
					if (i != 0) {
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
	if (!flag)
		num = "0";
	number = TPNumber(num, std::to_string(base)).getNumberAsString();
}


std::string TPNumberEditor::getNumber() const {
	return TPNumber(number, std::to_string(base)).getNumberAsString();
}


int TPNumberEditor::GetBaseAsInt()
{
	int temp = this->base;
	return temp;
}

void TPNumberEditor::SetBase(int new_base)
{
	if ((new_base >= 2) && (new_base <= 16)) this->base = new_base;
}

std::string TPNumberEditor::GetBaseAsStr()
{
	std::string temp = std::to_string(this->base);
	return temp;
}