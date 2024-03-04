#include<iostream>
#include<cmath>
using namespace std;

class Circle
{
	Point2D center;
	double radius;
public:
	Circle(){radius=0; center.setX(0); center.setY(0);}
	Circle(Point2D c, double r);
	Point2D getCenter();
	double getRadius();
	void setX(double argx);
    void setY(double argy);
    double getX();
    double getY();
	//write getter and setter methods for this class
	double area(); //returns area of the circle
	void print(); //prints the circle in the stdout
	int intersect(Circle rhs); //determine if this circle intersects with rhs
	int contains(Point2D p); //determine if this circle contains point p
	double perimeter(); //returns perimeter of the circle
	//write a destructor that sets all values to 0
	double distance(Point2D p1, Point2D p2);
	Circle operator+(Point2D p);
	Circle operator*(double n);
	Circle operator+(Circle c);
	Circle operator-(Circle c);
	bool operator==(Circle c);
	bool operator>=(Circle c);
	bool operator<=(Circle c);
	bool operator>(Circle c);
	bool operator<(Circle c);
	Circle operator++();
	Circle operator++(int notused);
	~Circle(){
        center.setX(0.0);
        center.setY(0.0);
        radius = 0.0;
    }
};

Circle::Circle(Point2D c, double r)
{
	radius = r;
	center.setX(c.getX());
	center.setY(c.getY());
}

Point2D Circle::getCenter()
{
	Point2D p;
	p.setX(center.getX());
	p.setY(center.getY());
	
	return p;
}

double Circle::getRadius()
{
	return radius;
}

void Circle::setX(double argx)
{
    center.setX(argx);
}

void Circle::setY(double argy)
{
    center.setY(argy);
}

double Circle::getX()
{
    return center.getX();
}

double Circle::getY()
{
    return center.getY();
}

double Circle::area()
{
	return acos(-1)*radius*radius;
}

int Circle::intersect(Circle rhs)
{
	int p, q;
    p = rhs.getX();
    q = rhs.getY();
    double distance = (center.getX()-p)*(center.getX()-p) + (center.getY()-q)*(center.getY()-q);
    distance = sqrt(distance);
    if(distance > rhs.radius+radius)
    return 0;
    else if(radius> rhs.radius && (distance+rhs.radius > radius)){
        return 0;
    }
    else if(rhs.radius > radius && (distance+radius>rhs.radius)){
        return 0;
    }
    else
    return 1;
}

int Circle::contains(Point2D rhs)
{
    int p, q;
    p = rhs.getX();
    q = rhs.getY();
    double distance = (center.getX()-p)*(center.getX()-p) + (center.getY()-q)*(center.getY()-q);
    distance = sqrt(distance);
    if(distance <= radius)
    return 1;
    else
    return 0;
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius << endl;
}

bool Circle::operator==(Circle c)
{
	return area()==c.area();
}

bool Circle::operator>=(Circle c)
{
	return area() >= c.area();
}

bool Circle::operator<=(Circle c)
{
	return area() <= c.area();
}

bool Circle::operator>(Circle c)
{
	return area() > c.area();
}

bool Circle::operator<(Circle c)
{
	return area() < c.area();
}

Circle Circle::operator+(Point2D p)
{
	Circle temp;
	temp.setX(p.getX()+getX());
	temp.setY(p.getY()+getY());
	temp.radius = radius;
	return temp;
}

Circle Circle::operator*(double d)
{
	Circle temp;
	temp.setX(center.getX()*d);
	temp.setY(center.getY()*d);
	temp.radius = radius*d;
	return temp;
}

Circle Circle::operator+(Circle c)
{
	double alpha;
	alpha = radius / (radius+c.getRadius());
	cout << "The weighted factor: " << alpha << endl;
	Circle a;
	a.radius = radius+c.radius;
	Point2D c1 = center*(alpha);
	Point2D c2 = c.getCenter()*(1.0-alpha);
	a.center = c1 + c2;
	return a;
}

Circle Circle::operator-(Circle c)
{
	double alpha;
	alpha = radius / (radius+c.getRadius());
	cout << "The weighted factor: " << alpha << endl;
	Circle a;
	a.radius = radius-c.radius;
	Point2D c1 = center*(alpha);
	Point2D c2 = c.getCenter()*(1.0-alpha);
	a.center = c1 + c2;
	return a;
}

Circle Circle::operator++() 
{
	double x, y;
	x = center.getX();
	y = center.getY();
	center.setX(x++);
	center.setY(y++);
	return *this;
}

Circle Circle::operator++(int notused)
{
	double x, y;
	x = center.getX();
	y = center.getY();
	center.setX(++x);
	center.setY(++y);
	return *this;
}

