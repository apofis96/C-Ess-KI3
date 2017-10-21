// Lab23199.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	cout << "Bottom right = " << n*n - n*2 + 2<< endl;


    return 0;
}

