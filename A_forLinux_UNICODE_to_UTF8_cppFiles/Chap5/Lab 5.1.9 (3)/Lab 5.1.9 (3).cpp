// Lab 5.1.9 (3).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
};

void AdHocSquare::set_side(double side)
{
	this->side = side;
}

double AdHocSquare::get_area()
{
	return (this->side * this->side);
}

class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();
private:
	double side;
	double area;
	bool side_changed;
};
void LazySquare::set_side(double side)
{
	this->side = side;
	this->side_changed = true;
}

double LazySquare::get_area()
{
	if (side_changed)
	{
		this->area = side*side;
		side_changed = false;
	}
	return area;
}

AdHocSquare::AdHocSquare(double side)
{
	this->side = side;
}

LazySquare::LazySquare(double side)
{
	this->side = side;
	this->side_changed = true;
}

int main()
{
	AdHocSquare ad(2);
	LazySquare la(2);
	cout << ad.get_area()<<endl;
	la.set_side(4);
	cout << la.get_area() << endl;
	
	return 0;
}