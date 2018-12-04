#ifndef FRACTION_H
#define FRACTION_H
//#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <iostream>
#include <cstdlib>
#include <string>


class Fraction
{

private:
	int numerator;
	int denominator;

public:
	Fraction()
	{
		numerator = 0;
		denominator = 0;
	}
	Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
	{}
	Fraction(std::string FractionString);

	~Fraction()
	{}
	int getNum();
	int getDen();
	std::string getNumString();
	std::string getFracString();
	std::string getDenString();
	void setNum(int num);
	void setDen(int den);
	void unary();
	int gcd(int a, int b);
	void reduction();
	Fraction operator = (const Fraction &firstFrac);

	Fraction sum(Fraction, Fraction);
	Fraction multi(Fraction, Fraction);
	Fraction divide(Fraction, Fraction);
	Fraction subtract(Fraction, Fraction);
	Fraction square(Fraction);
	void reroll();
	Fraction copy(Fraction);

	bool operator< (const Fraction & anotherFrac) const {
		if (float(this->numerator) / float(this->denominator)
			< float(anotherFrac.numerator) / float(anotherFrac.denominator))
			return true;
		else
			return false;
	}
};

#endif FRACTION_H#pragma once
