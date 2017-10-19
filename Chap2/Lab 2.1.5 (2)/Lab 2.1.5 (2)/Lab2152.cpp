// Lab2152.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void) {
	float grossprice, taxrate, netprice, taxvalue;
	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;
	// Insert you code here
	if (grossprice <= 0 || taxrate <= 0 || taxrate >= 100) {
		cout << "Price and taxrate must be more then 0! Taxrate must be less than 100!";
		return 0;
	}
	netprice = grossprice / ((taxrate + 100) / 100);
	taxvalue = grossprice - netprice;
	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	return 0;
}
