// Lab 3.8.7 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;
void increment(int & var, double i = 1.0)
{
	var += i;
}
void increment(float & var, double i = 1.0)
{
	var += i;
}
int main(void)
{
	int intvar = 0;
	float floatvar = 1.5;
	for (int i = 0; i < 10; i++)
		if (i % 2)
		{
			increment(intvar);
			increment(floatvar, sqrt(intvar));
		}
		else
		{
			increment(intvar, i);
			increment(floatvar);
		}
	cout << intvar * floatvar << endl;
	return 0;
}