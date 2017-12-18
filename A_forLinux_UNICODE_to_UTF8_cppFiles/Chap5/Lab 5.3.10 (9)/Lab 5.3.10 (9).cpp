// Lab 5.3.10 (9).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Point2D
{
public:
	Point2D(double x, double y);
	//string toString();
	//double toDouble();
	// ...
	double getX() { return x; }
	double getY() { return y; }
	double distanceTo(Point2D that);
private:
	double x;
	double y;
};
Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}
double Point2D::distanceTo(Point2D that)
{
	return (sqrt(pow(this->x - that.x, 2) + pow(this->y - that.y, 2)));
}

class Line2D
{
public:
	Line2D(double slope, double y_intercept);
	Line2D(Point2D pointA, Point2D pointB);
	string toString();
	// ...
private:
	double slope;
	double y_intercept;
};

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	slope = (pointB.getY() - pointA.getY()) / (pointB.getX() - pointA.getX());
	y_intercept = (pointB.getX()*pointA.getY() - pointB.getY()*pointA.getX()) / (pointB.getX() - pointA.getX());
}

Line2D::Line2D(double slope, double y_intercept)
{
	this->slope = slope;
	this->y_intercept = y_intercept;
}

string Line2D::toString()
{
	string answ;
	answ += "y = ";
	answ += to_string(slope);
	answ.erase(answ.find_last_not_of('0') + 1, string::npos);
	answ.erase(answ.find_last_not_of('.') + 1, string::npos);
	answ += "x ";
	if (y_intercept >= 0)
	{
		answ += "+ ";
	}
	answ += to_string(y_intercept);
	answ.erase(answ.find_last_not_of('0') + 1, string::npos);
	answ.erase(answ.find_last_not_of('.') + 1, string::npos);
	return answ;

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
	Line2D line(point1, point2);
	cout << line.toString()<<endl;
	return 0;
}