// Lab2153.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
	using namespace std;
int main(void) {
	int sys;
	float m, ft, in;
	cout << "System (0 for metric / 1 for imperial)\n";
	cin >> sys;
	if (sys == 1)
	{
		cout << "ft: ";
		cin >> ft;
		if (ft - (int)ft != 0)
		{
			cout << "ft must be int!";
			return 0;
		}
		cout << "in: ";
		cin >> in;
		m = ft * 0.3048;
		m += in * 0.0254;
		cout << m << "m";
	}
	else if (sys == 0)
	{
		cout << "m: ";
		cin >> m;
		ft = (int)(m / 0.3048);
		m = m - ft * 0.3048;
		in = m / 0.0254;
		cout << ft << "'" << in << "\"" << endl;
	}
	else
	{
		cout << "Wrong system!";
	}
	return 0;
}