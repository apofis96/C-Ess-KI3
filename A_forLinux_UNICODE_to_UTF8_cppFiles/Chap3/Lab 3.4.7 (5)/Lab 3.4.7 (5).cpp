// Lab 3.4.7 (5).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <ctime>
using namespace std;
struct Date
{
	int year;
	int month;
	int day;
};
Date today(void)
{
	Date to;
	time_t t = time(NULL);
	tm tl;// = localtime(&t);
	localtime_s(&tl, &t);
	to.year = tl.tm_year + 1900;	to.month = tl.tm_mon + 1;	to.day = tl.tm_mday;	return to;
}
int main(void)
{
	Date t = today();
	cout << t.year << "-" << t.month << "-" << t.day << endl;
	return 0;
}