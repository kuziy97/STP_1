#include "TPNumber.h"

TPNumber::TPNumber(double number, int base, int precision) {
	if (base >= 2 && base <= 16 && precision >= 0) {
		_number = number;
		_base = base;
		_precision = precision;
	}
	else {
		_number = 0.0;
		_base = 10;
		_precision = 0;
	}
}

TPNumber::TPNumber(const std::string &number, const std::string &base, const std::string &precision) {
	try {
		_base = std::stoi(base);
		_precision = std::stoi(precision);

		if (_base >= 2 && _base <= 16 && _precision >= 0) {
			_number = strtod(number);
		}
		else {
			_number = 0.0;
			_base = 10;
			_precision = 0;
		}
	}
	catch (...) {
		_number = 0.0;
		_base = 10;
		_precision = 0;
	}
}

double TPNumber::getNumber() {
	return _number;
}

std::string TPNumber::getNumberAsString() {
	std::string num;

	int intPart = (int)_number;
	double fracPart = _number - intPart;

	do {
		char digit = (char)(intPart % _base);

		digit += digit < 10 ? '0' : -10 + 'A';

		num.insert(num.begin(), digit);

		intPart /= _base;
	} while (intPart);

	if (fracPart != 0) {
		num += '.';

		for (int exp = 1; exp <= _precision; ++exp) {
			char digit = (char)(fracPart *= _base);

			num += digit < 10 ? '0' + digit : 'A' + digit - 10;

			fracPart -= digit;
		}
	}

	return num;
}

std::string TPNumber::getNumberAsStringWithoutZero() {
	std::string res = getNumberAsString();
	while (res.back() == '0') {
		res.pop_back();
	}
	return res;
}

int TPNumber::getBase() {
	return _base;
}

std::string TPNumber::getBaseAsString() {
	return std::to_string(_base);
}

void TPNumber::setBase(int base) {
	if (base < 2 || base > 16) {
		throw std::invalid_argument("Wrong base");
	}
	_base = base;
}

void TPNumber::setBase(const std::string &base) {
	int new_base = std::stoi(base);

	if (new_base < 2 || new_base > 16) {
		throw std::invalid_argument("Wrong base");
	}

	_base = new_base;
}

int TPNumber::getPrecision() {
	return _precision;
}

std::string TPNumber::getPrecisionAsString() {
	return std::to_string(_precision);
}

void TPNumber::setPrecision(int precision) {
	if (precision < 0) {
		throw std::invalid_argument("Wrong precision");
	}

	_precision = precision;
}

void TPNumber::setPrecision(const std::string &precision) {
	int new_precision = std::stoi(precision);

	if (new_precision < 0) {
		throw std::invalid_argument("Wrong precision");
	}

	_precision = new_precision;
}

TPNumber TPNumber::copy() {
	return TPNumber(_number, _base, _precision);
}

TPNumber TPNumber::inv() {
	if (_number == 0) {
		throw std::invalid_argument("Division by zero!");
	}

	return TPNumber(1 / _number, _base, _precision);
}

TPNumber TPNumber::sqr() {
	return TPNumber(_number * _number, _base, _precision);
}

TPNumber TPNumber::operator+(const TPNumber &sec) {
	if (_base != sec._base || _precision != sec._precision) {
		throw std::invalid_argument("Illegal addition");
	}

	return TPNumber(_number + sec._number, _base, _precision);
}

TPNumber TPNumber::operator-(const TPNumber &sec) {
	if (_base != sec._base || _precision != sec._precision) {
		throw std::invalid_argument("Illegal subtraction");
	}

	return TPNumber(_number - sec._number, _base, _precision);
}

TPNumber TPNumber::operator*(const TPNumber &sec) {
	if (_base != sec._base || _precision != sec._precision) {
		throw std::invalid_argument("Illegal multiplication");
	}

	return TPNumber(_number * sec._number, _base, _precision);
}

TPNumber TPNumber::operator/(const TPNumber &sec) {
	if (_base != sec._base || _precision != sec._precision) {
		throw std::invalid_argument("Illegal division");
	}

	return TPNumber(_number / sec._number, _base, _precision);
}

double TPNumber::strtod(const std::string &num) {
	size_t pos = num.find('.');

	int intPart = std::stoi(num.substr(0, pos), nullptr, _base);
	int fracPart = pos != std::string::npos ? std::stoi(num.substr(pos + 1), nullptr, _base) : 0;

	double res = fracPart;
	while (res > 1) {
		res /= _base;
	}
	res += intPart;

	return res;
}