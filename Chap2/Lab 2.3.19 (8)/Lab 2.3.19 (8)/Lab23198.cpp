// Lab23198.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n ;
	unsigned long long ni = 1;
	cout << "n = ";
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		ni *= i+1;
	}
	cout << "n! = " << ni<<endl;
    return 0;
}

