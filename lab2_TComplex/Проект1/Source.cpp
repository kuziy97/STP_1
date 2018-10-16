#include <iostream>
#include "Header.h"
#include <math.h>
#include <sstream>
#include <string>
#include <iomanip>
#define M_PI       3.14159265358979323846
using namespace std;

TComplex::TComplex(float im, float re)
{
	a = im;
	b = re;
}
TComplex::TComplex(string str)
{

	size_t p = str.find("i"), t = str.find("*");

	this->a = stof(str.substr(0, p - 1));
	this->b = stof(str.substr(t + 1));
	//cout << a << endl;
	if (str.at(p - 1) == '-') this->b *= -1;
}
int TComplex::fromStoINT(string str) {
	long long c = 0; int n = str.size();
	for (int i = 0; i < n; i++) {
		c += (str.at(n - i - 1) - '0') * pow(10, i);
	}
	return c;
}
TComplex TComplex::Copy()//копировать
{
	TComplex copy(a, b);
	return copy;
}
TComplex TComplex::Summ(TComplex d)//сложить
{
	TComplex summ((a + d.a), (b + d.b));
	return summ;
}
TComplex TComplex::Multiply(TComplex d)//умножить
{
	TComplex multiply(((a*d.a) - (b*d.b)), ((a*d.b) + (b*d.a)));
	return multiply;
}
TComplex TComplex::Square()//квадрат
{
	TComplex square(((a*a) - (b*b)), ((a*b) + (a*b)));
	return square;
}
TComplex TComplex::Reverse()//обратное
{
	return TComplex((a / (a*a + b*b)), ((-b / (a*a + b*b))));
}
TComplex TComplex::Subtract(TComplex d)//вычесть
{
	TComplex subtract((a - d.a), (b - d.b));
	return subtract;
}
TComplex TComplex::Del(TComplex d)//делить
{
	TComplex del(((a*d.a + b*d.b) / (d.a*d.a + d.b*d.b)), ((d.a*b - d.b*a) / (d.a*d.a + d.b*d.b)));
	return del;
}
TComplex TComplex::Minus()
{
	a = -a;
	b = -b;
	TComplex minus(a, b);
	return minus;
}
float TComplex::Module()
{
	return sqrt(a*a + b*b);
}
float TComplex::AngleRad()
{
	if (a == 0 && b < 0) return -M_PI / 2;
	if (a == 0 && b > 0) return M_PI / 2;
	if (a == 0 && b == 0) return 0;
	if (a > 0) return atan2(b, a);
	else
		return atan2(b, a) + M_PI;
}
float TComplex::AngleGrad()
{
	return (AngleGrad() * 180) / M_PI;
}
TComplex TComplex::Degree(int n)
{
	return TComplex((pow(Module(), n)*cos(n*AngleRad())), (pow(Module(), n)*sin(n*AngleRad())));
}
TComplex TComplex::Root(int n, int i)
{
	int k = i - 1;
	return TComplex((pow(Module(), 1 / n)*cos((AngleRad() + 2 * k*M_PI) / n)), (sin((AngleRad() + 2 * k*M_PI) / n)));
}
bool TComplex::Equality(TComplex d)
{
	if (a == d.a && b == d.b)return true;
	else return false;
}
bool TComplex::NoEquality(TComplex d)
{
	if (a != d.a || b != d.b) return true;
	else return false;
}
float TComplex::GetRe()
{
	return a;
}
float TComplex::GetIm()
{
	return b;
}
string TComplex::GetReSTR()
{
	//return 0;

	/*stringstream stream;
	stream << fixed << setprecision(2) << a;
	string s = stream.str();
	return s;*/
	return to_string(a);
}
string TComplex::GetImSTR()
{
	return to_string(b);
}
string TComplex::GetTComplexSTR()
{
	string aa = to_string(a);
	string bb = to_string(b);
	aa.erase(aa.find_last_not_of('0') + 1, std::string::npos);
	aa.erase(aa.find_last_not_of('.') + 1, std::string::npos);
	bb.erase(bb.find_last_not_of('0') + 1, std::string::npos);
	bb.erase(bb.find_last_not_of('.') + 1, std::string::npos);
	if (b >= 0)
		return aa + "+" + bb + "*i";
	else return aa + bb + "*i";
}
TComplex TComplex::operator + (TComplex d)
{
	return Summ(d);
}
TComplex TComplex::operator - (TComplex d)
{
	return Subtract(d);
}
TComplex TComplex::operator * (TComplex d)
{
	return Multiply(d);
}
TComplex TComplex::operator / (TComplex d)
{
	return Del(d);
}

//static TComplex operator-(TComplex first)
//{
//	return first.Minus();
//}