// Lab 7.2.5 (1).cpp: определяет точку входа для консольного приложения.
//
#include "iostream"
#include "string"
using namespace std;

class Exception {
public:
	string message;
	Exception() { message = "Your input is not valid. The area can't be negative.\n"; }
	Exception(string message) { this->message = message; }
};

class Matrix {
public:
	int rowCount;
	int colCount;
	int** matrix;
	Matrix(int rowCount, int colCount)
	{
		this->rowCount = rowCount;
		this->colCount = colCount;
		matrix = new int*[this->rowCount];
		for (int i = 0; i < this->rowCount; i++)
		{
			matrix[i] = new int[this->colCount];

		}

		for (int i = 0; i < this->rowCount; i++)
			for (int j = 0; j < this->colCount; j++)
			{
				matrix[i][j] = 0;
			}

	}
	void AddValue(int rowCount, int colCount, int value)
	{
		if (rowCount > this->rowCount || colCount > this->colCount)
			throw Exception("Index out of range exeption.\n");
		matrix[rowCount][colCount] = value;
	}
	int GetValue(int rowCount, int colCount)
	{
		if (rowCount > this->rowCount || colCount > this->colCount)
			throw Exception("Index out of range exeption.\n");
		return matrix[rowCount][colCount];
	}
	void Print()
	{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}
};

Matrix AddMatrixes(Matrix m1, Matrix m2)
{
	if (m1.colCount != m2.colCount || m1.rowCount != m2.rowCount)
		throw Exception("Matrices don't fit");
	Matrix resultMatrix(m1.rowCount, m1.colCount);
	for (int i = 0; i < m1.rowCount; i++)
		for (int j = 0; j < m1.colCount; j++)
			resultMatrix.AddValue(i, j, m1.GetValue(i, j) + m2.GetValue(i, j));
	return resultMatrix;

}



int main(void) {
	int m1X, m1Y, m2X, m2Y, m3X, m3Y;
	cout << "input\n";
	cin >> m1X;
	cin >> m1Y;
	cin >> m2X;
	cin >> m2Y;
	cin >> m3X;
	cin >> m3Y;

	Matrix m1 = Matrix(m1X, m1Y);
	Matrix m2 = Matrix(m2X, m2Y);
	Matrix m3 = Matrix(m3X, m3Y);
	try
	{
		Matrix m1Plusm2 = AddMatrixes(m1, m2);
		m1Plusm2.Print();
	}
	catch (Exception exp)
	{
		cout << exp.message << endl;
	}
	try
	{
		Matrix m2Plusm3 = AddMatrixes(m2, m3);
		m2Plusm3.Print();
	}
	catch (Exception exp)
	{
		cout << exp.message<< endl;
	}
	try
	{
		Matrix m1Plusm3 = AddMatrixes(m1, m3);
		m1Plusm3.Print();
	}
	catch (Exception exp)
	{
		cout << exp.message << endl;
	}
	system("pause");
	return 0;
}
