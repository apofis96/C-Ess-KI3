// Lab23192.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void) {
	double pi4 = 0.;
	long n;
	cout << "Number of iterations? ";
	cin >> n;
	for (long i = 0; i < n; i++)
	{
		pi4 += 1.0 / (1.0 + 4.0 * i) - 1.0 / (3.0 + 4.0 * i);
	}
	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	return 0;
}

