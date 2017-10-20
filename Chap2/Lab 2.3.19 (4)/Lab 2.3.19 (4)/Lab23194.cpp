// Lab23194.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	double exp = 1;
	cout << "Input power: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		exp /= 2;

	}
	cout.precision(20);
	cout << "Exp: " << exp;
	return 0;
}
