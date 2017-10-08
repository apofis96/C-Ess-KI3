#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int x, y;
	float a, b;
	cout << "x:";
	cin >> x;
	cout << "y:";
	cin >> y;
	a = x;
	b = y;
	if (1.0 / a == 1.0 / b) { cout << "Results are equal (by 0.000001 epsilon)\n"; }
	else { cout << "Results are not equal (by 0.000001 epsilon)\n"; }
    return 0;
}

