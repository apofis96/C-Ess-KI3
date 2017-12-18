// Lab 3.6.3 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
void increment(int &var, int i = 1)
{
	var += i;
}
int main(void)
{
	int var = 0;
	for (int i = 0; i < 10; i++)
		if (i % 2)
			increment(var);
		else
			increment(var, i);
	cout << var << endl;
	return 0;
}
