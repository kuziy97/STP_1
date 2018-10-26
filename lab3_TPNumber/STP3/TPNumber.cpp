#include "TPNumber.h"
#include "stdafx.h" 



TPNumber::TPNumber(float a, unsigned char b, unsigned char c)
{
	if (b<2 || b>16 || c<0)
		throw 1;


	this->a = a;
	this->b = b;
	this->c = c;
}

TPNumber::TPNumber(string a, unsigned char b, unsigned char c)
{
	if (b<2 || b>16 || c<0)
		throw 1;

	bool sign = (a[0] == '-');

	if (sign)
		a.erase(0, 1);

	string integer, frac;

	if (a.find('.', 0) != string::npos) {
		integer = a.substr(0, a.find('.', 0));
		frac = a.substr(a.find('.', 0) + 1, a.size());
	}
	else {
		integer = a;
		frac[0] = 0;
	}

	this->a = 0;

	for (int i = 0; i<integer.size(); i++) {
		if (!((integer[i] >= '0' && integer[i] <= '9') || (tolower(integer[i]) >= 'a') && (tolower(integer[i]) <= 'z')) || (CharToInt(integer[i]) >= b))
			throw 1;
		this->a += CharToInt(integer[i])*Power(b, integer.size() - i - 1);
	}

	for (int i = 0; i<frac.size(); i++) {
		if (!((frac[i] >= '0'&&frac[i] <= '9') || (tolower(frac[i]) >= 'a') && (tolower(frac[i]) <= 'z')) || (CharToInt(frac[i]) >= b))
			throw 1;
		this->a += CharToInt(frac[i])*Power(b, -(i + 1));
	}

	if (sign)
		this->a = -this->a;
	this->b = b;
	this->c = c;
}

TPNumber TPNumber::Copy()
{
	return *this;
}

TPNumber TPNumber::operator +(TPNumber num)
{
	if (c != num.c || b != num.b)
		throw 1;
	else
		return TPNumber(a + num.a, b, c);
}

TPNumber TPNumber::operator -(TPNumber num)
{
	if (c != num.c || b != num.b)
		throw 1;
	else
		return TPNumber(a - num.a, b, c);
}

TPNumber TPNumber::operator *(TPNumber num)
{
	if (c != num.c || b != num.b)
		throw 1;
	else
		return TPNumber(a*num.a, b, c);
}

TPNumber TPNumber::operator /(TPNumber num)
{
	if (!num.a)
		throw 1;
	if (c != num.c || b != num.b)
		throw 1;
	else
		return TPNumber(a / num.a, b, c);
}

TPNumber TPNumber::Reverse()
{
	if (!a)
		throw 1;
	return TPNumber(1 / a, b, c);
}

TPNumber TPNumber::Sqr()
{
	return TPNumber(a*a, b, c);
}

string TPNumber::GetPString()
{
	std::stringstream ss;

	string part1 = "", part2 = "";

	bool sign = (a<0);
	int integer;
	float frac;
	integer = (int)fabs(a);
	frac = fabs(a) - integer;


	while (integer) {
		part1.insert(0, 1, IntToChar(integer%b));
		integer /= b;
	}

	for (int i = 0; i<c; i++) {
		float tmp = Power(b, -(i + 1));
		int n = 0;
		while (tmp*(n + 1) <= frac) {
			n++;
		}
		frac -= tmp*(n);
		part2 += IntToChar(n);

	}

	if (part1 == "")
		part1 += '0';

	if (sign)
		part1.insert(0, 1, '-');

	return part1 + "." + part2;
}

string TPNumber::GetBaseString()
{
	int num = b;
	string result = "";

	while (num) {
		result.insert(0, 1, IntToChar(num % 10));
		num /= 10;
	}

	return result;
}

string TPNumber::GetExString()
{
	int num = c;
	string result = "";

	while (num) {
		result.insert(0, 1, IntToChar(num % 10));
		num /= 10;
	}

	return result;
}

void TPNumber::SetBaseString(string bs)
{
	int num = 0;
	for (int i = 0; i<bs.size(); i++)
		num += CharToInt(bs[i])*Power(10, bs.size() - i - 1);

	if (num<2 || num>10)
		throw 1;

	b = num;
}

void TPNumber::SetExString(string newc)
{
	int num = 0;
	for (int i = 0; i<newc.size(); i++)
		num += CharToInt(newc[i])*Power(10, newc.size() - i - 1);

	if (c<0)
		throw 1;

	c = num;
}

int TPNumber::CharToInt(char c)
{
	c = tolower(c);
	if (c >= '0'&&c <= '9')
		return c - '0';
	else if (c >= 'a'&&c <= 'f')
		return c - 'a' + 10;
	else return -1;
}

char TPNumber::IntToChar(int num)
{
	if (num >= 0 && num <= 9)
		return num + '0';
	if (num >= 10 && num <= 15)
		return 'A' + num - 10;
	else
		return 0;
}

float TPNumber::Power(int num, int pow)
{
	float result;
	if (pow == 0)
		return 1;

	else if (pow>0) {
		result = 1;
		for (int i = 0; i<pow; i++)
			result *= num;
	}
	else if (pow<0) {
		result = 1;
		for (int i = 0; i < -pow; i++)
			result /= (float)num;
	}

	return result;
}