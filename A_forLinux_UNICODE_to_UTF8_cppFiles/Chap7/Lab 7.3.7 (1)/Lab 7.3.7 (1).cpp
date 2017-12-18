// Lab 7.3.7 (1).cpp: определяет точку входа для консольного приложения.
//

#include "iostream"
#include "string"
#include "fstream"
#include "io.h"  
#include "stdio.h"
#include "stdlib.h"
using namespace std;

class Exception {
public:
	string message;
	Exception() { message = "Unknown exception\n"; }
	Exception(string message) { this->message = message; }
};

class MyClass {
private: int** matrix;
public: MyClass()
{
	matrix = new int*[2];
	matrix[0] = new int[2];
	matrix[1] = new int[2];
}
		void LoadMatrixFromFile(string path) {
			if (!ifstream(path))
				throw Exception("File not found at: " + path);
			ifstream file;
			file.open(path);
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					file >> matrix[i][j];
			file.close();
		}
		void SaveMatrixToFile(string path)
		{
			if (_access(path.c_str(), 2) == -1)
				throw Exception("No rights to write to file: " + path);
			ofstream file;
			file.open(path);
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					file << matrix[i][j] << " ";
			file.close();
		}

};

int main(void) {
	float a, b, r;
	try
	{
		MyClass m;
		m.LoadMatrixFromFile("D:\\nonexisting.txt");
	}
	catch (Exception exp)
	{
		cout << exp.message << endl;
	}
	try
	{
		MyClass m;
		m.SaveMatrixToFile("D:\\readOnlyFile.txt");
	}
	catch (Exception exp)
	{
		cout << exp.message << endl;
	}
	system("pause");
	return 0;
}
