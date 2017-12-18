// Lab 3.4.7 (4).cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
struct Date
{
	int year;
	int month;
	int day;
};
bool isLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		return true;
	}
	else if (year % 400 == 0)
	{
		return true;
	}
	else return false;
}
int monthLength(int year, int month)
{
	if (month == 2)
	{
		if (isLeap(year)) return 29;
		else return 28;
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 0;
}
int dayOfYear(Date date)
{
	int i = 0;
	for (int j = 1; j < date.month; j++)
	{
		i += monthLength(date.year, j);
	}
	i += date.day;
	return i;
}

int daysBetween(Date d1, Date d2)
{
	int year = d2.year - d1.year;
	if (year < 0) return -1;
	int i = 0;
	if (d1.year == d2.year)
	{
		i = dayOfYear(d2) - dayOfYear(d1);
	}
	else
	{
		for (int j = 0; j < year; j++)
		{
			if (isLeap(d1.year + j)) i += 366;
			else i += 365;
		}
		i -= dayOfYear(d1);
		i += dayOfYear(d2);
	}
	if (i < 0) return -1;
	else return i;
}
int main(void)
{
	Date since, till;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> till.year >> till.month >> till.day;
	cout << daysBetween(since, till) << endl;
	return 0;
}