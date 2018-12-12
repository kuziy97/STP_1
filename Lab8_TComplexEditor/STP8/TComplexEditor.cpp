#include "../STP8/TComplexEditor.h"
#include "TComplexEditor.h"
#include "tcomplex.h"

using namespace std;

const string TComplexEditor::ZERO = "0+i*0";
const string TComplexEditor::DIV_SIGN = "+i*";

TComplexEditor::TComplexEditor() : num("0"), isRealPartEditing(true) {
}


bool TComplexEditor::isZero() {
	return TComplex(num).getComplexStr() == TComplex(0, 0).getComplexStr();
}


string TComplexEditor::changeSign() {
	if (isRealPartEditing) {
		if (num[0] == '-') {
			num.erase(num.begin());
		}
		else {
			if (num[0] != '0') {
				num = "-" + num;
			}
		}
	}
	else {
		int pos = num.find("i*");
		num[pos - 1] = (num[pos - 1] == '-') ? '+' : '-';
	}
	return num;
}


string TComplexEditor::addDigit(int digit) {
	int pos = isRealPartEditing ? 0 : num.find('*') + 1;
	if (digit >= 0 && digit < 10) {
		if (num[pos] == '0') {
			num.pop_back();
		}
		num += (char)('0' + digit);
	}
	return num;
}


string TComplexEditor::addZero() {
	return addDigit(0);
}


string TComplexEditor::backspace() {
	num.pop_back();
	if (isRealPartEditing) {
		if (num == "-" || num.empty()) {
			num = "0";
		}
	}
	else {
		if (num.find('*')) {
			num.erase(num.end() - 2, num.end());
			isRealPartEditing = true;
		}
	}
	return num;
}


string TComplexEditor::clear() {
	num = "0";
	isRealPartEditing = true;
	return num;
}

string TComplexEditor::addSplit() {
	if (num.find(DIV_SIGN) == string::npos) {
		num = num + DIV_SIGN;
		isRealPartEditing = false;
	}
	return num;
}


int TComplexEditor::validation(string comp) {
	bool isValid = false;
	if (!comp.empty()) {
		int position = comp.find('i');

		string tempReal = comp;
		string tempImag = comp;
		int digitsCounterR = 0;
		int digitsCounterM = 0;
		
		string realPart;
		string imagPart = "";
		if (position != string::npos) {
			realPart = tempReal.erase(position - 1, comp.length());
			string imagPart = tempImag.erase(0, position + 2);
			for (char i : imagPart) {
				if (isdigit(i)) digitsCounterM++;
			}
		}
		else
		{
			realPart = comp;
		}

		for (char i : realPart) {
			if (isdigit(i)) digitsCounterR++;
		}

		if (digitsCounterR != 0) {
			if (realPart[0] == '-') {
				if (digitsCounterR == realPart.length() - 1) isValid = true;
			}
			else {
				if (digitsCounterR == realPart.length()) isValid = true;
			}
			if (digitsCounterM != 0) {
				if (imagPart[0] == '-') {
					if (digitsCounterM == imagPart.length() - 1) isValid = true;
				}
				else {
					if (digitsCounterM == imagPart.length()) isValid = true;
				}
			}
		}
	}
	return isValid;
}

void TComplexEditor::set(string comp) {
	if (validation(comp)) {
		num = comp;
	}
	else {
		cout << "\nНеверный формат ввода!";
	}
}


string TComplexEditor::get() const {
	return TComplex(num).getComplexStr();
}