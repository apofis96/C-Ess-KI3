// Lab2154.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int year, month, day;
	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
	if ((month -= 2) <= 0)
	{
		month += 12;
		year--;
	}
	month *= 83;
	month /= 32;
	month += day;
	month += year;
	month += year / 4;
	month -= year / 100;
	month += year / 400;
	month = month % 7;
	switch (month)
	{
	case 0: cout << "Sunday("<<month<<")"; break;
	case 1: cout << "Monday(" << month << ")"; break;
	case 2: cout << "Tuesday(" << month << ")"; break;
	case 3: cout << "Wednesday(" << month << ")"; break;
	case 4: cout << "Thursday(" << month << ")"; break;
	case 5: cout << "Friday(" << month << ")"; break;
	case 6: cout << "Saturday(" << month << ")"; break;
	default:
		break;
	}
    return 0;
}

