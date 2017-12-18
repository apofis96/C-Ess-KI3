// Lab 3.4.7 (6).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num)
{
	int i, sq;
	if (num == 2) return true;
	if (num < 2 || num % 2 == 0) { return false; }
	sq = (int)sqrt(num);
	for (i = 3; i <= sq; i++)
	{
		if ((num%i) == 0) { return false; }
	}
	return true;
}
int main(void)
{
	for (int i = 0; i <= 21; i++)
		if (isPrime(i))
			cout << i << " ";
	cout << endl;
	return 0;
}
