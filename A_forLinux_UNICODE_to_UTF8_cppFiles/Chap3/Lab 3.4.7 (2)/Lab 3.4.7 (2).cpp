// Lab 3.4.7 (2).cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
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
		if(isLeap(year)) return 29;
		else return 28;
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 0;
}
int main(void)
{
	for (int yr = 2000; yr < 2002; yr++)
	{
		for (int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr, mo) << " ";
		cout << endl;
	}
	return 0;
}