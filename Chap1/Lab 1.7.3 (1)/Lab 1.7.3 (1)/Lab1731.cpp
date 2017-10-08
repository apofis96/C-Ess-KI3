// Lab1731.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float a = 2.3, b = 2.3, c = 2.123456, d = 2.123456, f = 2.123456;
	cout << a <<endl;
	cout << fixed << setprecision(2) << b << endl;
	cout << setprecision(6) << c << endl;
	cout << setprecision(2) << d << endl;
	cout << setprecision(0) << f << endl;
    return 0;
}

