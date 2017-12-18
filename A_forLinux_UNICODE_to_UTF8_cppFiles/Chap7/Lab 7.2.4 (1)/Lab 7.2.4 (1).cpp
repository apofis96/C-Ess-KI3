// Lab 7.2.4 (1).cpp: определяет точку входа для консольного приложения.
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



float square_area(float a)
{
	if (a <= 0) throw Exception();
	return a * a;
}

float rectangle_area(float a, float b)
{
	if (a <= 0 || b <= 0) throw Exception();
	return a * b;
}

int main(void) {
	float a, b, r;
	cin >> a;
	cin >> b;
	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a, b);
		cout << rsquare << endl << rrectangle << endl;
	}
	catch (Exception exp)
	{
		cout << exp.message << endl;
	}

	system("pause");
	return 0;
}
