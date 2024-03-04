#include<iostream>
#include<cmath>
using namespace std;


class Circle : public Shape
{
	Point2D center;
	double radius;
public:
	Circle();
	Circle(STYPE type, Point2D c, double r); //implement this
	double area(); //implement this
	void print(); //implement this
	bool contains(const Shape * s); //implemented partially
	bool contains(const Point2D * p); //implement this
	bool contains(const Circle * rhs); //implement this
	bool contains(const Rectangle * p); //implement this
	bool operator==(const Circle &rhs); //implement this
	~Circle(){}
};

Circle::Circle()
{
	radius = 0.0;
}

Circle::Circle(STYPE type, Point2D c, double r) : Shape(type)
{
	center.setX(c.getX());
	center.setY(c.getY());
	radius = r;
}

void Circle::print()
{
	Shape::print();
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius << endl;
}

double Circle::area()
{
	return 3.1416*radius*radius;
}

bool Circle::contains(const Shape * s)
{
	const Point2D * pointType = dynamic_cast<const Point2D*>(s);
	if(pointType!=null) 
	{
		//Supported
		return contains(pointType);
	}
	const Circle * circleType = dynamic_cast<const Circle*>(s);
	if(circleType!=null) 
	{
		//Supported
		return contains(circleType);
	}
	const Rectangle * rectangleType = dynamic_cast<const Rectangle*>(s);
	if(rectangleType!=null) 
	{
		//Supported
		return contains(rectangeType);
	}
	//By default
	return Shape::contains(rhs);
}

bool Circle::contains(const Point2D *p)
{
	double dif;
	dif = (p.getX()-center.getX())*(p.getX()-center.getX());
	dif = dif + (p.getY()-center.getY())*(p.getY()-center.getY());
	dif = dif - radius*radius;
	
	if(dif > 0.0)
	return false;
	else return true;
}

bool Circle::contains(const Circle *rhs)
{
	double dif;
	dif = (rhs.center.getX()-center.getX())*(rhs.center.getX()-center.getX());
	dif = dif + (rhs.center.getY()-center.getY())*(rhs.center.getY()-center.getY());
	dif = sqrt(dif);
	if(dif > rhs.radius+radius)
	return false;
	else return true;
}

bool Circle::contains(const Rectangle *p)
{
	double p,q;
    p = center.getX();
    q = center.getY();
    if(p.getbot().getX()<=p && (p-p.getbot().getX()+radius) > p.gettop().getX())
    return false;
    else if(p.gettop().getX()>=p && (p.gettop().getX()-p+r) > (p.gettop().getX()-p.getbot().getX()))
    return false;
    if(p.getbot().getY()<=q && (q-p.getbot().getY()+r) > p.gettop().getY())
    return false;
    else if(p.gettop().getY()>=q && (p.gettop().getY()-q+r) > (p.gettop().getY()-p.getbot().getY()))
    return false;
    else
    return true;
}
