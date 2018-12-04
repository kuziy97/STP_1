#include "tcomplex.h"
#include <cmath>
//#define _USE_MATH_DEFINES


TComplex TComplex::copy(TComplex complex)
{
	return TComplex(complex.real, complex.imaginary);
}

TComplex TComplex::summ(TComplex firstComplex, TComplex secondComplex)
{
	return TComplex(firstComplex.real + secondComplex.real,
		firstComplex.imaginary + secondComplex.imaginary);
}

TComplex TComplex::multi(TComplex firstComplex, TComplex secondComplex)
{
	return TComplex(firstComplex.real * secondComplex.real -
		firstComplex.imaginary * secondComplex.imaginary,
		firstComplex.real * secondComplex.imaginary +
		secondComplex.real * firstComplex.imaginary);
}

TComplex TComplex::subtract(TComplex firstComplex, TComplex secondComplex)
{
	return TComplex(firstComplex.real - secondComplex.real,
		firstComplex.imaginary - secondComplex.imaginary);
}

TComplex TComplex::divide(TComplex firstComplex, TComplex secondComplex)
{
	double real = (double)(firstComplex.real*secondComplex.real + firstComplex.imaginary*secondComplex.imaginary)
		/ (secondComplex.real*secondComplex.real + secondComplex.imaginary*secondComplex.imaginary);
	double image = (double)(secondComplex.real*firstComplex.imaginary - firstComplex.real*secondComplex.imaginary)
		/ (secondComplex.real*secondComplex.real + secondComplex.imaginary*secondComplex.imaginary);


	return TComplex(real, image);
}

TComplex TComplex::reverse(TComplex complex)
{
	return TComplex((complex.real)
		/ (complex.real * complex.real +
			complex.imaginary * complex.imaginary),
		(complex.imaginary)
		/ (complex.real * complex.real +
			complex.imaginary * complex.imaginary));

}

TComplex TComplex::square(TComplex complex)
{
	return TComplex(complex.real * complex.real -
		complex.imaginary * complex.imaginary,
		complex.real * complex.imaginary +
		complex.real * complex.imaginary);
}

double TComplex::absolute(TComplex complex)
{
	double result = std::sqrt(complex.real *complex.real
		+ complex.imaginary * complex.imaginary);
	return result;
}

double TComplex::angleRadians(TComplex complex)
{
	if (complex.real > 0)
	{
		if (complex.imaginary >= 0)
			return std::atan(complex.imaginary / complex.real);
		else if (complex.imaginary < 0)
			return 2 * M_PI - std::atan(complex.imaginary / complex.real);
	}
	else if (complex.real < 0)
	{
		if (complex.imaginary >= 0)
			return M_PI - std::atan(complex.imaginary / complex.real);
		else if (complex.imaginary < 0)
			return M_PI + std::atan(complex.imaginary / complex.real);
	}
	else if (complex.real == 0)
	{
		if (complex.imaginary >= 0)
			return M_PI_2;
		else if (complex.imaginary < 0)
			return 3 * M_PI_2;
	}
}

double TComplex::angleDegrees(TComplex complex)
{
	if (complex.real > 0)
	{
		if (complex.imaginary >= 0)
			return 180 / M_PI * std::atan(complex.imaginary / complex.real);
		else if (complex.imaginary < 0)
			return  180 * M_PI - std::atan(complex.imaginary / complex.real);
	}
	else if (complex.real < 0)
	{
		if (complex.imaginary >= 0)
			return 180 - std::atan(complex.imaginary / complex.real);
		else if (complex.imaginary < 0)
			return 180 + std::atan(complex.imaginary / complex.real);
	}
	else if (complex.real == 0)
	{
		if (complex.imaginary >= 0)
			return 90;
		else if (complex.imaginary < 0)
			return 270;
	}
}

TComplex TComplex::power(int index)
{
	double fi = angleRadians(*this);
	return   TComplex::multi(TComplex((std::pow(absolute(*this), index), 0), 0),
		TComplex(std::cos(index * fi), std::sin(index * fi)));
}

TComplex TComplex::root(int n, int k)
{
	std::vector<TComplex> answers;
	double fi = angleRadians(*this);
	for (int i = 0; i < n; ++i)
	{
		answers.push_back(TComplex::multi(TComplex(std::pow(absolute(*this), 1.0 / n), 0),
			TComplex(std::cos((fi + 2 * i*M_PI) / n), std::sin((fi + 2 * i*M_PI) / n))));
	}

	return answers[k];
}

bool TComplex::equal(TComplex complex)
{
	if ((this->real == complex.real) && (this->imaginary == complex.imaginary))
		return 1;
	else return 0;
}

bool TComplex::notEqual(TComplex complex)
{
	if ((this->real == complex.real) && (this->imaginary == complex.imaginary))
		return 0;
	else return 1;
}

double TComplex::getRealDouble()
{
	return real;
}

double TComplex::getImaginaryDouble()
{
	return imaginary;
}

std::string TComplex::getRealStr()
{
	return std::to_string(real);
}

std::string TComplex::getImaginaryStr()
{
	return std::to_string(imaginary);
}

std::string TComplex::getComplexStr()
{
	std::string realTempString = std::to_string(real);
	realTempString += " + i*";
	std::string imaginaryTempString = std::to_string(imaginary);
	realTempString += imaginaryTempString;
	return realTempString;

}

bool TComplex::convertStringToComplex(std::string complexString)
{
	std::size_t pos = complexString.find("+i*") + 2;

	if (pos != std::string::npos) {
		try {
			this->real = atol(complexString.substr(0, pos).c_str());
			this->imaginary = atol(complexString.substr(pos + 1).c_str());
		}
		catch (...) {
			return false;
		}

		return (this->imaginary == 0) ? false : true;
	}

	return false;
}