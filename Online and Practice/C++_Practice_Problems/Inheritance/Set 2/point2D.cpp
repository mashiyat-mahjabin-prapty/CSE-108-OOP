#include<iostream>
using namespace std;

class Point2D : public Shape
{
	double x,y;
public:
	Point2D();
	Point2D(STYPE argtype, int argx, int argy);
	void print();
	double area();
	bool contains(const Shape * rhs);
	bool contains(const Point2D * rhs);
	bool operator==(const Point2D &rhs);
	void setX(double argx) { x = argx; }
	void setY(double argy) { y = argy; }
	double getX() const { return x; }
	double getY() const { return y; }
	~Point2D(){}
};

Point2D::Point2D() //calls Base's default constructor
{
	x = 0.0;
	y = 0.0;
}

Point2D::Point2D(STYPE argtype, int argx, int argy) : Shape(argtype)
{
	x = argx;
	y = argy;
}

void Point2D::print()
{
	Shape::print();
	cout << " (" << x << "," << y << ")";
}

double Point2D::area()
{
	return 0.0;
}

bool Point2D::contains(const Shape *s)
{
	Point2D * pointType = dynamic_cast<Point2D*>(s);
	if(pointType!=NULL) 
	{
		//Supported
		return contains(pointType);
	}
	//By default, use base
	return Shape::contains(rhs);
}

bool Point2D::contains(const Point2D * rhs)
{
	if(x==rhs->x && y==rhs->y) return true;
	else return false;
}

bool Point2D::operator==(const Point2D & rhs)
{
	if( !Shape::operator==(rhs) ) return false;
	if( x==rhs.x && y==rhs.y ) return true;
	else return false;
}
