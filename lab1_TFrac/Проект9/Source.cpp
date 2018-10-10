#include "Header.h"

int main(int argc, char **argv) {
	Drobi a(-4, 7), b(1, 8);
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " in pow -1 = " << power(Drobi(-4, 7), -1) << endl;
	system("pause");
	return 0;
}