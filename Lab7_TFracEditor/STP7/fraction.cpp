#include "fraction.h"

Fraction::Fraction(std::string FractionString) {
	std::size_t pos = FractionString.find("/");

	if (pos != std::string::npos) {
		this->numerator = atol(FractionString.substr(0, pos).c_str());
		this->denominator = atol(FractionString.substr(pos + 1).c_str());
	}
	else {
		this->numerator = atol(FractionString.c_str());
		this->denominator = 1;
	}
}

Fraction Fraction::operator = (const Fraction &firstFrac)
{
	if (&firstFrac == this)
		return *this;

	return Fraction(this->numerator = firstFrac.numerator, this->denominator = firstFrac.denominator);
}

int Fraction::getNum()
{
	return numerator;
}

int Fraction::getDen()
{
	return denominator;
}

void Fraction::setNum(int num)
{
	this->numerator = num;
}

void Fraction::setDen(int den)
{
	this->denominator = den;
}

int Fraction::gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void Fraction::reduction()
{
	//if (this->numerator == 0 || this->denominator == 0) return Fraction(0, 0);
	int temp = gcd(this->numerator, this->denominator);

	this->numerator /= temp;
	this->denominator /= temp;
}


Fraction Fraction::sum(Fraction firstFrac, Fraction secondFrac) {

	int denominatorT = firstFrac.denominator * secondFrac.denominator;
	int firstNumerator = firstFrac.numerator * secondFrac.denominator;
	int secondNumerator = secondFrac.numerator * firstFrac.denominator;

	if (firstFrac.numerator == 0) return Fraction(secondFrac.numerator, secondFrac.denominator);
	if (secondFrac.numerator == 0) return Fraction(firstFrac.numerator, firstFrac.denominator);
	if (!(firstNumerator + secondNumerator)) return Fraction(0, 0);
	//if (!denominatorT) return Fraction(0, 0);
	return Fraction(firstNumerator + secondNumerator, denominatorT);
}

Fraction Fraction::subtract(Fraction firstFrac, Fraction secondFrac) {
	int denominatorT = firstFrac.denominator * secondFrac.denominator;
	int firstNumerator = firstFrac.numerator * secondFrac.denominator;
	int secondNumerator = secondFrac.numerator * firstFrac.denominator;

	if (firstFrac.numerator == 0) return Fraction(secondFrac.numerator, secondFrac.denominator);
	if (secondFrac.numerator == 0) return Fraction(firstFrac.numerator, firstFrac.denominator);

	if ((firstNumerator - secondNumerator) == 0) return Fraction(0, 0);
	//if (!denominatorT) return Fraction(0, 0);

	return Fraction(firstNumerator - secondNumerator, denominatorT);
}

Fraction Fraction::multi(Fraction firstFrac, Fraction secondFrac) {
	int denominatorT = firstFrac.denominator * secondFrac.denominator;
	int numeratorT = firstFrac.numerator * secondFrac.numerator;

	if (!numeratorT || !denominatorT) return Fraction(0, 0);

	return Fraction(numeratorT, denominatorT);
}

Fraction Fraction::divide(Fraction firstFrac, Fraction secondFrac)
{
	int denominatorT = firstFrac.denominator * secondFrac.numerator;
	int numeratorT = firstFrac.numerator * secondFrac.denominator;

	if (!numeratorT || !denominatorT) return Fraction(0, 0);

	return Fraction(numeratorT, denominatorT);
}

Fraction Fraction::copy(Fraction firstFrac) {
	return Fraction(firstFrac.numerator, firstFrac.denominator);
}

void Fraction::reroll() {
	int tmp;
	tmp = this->numerator;
	this->setNum(this->denominator);
	this->setDen(tmp);
}

Fraction Fraction::square(Fraction firstFrac) {
	return Fraction(firstFrac.numerator*firstFrac.numerator, firstFrac.denominator*firstFrac.denominator);
}

void Fraction::unary() {
	this->numerator *= -1;
}

std::string Fraction::getNumString() {
	char tmp[10];
	_itoa_s(this->numerator, tmp, 10);
	std::string str = tmp;
	return str;
}
std::string Fraction::getFracString() {
	char tmp[10];
	_itoa_s(this->numerator, tmp, 10);
	std::string str = tmp;
	str += '/';
	_itoa_s(this->denominator, tmp, 10);
	str += tmp;
	return str;
}
std::string Fraction::getDenString() {
	char tmp[10];
	_itoa_s(this->denominator, tmp, 10);
	std::string str = tmp;
	return str;
	//return ("" + this->denominator);
}