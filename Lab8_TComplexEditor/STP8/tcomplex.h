#ifndef TCOMPLEX_H
#define TCOMPLEX_H
//#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.785398163397448309616
#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

class TComplex
{
private:
	double real;
	double imaginary;

public:
	explicit TComplex() : real(0), imaginary(0) {}

	TComplex(double real, double imaginary) : real(real), imaginary(imaginary)
	{}

	TComplex(std::string complexString)
	{
		try {
			size_t pos = complexString.find("+i*");
			int k = 1;
			if (pos == std::string::npos) {
				pos = complexString.find("-i*");
				k = -1;
			}
			if (pos == std::string::npos) {
				real = std::stod(complexString);
				imaginary = 0;
			}
			else {
				real = std::stod(complexString.substr(0, pos));
				imaginary = std::stod(complexString.substr(pos + 3)) * k;
			}
		}
		catch (...) {
			real = 0;
			imaginary = 0;
		}
	}
	~TComplex()
	{}

	TComplex copy(TComplex complex);
	TComplex summ(TComplex firstComplex, TComplex secondComplex);
	TComplex subtract(TComplex firstComplex, TComplex secondComplex);
	TComplex multi(TComplex firstComplex, TComplex secondComplex);
	TComplex divide(TComplex firstComplex, TComplex secondComplex);
	TComplex square(TComplex complex);
	TComplex reverse(TComplex complex);
	TComplex power(int index);
	TComplex root(int n, int k);
	double absolute(TComplex complex);
	double angleRadians(TComplex complex);
	double angleDegrees(TComplex complex);
	bool equal(TComplex complex);
	bool notEqual(TComplex complex);
	double getRealDouble();
	double getImaginaryDouble();
	std::string getRealStr();
	std::string getImaginaryStr();
	std::string getComplexStr();
	bool convertStringToComplex(std::string complexString);
};
#endif TCOMPLEX_H