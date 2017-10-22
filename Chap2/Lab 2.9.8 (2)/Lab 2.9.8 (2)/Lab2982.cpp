// Lab2982.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int cash = 0;
	int arra[2][5] = { {0,0,0,0,0} , { 50, 20,10,5,1 } };
	cout << "Cash = ";
	cin >> cash;
	while (cash != 0)
	{
		for (int i = 0; i < 5;) 
		{
			if (cash >= arra[1][i]) {
				cash -= arra[1][i]; arra[0][i]++;
			}
			else i++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < arra[0][i]; j++)
		{
			cout << arra[1][i] << " ";
		}
	}
	
    return 0;
}

