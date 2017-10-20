// Lab23191.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int c0, counter = 0;
	cout << "Input number: ";
	cin >> c0;
	while (c0 != 1)
	{
		if (c0 % 2 == 0)
		{
			c0 /= 2;
		}
		else
		{
			c0 = 3 * c0 + 1;
		}
		counter++;
		cout << c0<<endl;
	}
	cout << "Steps: " << counter;
    return 0;
}

