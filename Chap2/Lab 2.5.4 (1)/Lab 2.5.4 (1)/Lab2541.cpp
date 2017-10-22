// Lab2541.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double a = 0, b = 0;
	int c = 0;
	while (true)
	{
		cout << "MENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice : ";
		cin >> c;
		if (c != 0) 
		{
			cout << "Number a = ";
			cin >> a;
			cout << "Number b = ";
			cin >> b;
			cout << "Result = ";
		}
		switch (c)
		{
		case 0: return 0;
		case 1: cout << a + b<<endl; break;
		case 2: cout << a - b << endl; break;
		case 3: cout << a*b << endl; break;
		case 4: cout << a / b << endl; break;
		default: cout << "Wrong operation!\n";
			break;
		}
	}
    return 0;
}

