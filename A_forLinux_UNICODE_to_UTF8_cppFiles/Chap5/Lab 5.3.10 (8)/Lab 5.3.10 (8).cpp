// Lab 5.3.10 (8).cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <math.h>
using namespace std;
class Point2D
{
public:
	Point2D(double x, double y);
	//string toString();
	//double toDouble();
	// ...
	double distanceTo(Point2D that);
private:
	double x;
	double y;
};Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}
double Point2D::distanceTo(Point2D that)
{
	return (sqrt(pow(this->x - that.x, 2) + pow(this->y - that.y, 2)));
}


int main()
{
	double a, b;
	cin >> a;
	cin >> b;
	Point2D point1(a, b);
	cin >> a;
	cin >> b;
	Point2D point2(a, b);
	cout << point1.distanceTo(point2) << endl;
    return 0;
}

