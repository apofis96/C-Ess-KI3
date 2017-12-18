// Lab 6.3.6 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

class Piece
{
public:
	Piece() { x = 98; y = 1; }

protected:
	char x;
	int y;

public:
	virtual bool CheckMove(int x, int y)
	{
		if (x < 'a' || x > 'h' || y < 1 || y > 8)
			return false;
		return true;
	}
};

class Man : public Piece
{
	bool CheckMove(int x, int y)
	{
		if (x < this->x)
			return false;

		if (abs(this->x - x) != 1 || abs(this->y - y) != 1)
			return false;

		return Piece::CheckMove(x, y);
	}
};

class King : public Piece
{
	bool CheckMove(int x, int y)
	{
		if (this->x - x == 0 || this->y - y == 0)
			return false;

		if (this->x - x != this->y - y)
			return false;

		return Piece::CheckMove(x, y);
	}
};

int main()
{
	Piece* man = new Man();
	Piece* king = new King();

	cout << man->CheckMove('c', 2) << endl;
	cout << king->CheckMove('d', 3) << endl;
	cout << man->CheckMove('d', 3) << endl;

	return 0;
}