// Lab2151.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	int year;
	string s;

	cout << "Enter a year: ";
	cin >> year;
		// Insert your code here
	if (year < 1582)
	{
		s = "Non Gregorian";
	}
	else 
	{
		if (year % 4 == 0 && year % 100 != 0) 
		{
			s = "leap year";
		}
		else if (year % 400 == 0) 
		{
			s = "leap year";
		}
		else s = "common year";
	}
	cout << s;
	return 0;
}

