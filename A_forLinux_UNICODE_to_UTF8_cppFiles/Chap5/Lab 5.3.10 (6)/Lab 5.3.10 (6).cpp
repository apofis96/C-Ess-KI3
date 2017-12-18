// Lab 5.3.10 (6).cpp : Defines the entry point for the console application.
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
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);
private:
	int numerator;
	int denominator;
	void reduce();	int gcd(int a, int b);
};
int Fraction::gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void Fraction::reduce()
{
	int a;
	a = gcd(numerator, denominator);
	this->numerator /= a;
	this->denominator /= a;
}

Fraction Fraction::plus(Fraction that)
{
	int num = this->numerator * that.denominator + that.numerator * this->denominator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;}

Fraction Fraction::minus(Fraction that)
{
	int num = this->numerator * that.denominator - that.numerator * this->denominator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;}

Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;}

Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	result.reduce();
	return result;}

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

string Fraction::toString()
{
	string answ = "";
	bool negativ = false;
	int a = this->numerator, b = this->denominator, c = 0;
	if (this->numerator < 0)
	{
		negativ = true;
		a *= -1;
	}
	if (this->denominator < 0)
	{
		if (negativ) { negativ = false; }
		else { negativ = true; }
		b *= -1;
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
	cout << "Fraction 1: ";
	getline(cin, input);
	int i = input.find("/");
	num = stoi(input.substr(0, i));
	den = stoi(input.substr(i + 1));
	if (den == 0)
	{
		cout << "Error\n";
		return 1;
	}
	Fraction fraction1(num, den);
	cout << "Fraction 2: ";
	getline(cin, input);
	i = input.find("/");
	num = stoi(input.substr(0, i));
	den = stoi(input.substr(i + 1));
	if (den == 0)
	{
		cout << "Error\n";
		return 1;
	}
	Fraction fraction2(num, den);
	//cout << fraction.toDouble();
	cout << fraction1.toString() << " + "  << fraction2.toString() <<" = "<<fraction1.plus(fraction2).toString()<< endl;
	cout << fraction1.toString() << " - " << fraction2.toString() << " = " << fraction1.minus(fraction2).toString() << endl;
	cout << fraction1.toString() << " * " << fraction2.toString() << " = " << fraction1.times(fraction2).toString() << endl;
	cout << fraction1.toString() << " / " << fraction2.toString() << " = " << fraction1.by(fraction2).toString() << endl;
	return 0;
}