#pragma once
#include <cstdint>
#include <string>
#include <ostream>

using namespace std;

class TFrac {

private:
	int num;
	int den;
	void reduction();

public:
	TFrac();
	TFrac(int a, int b);
	TFrac(string fraction);

	TFrac& operator=(const TFrac &sec);

	TFrac operator+(const TFrac &sec);

	TFrac operator-(const TFrac &sec);

	TFrac operator*(const TFrac &sec);

	TFrac operator/(const TFrac &sec);

	TFrac operator-();

	bool operator>(const TFrac &sec) const;

	bool operator<(const TFrac &sec) const;

	bool operator==(const TFrac &sec);

	int gcd(int a, int b);
	TFrac copy();
	TFrac square();
	TFrac reverse();

	int getNum();
	int getDen();
	string getNumStr();
	string getDenStr();
	string getFracStr();
};