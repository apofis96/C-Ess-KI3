// Lab 8.1.1 (1).cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;
class Matrix
{
public:
	int a11, a12, a21, a22;
	Matrix(int a11, int a12, int a21, int a22);
	friend ostream& operator<<(ostream& os, const Matrix& m)
	{
		cout << m.a11 << " " << m.a12 << endl;
		cout << m.a21 << " " << m.a22 << endl;
		return os;
		
	};
};
Matrix::Matrix(int a11, int a12, int a21, int a22)
{
	this->a11 = a11;
	this->a12 = a12;
	this->a21 = a21;
	this->a22 = a22;
}


int main(void) {
	int a11, a12, a21, a22;
	cout << "Enter a11 \n";
	cin >> a11;
	cout << "Enter a12 \n";
	cin >> a12;
	cout << "Enter a21 \n";
	cin >> a21;
	cout << "Enter a11 \n";
	cin >> a22;
	Matrix m(a11, a12, a21, a22);
	cout << m;
	return 0;
}

