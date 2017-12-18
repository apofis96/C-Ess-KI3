// Lab 5.3.10 (5).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Fraction
{
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};
Fraction::Fraction(int numerator, int denominator) 
{
	this->numerator = numerator;
	this->denominator = denominator;
}

string Fraction::toString()
{
	string answ ="";
	bool negativ = false;
	int a = numerator, b = denominator, c = 0;
	if (numerator < 0) { 
		negativ = true;
		a *= -1;
	}
	if (denominator < 0)
	{
		if (negativ) { negativ = false; }
		else { negativ = true; }
		b *=  -1;
	}

	if (negativ)
	{
		answ = "-";
	}


	if (a >= b)
	{
		c = a / b;
		answ += to_string(c);
		if ((a - c*b) == 0) 
		{
			return answ;
		}
		answ += " ";
		answ += to_string(a - c*b);
		answ += "/";
		answ += to_string(b);
		return answ;
	}
	
	if (negativ)
	{
		answ += "1 ";
	}
	answ += to_string(a);
	answ += "/";
	answ += to_string(b);
	return answ;

}

double Fraction::toDouble()
{
	return ((double)numerator / (double)denominator);
}
int main(void)
{
	int num, den;
	std::string input = "";
	getline(cin, input);
	int i = input.find("/");
	num = stoi(input.substr(0, i));
	cout << num << endl;
	den = stoi(input.substr(i + 1));
	cout << den << endl;
	if (den == 0)
	{
		cout << "Error\n";
		return 1;
	}
	// parse input and get numerator and denominator
	Fraction fraction(num, den);
	//cout << fraction.toDouble();
	cout << fraction.toString() << " is " <<fixed << setprecision(2) << fraction.toDouble() << " in decimal" << endl;
	return 0;
}