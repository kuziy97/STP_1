#include "Header.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main()
{
	string s = "1-i*2";
	TComplex ai(s);
	TComplex aj(1, 2);
	TComplex c(0, 0);
	//c = ai + aj;
	//c = ai*aj;
	//c = ai - aj;
	//c = ai / aj;
	//ai.Minus();
	c=ai.Square();
	cout << ai.GetImSTR() << endl;
	cout << ai.GetTComplexSTR() << endl;
	cout << c.GetTComplexSTR()<<endl;

	
	//string s;
	//cin >> s;
	//TComplex ai(s);

	system("PAUSE");
}
