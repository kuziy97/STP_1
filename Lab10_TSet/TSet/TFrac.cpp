#include "TFrac.h"
#include <vector>
#include <cstdint>
#include <string>
#include <ostream>
#include <iostream>
#include <cstdlib>

using namespace std;

TFrac::TFrac() : num(0), den(1) {

}

TFrac::TFrac(int a, int b) : num(a), den(b) {
	reduction();
}

int TFrac::gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

void TFrac::reduction() {
	int g = gcd(num, den);
	num /= g;
	den /= g;
	if (den < 0) {
		num *= -1;
		den *= -1;
	}
}

TFrac::TFrac(string fraction) {
	int average = fraction.find('/');
	char buf1[30], buf2[30];
	size_t n1 = fraction.copy(buf1, average, 0);
	size_t n2 = fraction.copy(buf2, fraction.length() - average - 1, average + 1);
	buf1[n1] = '\0';
	buf2[n2] = '\0';
	num = atoi(buf1);
	den = atoi(buf2);
	reduction();
}

TFrac TFrac::copy() {
	return { num, den };
}

TFrac &TFrac::operator=(const TFrac &sec) = default;

TFrac TFrac::operator+(const TFrac &sec) {
	return TFrac(num * sec.den + den * sec.num,
		den * sec.den);
}

TFrac TFrac::operator-(const TFrac &sec) {
	return TFrac(num * sec.den - den * sec.num,
		den * sec.den);
}

TFrac TFrac::operator*(const TFrac &sec) {
	return TFrac(num * sec.num, den * sec.den);
}

TFrac TFrac::operator/(const TFrac &sec) {
	if (!sec.num) {
		throw std::invalid_argument("Denominator is zero!");
	}

	return TFrac(num * sec.den, den * sec.num);
}

TFrac TFrac::operator-() {
	return TFrac(-num, den);
}

bool TFrac::operator==(const TFrac &sec) {
	return num == sec.num && den == sec.den;
}

bool TFrac::operator>(const TFrac &sec) const {
	return num * sec.den > den * sec.num;
}

bool TFrac::operator<(const TFrac &sec) const {
	return num * sec.den < den * sec.num;
}

TFrac TFrac::square() {
	return { num * num, den * den };
}

TFrac TFrac::reverse() {
	return { den, num };
}

int TFrac::getNum() {
	return num;
}

int TFrac::getDen() {
	return den;
}

string TFrac::getNumStr() {
	return to_string(num);
}

string TFrac::getDenStr() {
	return to_string(den);
}

string TFrac::getFracStr() {
	return to_string(num) + "/" + to_string(den);
}