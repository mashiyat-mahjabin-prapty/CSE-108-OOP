#include<iostream>
#include<cmath>
using namespace std;

class Point2D
{
	double x,y;
public:
	Point2D(){ x = 0.0; y = 0.0; } //default constructor initializes to (0,0)
	Point2D(double x, double y);
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
	void print();
	Point2D operator+(Point2D p);
	Point2D operator*(double n);
	int operator==(Point2D p);
	int operator!=(Point2D p);
	~Point2D(){ x = 0.0; y = 0.0; } //destructor that sets all values to 0
};

Point2D::Point2D(double argx,double argy)
{
	x = argx;
	y = argy;
}

void Point2D::setX(double argx)
{
	x = argx;
}

void Point2D::setY(double argy)
{
	y = argy;
}

double Point2D::getX()
{
	return x;
}

double Point2D::getY()
{
	return y;
}

void Point2D::print()
{
	cout << "(" << x << "," << y << ")" << endl;
}

Point2D Point2D::operator+(Point2D p)
{
	Point2D temp;
	temp.x = x + p.x;
	temp.y = y + p.y;
	
	return temp;
}

Point2D Point2D::operator*(double n)
{
	Point2D temp;
	temp.x = x*n;
	temp.y = y*n;
	
	return temp;
}

int Point2D::operator==(Point2D p)
{
	return (x==p.x) && (y==p.y);
}

int Point2D::operator!=(Point2D p)
{
	return (x!=p.x) || (y!=p.y);
}

