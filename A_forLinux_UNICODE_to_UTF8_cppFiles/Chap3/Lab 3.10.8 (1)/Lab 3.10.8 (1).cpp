// Lab 3.10.8 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void)
{
	int maxball;
	int ballsno;
	int *numbers;
	int rnd;
	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	if (maxball < ballsno)
	{
		cout << "Imposibru!\n";
		return 1;
	}
	srand(time(NULL));
	numbers = new int[ballsno];
	
	for (int i = 0; i < ballsno;)
	{
		rnd = rand() % maxball + 1;
		for (int j = 0; j < ballsno; j++)
		{
			if (rnd == numbers[j]) { rnd = -1; break;}
		}
		if (rnd != -1) { numbers[i] = rnd; i++; }
	}
	
	cout << "Balls: ";
	for (int j = 0; j < ballsno; j++)
	{
		cout << numbers[j] << " ";
	}
	cout << endl;
	return 0;
}