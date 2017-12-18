// Lab 4.2.5 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
int main()
{
	unsigned long long sum = 0;
	int n;
	cout << "N : ";
	cin >> n;
	if (n > 100000) { cout << "Too much"; return 1; }
	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}
	cout << "Sum : " << sum << endl;
    return 0;
}

