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
	TIME time;
	int duration = 0;
	while (true)
	{
		cout << "Type hour: ";
		cin >> time.hour;
		cout << "Type minuts: ";
		cin >> time.minute;
		if (time.hour<24 && time.hour>-1 && time.minute > -1 && time.minute < 60) break;
		else cout << "Invalid data\n";
	}
	while (duration <= 0) 
	{
		cout << "Duration: ";
		cin >> duration;
	}

	time.minute += duration;
	while (time.minute >= 60)
	{
		time.hour++;
		time.minute -= 60;
	}
	while (time.hour >= 24)
	{
		time.hour -= 24;
	}
	cout << "Time: " << time.hour << ":" << time.minute << endl;
    return 0;
}

