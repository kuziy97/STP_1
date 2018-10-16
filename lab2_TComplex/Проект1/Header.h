#pragma once
#include <sstream>
#include <string>
using namespace std;
class TComplex
{
private:
	float a, b;
public:
	TComplex(float, float);
	TComplex(std::string);
	TComplex Copy();
	TComplex Summ(TComplex d);
	TComplex Multiply(TComplex d);
	TComplex Square();
	TComplex Reverse();
	TComplex Subtract(TComplex d);
	TComplex Del(TComplex d);
	TComplex Minus();
	float Module();
	float AngleRad();
	float AngleGrad();
	TComplex Degree(int n);
	TComplex Root(int n, int i);
	int fromStoINT(std::string);
	bool Equality(TComplex d);
	bool NoEquality(TComplex d);
	float GetRe();
	float GetIm();
	string GetReSTR();
	string GetImSTR();
	string GetTComplexSTR();
	TComplex operator + (TComplex);
	TComplex operator - (TComplex);
	TComplex operator * (TComplex);
	TComplex operator / (TComplex);
	//static TComplex operator-(TComplex first);
};


