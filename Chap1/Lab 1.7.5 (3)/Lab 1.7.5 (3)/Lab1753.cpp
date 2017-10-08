#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int o1, o2, o3, o4;
	cout << "Input first octet:";
	cin >> o1;
	if (o1 < 1 || o1>255) { cout << "number must be in the range from 1 to 255"; return 0; }
	cout << "Input second octet:";
	cin >> o2;
	if (o2 < 1 || o2>255) { cout << "number must be in the range from 1 to 255"; return 0; }
	cout << "Input third octet:";
	cin >> o3;
	if (o3 < 1 || o3>255) { cout << "number must be in the range from 1 to 255"; return 0; }
	cout << "Input fourth octet:";
	cin >> o4;
	if (o4 < 1 || o4>255) { cout << "number must be in the range from 1 to 255"; return 0; }
	cout << "IP:" << o1 << "." << o2 << "." << o3 << "." << o4 << endl;
	return 0;
}

