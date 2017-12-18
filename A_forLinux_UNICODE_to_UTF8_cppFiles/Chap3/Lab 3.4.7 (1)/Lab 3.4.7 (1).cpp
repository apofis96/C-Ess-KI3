// Lab 3.4.7 (1).cpp : Defines the entry point for the console application.
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
int main(void)
{
	for (int yr = 1995; yr < 2017; yr++)
		cout << yr << " -> " << isLeap(yr) << endl;
	return 0;
}