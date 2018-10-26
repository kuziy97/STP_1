#pragma once
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
class TPNumber
{
public:
	TPNumber(float a, unsigned char b, unsigned char c);
	TPNumber(string a, unsigned char b, unsigned char c);
	TPNumber Copy();
	TPNumber operator+(TPNumber num);
	TPNumber operator-(TPNumber num);
	TPNumber operator*(TPNumber num);
	TPNumber operator/(TPNumber num);
	TPNumber Reverse();
	TPNumber Sqr();

	string GetPString();
	string GetBaseString();
	string GetExString();

	void SetBaseString(string bs);
	void SetExString(string newc);

	float GetFloatPNumber()
	{
		return a;
	}
	int GetIntBase()
	{
		return b;
	}
	int GetIntEx()
	{
		return c;
	}
	void SetIntBase(int b) {
		if (b<2 || b>16)
			throw 1;
		this->b = b;
	}
	void SetIntEx(int c) {
		if (c<0)
			throw 1;
		this->c = c;
	}


private:
	static int CharToInt(char c);
	static char IntToChar(int num);
	static float Power(int num, int pow);
	float a;
	unsigned char b;
	unsigned char c;

};
