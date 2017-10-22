// Lab21161.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	struct TIME
	{
		int hour;
		int minute;
	};
	TIME time_start, time_end;
	cout << "Start time:\n";
	while (true)
	{
		cout << "Type hour: ";
		cin >> time_start.hour;
		cout << "Type minuts: ";
		cin >> time_start.minute;
		if (time_start.hour<24 && time_start.hour>-1 && time_start.minute > -1 && time_start.minute < 60) break;
		else cout << "Invalid data\n";
	}

	cout << "End time:\n";
	while (true)
	{
		cout << "Type hour: ";
		cin >> time_end.hour;
		cout << "Type minuts: ";
		cin >> time_end.minute;
		if (time_end.hour<24 && time_start.hour>-1 && time_start.minute > -1 && time_start.minute < 60) 
		{
			if (time_end.hour < time_start.hour) { cout << "End must be later than start!"; }
			else
			{
				if (time_end.hour == time_start.hour && time_end.minute < time_start.minute) cout << "End must be later than start!";
				else break;
			}
		}
		else  
			cout << "Invalid data\n";
	}
	if (time_end.minute < time_start.minute) 
	{
		time_end.hour--;
		time_end.minute += 60;
	}
	time_end.minute -= time_start.minute;
	time_end.hour -= time_start.hour;
	cout << "Duration : " << time_end.hour<<":"<<time_end.minute << endl;
	return 0;
}

