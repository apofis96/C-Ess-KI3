// Lab24231.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	unsigned long long numb;
	int kek=0;
	cout << "Numb: ";
	cin >> numb;
	if (numb & 1) kek++;
	for (int i = 0; i < 63; i++)
	{
		numb >>= 1;
		if (numb & 1) kek++;
	}
	cout << kek<<endl;
    return 0;
}

