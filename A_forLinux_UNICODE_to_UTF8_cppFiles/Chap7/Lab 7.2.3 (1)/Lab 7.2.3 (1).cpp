// Lab 7.2.3 (1).cpp: определяет точку входа для консольного приложения.
//

#include "iostream"

using namespace std;
const int DivideByZero = 111;

float internaldiv(float arg1, float arg2)
{
	return arg1 / arg2;
}

float div(float arg1, float arg2)
{
	if (arg2 == 0.0)
		throw DivideByZero;

	return internaldiv(arg1, arg2);;
}

int main(void) {
	float a, b;

	while (cin >> a) {
		cin >> b;

		try
		{
			cout << div(a, b) << endl;
		}
		catch (int code)
		{
			cout << "Are you kidding me?" << endl;
			if (code == 111)
			{
				cout << "Your input is not valid. You can't divide by zero." << endl;
			}
		}
	}
	system("pause");
	return 0;
}