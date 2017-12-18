// Lab 7.1.1 (1).cpp: определяет точку входа для консольного приложения.
//

#include "iostream"
#include "string"

using namespace std;

int main(void) {

	int a = 8, b = 0, c = 0;
	cin >> b;

	try {
		if (b == 0)
			throw string("Dividing by zero!");

		c = a / b;
	}
	catch (string exeption)
	{
		cout << exeption << endl;
	}

	cout << c << endl;

	return 0;
}