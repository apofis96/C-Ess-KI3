// Lab23193.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	unsigned long long exp = 1;
	cout << "Input power: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		exp *= 2;

	}
	cout << "Exp: " << exp;
    return 0;
}

