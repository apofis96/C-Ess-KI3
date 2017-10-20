// Lab23195.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void) {
	int n = 1;
	while (n == 1)
	{
		cout << "Side size (2 to 20): ";
		cin >> n;
		if (n <= 1)
		{
			cout << "Size must be greater than 1\n";
			n = 1;
		}
		else if (n > 20)
		{
			cout << "Sorry, the side size is too big\n";
			n = 1;
		}
	}
	n -= 2;
	cout << '+';
	for (int i = 0; i < n; i++)
		cout << '-';
	cout << '+' << endl;
	for (int i = 0; i < n; i++) {
		cout << '|';
		for (int j = 0; j < n; j++)
			cout << ' ';
		cout << '|' << endl;
	}
	cout << '+';
	for (int i = 0; i < n; i++)
		cout << '-';
	cout << '+' << endl;
	return 0;
}

