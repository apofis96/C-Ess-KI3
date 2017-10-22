// Lab2985.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void)
{
	double matrix[][4] = { { 1, 2, 3, 4 },
	{ 2, 2, 3, 1 },
	{ 3, 3, 3, 2 },
	{ 4, 1, 2, 4 }};
	int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	int row = sizeof(matrix) / sizeof(matrix[0]);
	bool issymmetric = true;
	if (side == row)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < row; j++)
			{
				if (matrix[i][j] != matrix[j][i]) { issymmetric = false; }
			}
		}
	}
	else issymmetric = false;
	if (issymmetric)
		cout << "The matrix is symmetric" << endl;
	else
		cout << "The matrix is not symmetric" << endl;
	return 0;
}

