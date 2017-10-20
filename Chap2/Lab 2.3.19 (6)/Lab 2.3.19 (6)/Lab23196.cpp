// Lab23196.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int h = 0;
	while (h == 0)
	{
		cout << "Input size of piramid(3-8): ";
		cin >> h;
		if (h < 3 | h>8)
		{
			cout << "Wrong size\n";
			h = 0;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 11; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < 11; j++)
			cout << " ";
	}
	cout << endl;
	int k = 10;
	int m = 1;
	for (int i = 2; i < h; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int l = 0; l < k; l++)
			{
				cout << " ";
			}
			cout << "*";
			for (int l = 0; l < m; l++)
			{
				cout << " ";
			}
			cout << "*";
			for (int l = 0; l < k; l++)
			{
				cout << " ";
			}
		}
		cout << endl;
		m += 2;
		k -= 1;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < h*2 - 1; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < k; j++)
		{
			cout << " ";
		}
	}
	cout << endl;



    return 0;
}

