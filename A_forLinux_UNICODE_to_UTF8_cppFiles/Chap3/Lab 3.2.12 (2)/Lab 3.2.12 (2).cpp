// Lab 3.2.12 (2).cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
int main(void)
{
	int matrix[10][10] = {};
	int (*ptr1)[10] = matrix;
	int *ptr2 = *ptr1;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			*ptr2 = j*i;
			ptr2++;
		}
		ptr1++;
		ptr2 = *ptr1;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}