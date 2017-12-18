// Lab 3.2.12 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;
int main(void)
{
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
	int *ptr, min;
	ptr = vector;
	min = *ptr;
	for (int i = 1; i < n; i++)
	{
		ptr++;
		if (*ptr < min) min = *ptr;
	}
	cout << min << endl;
	return 0;
}
