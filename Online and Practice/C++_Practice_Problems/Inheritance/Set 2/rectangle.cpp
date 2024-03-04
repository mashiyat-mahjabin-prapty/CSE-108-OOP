#include<iostream>
using namespace std;

class Rectangle : public Shape
{
	Point2D topRight;
	Point2D bottomLeft;
Public:
	Rectangle();//implement this
	Rectangle(STYPE type, Point2D tr, Point2D bl);//implement this
	void print(); //implement this
	double area(); //implement this
	Point2D getbot();
	Point2D gettop();
	bool contains(const Shape *rhs); //implement this to check containment for point2d only
	bool operator==(const Rectangle &rhs); //implement this
	~Rectangle(){}
}

Rectangle::Rectangle()
{
	topRight.setX(0.0);
	topRight.setY(0.0);
	bottomLeft.setX(0.0);
	bottomLeft.setY(0.0);
} 

Rectangle::Rectangle(STYPE type, Point2D tr, Point2D bl) : Shape(type)
{
	topRight.setX(tr.getX());
	topRight.setY(tr.getY());
	bottomLeft.setX(bl.getX());
	bottomLeft.setY(bl.getY());
}

void Rectangle::print()
{
	Shape::print();
	cout << "Top-right Corner: ";
	topRight.print();
	cout << "Bottom-left Corner: ";
	bottomLeft.print();	
}

double Rectangle::area()
{
	return (topRight.getX()-bottomLeft.getX())*(topRight.getY()-bottomLeft.getY());
}

Point2D Rectangle::getbot()
{
    return bottomLeft;
}

Point2D Rectangle::gettop()
{
    return topRight;
}

bool Rectangle::contains(const Shape *rhs)
{
	Point2D * pointType = dynamic_cast<Point2D*>(s);
	if(pointType!=NULL) 
	{
		if(rhs.bottomLeft.getX()>=bottomLeft.getX() && rhs.topRight.getX<=topRight.getX() && rhs.bottomLeft.getY()>=bottomLeft.getY() && rhs.topRight.gety<=topRight.gety())
			return true;
		else return false;
	}
	//By default, use base
	return Shape::contains(rhs);
}

bool Rectangle::operator==(const Rectangle &rhs)
{
	if(rhs.area() == area())
	return true;
	else return false;
}
