// Lab 4.1.9 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>

using namespace std;

void kek(int **kek1 , float *kek2, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		float sum = 0;
		for (int j = 1; j <= kek1[i][0]; j++)
		{
			sum += kek1[i][j];
		}
		kek2[i] = sum / kek1[i][0];
	}
	float sum = 0;
	for (int i = 0;i < rows ; i++)
	{
		sum += kek2[i];
	}
	kek2[rows] = sum / rows;
}

int main(void)
{
	int rows;
	cout << "Hello\n";
	cin >> rows;
	int **arr;
	arr = new int *[rows];
	float *arrr = new float[rows + 1];

	for (int r = 0; r < rows; r++)
	{
		int i;
		cin >> i;
		arr[r] = new int[i+1];
		arr[r][0] = i;
		for (int c = 1; c <= i; c++)
			cin >> arr[r][c];
	}
	kek(arr, arrr, rows);
	cout << "-----------\n";
	for (int r = 0; r < rows; r++)
	{
		cout << "Course " << r + 1 << ": final " << fixed << std::setprecision(2) << arrr[r]<<", grades : ";     // 1: final 3.50, grades : 2 3 4 5
		for (int c = 1; c <= arr[r][0]; c++)
			cout << arr[r][c] << " ";
		cout << endl;
	}
	cout << "Overall final : " << arrr[rows];

	for (int r = 0; r < rows; r++)
		delete[] arr[r];
	delete[] arr;
	delete[] arrr;
	return 0;
}