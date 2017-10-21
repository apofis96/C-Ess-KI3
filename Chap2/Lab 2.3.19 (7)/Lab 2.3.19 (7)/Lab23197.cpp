// Lab23197.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n; unsigned long long a = 1, b = 1, c = 1;
	cout << "Fibonacci number: ";
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		a = b;
		b = c;
		c = a + b;
	}
	cout << "F = " << c << endl;;
	return 0;
}