#include<iostream>
#include<cmath>
/*#include "shape.cpp"
#include "point2D.cpp"
#include "circle.cpp"
#include "rectangle.cpp"
#include "point3D.cpp" 
#include "shape3D.cpp"
#include "sphere.cpp"*/
using namespace std;

typedef enum {UNDEFINED, POINT2D, POINT3D, CIRCLE, SQUARE, RECTANGLE, SPHERE} STYPE;

class Shape
{
	STYPE type;
public:
	Shape();
	Shape(STYPE type);
	virtual void print();
	virtual double area();
	virtual bool contains(const Shape *s);
	//Intentionally made non-virtual
	bool operator==(const Shape &rhs);
	virtual ~Shape(){}
};

Shape::Shape()
{
	type = UNDEFINED;
}

Shape::Shape(STYPE argtype)
{
	type = argtype;
}

double Shape::area()
{
	cout << "I am a dummy Shape";
	return 0.0;
}

bool Shape::contains(const Shape *rhs)
{
	cout << "You see this, because appropriate contains function is undefined";
	return false;
}

void Shape::print()
{
	cout << "Type: " << type;
}

bool Shape::operator==(const Shape &rhs)
{
	if(type==rhs.type) return true;
	else return false;
}

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
	const Point2D * pointType = dynamic_cast<const Point2D*>(s);
	if(pointType!=NULL) 
	{
		//Supported
		return contains(pointType);
	}
	//By default, use base
	return Shape::contains(s);
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

class Rectangle : public Shape
{
	Point2D topRight;
	Point2D bottomLeft;
 public:
	Rectangle();//implement this
	Rectangle(STYPE type, Point2D tr, Point2D bl);//implement this
	void print(); //implement this
	double area(); //implement this
	Point2D getbot();
	Point2D gettop();
	bool contains(const Shape *rhs); //implement this to check containment for point2d only
	bool operator==(const Rectangle &rhs); //implement this
	~Rectangle(){}
};

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
	const Point2D * pointType = dynamic_cast<const Point2D*>(rhs);
	if(pointType!=NULL) 
	{
		if(rhs->getX()>=bottomLeft.getX() && rhs->getX<=topRight.getX() && rhs->getY()>=bottomLeft.getY() && rhs->getY<=topRight.getY())
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
	if(pointType!=NULL) 
	{
		//Supported
		return contains(pointType);
	}
	const Circle * circleType = dynamic_cast<const Circle*>(s);
	if(circleType!=NULL) 
	{
		//Supported
		return contains(circleType);
	}
	const Rectangle * rectangleType = dynamic_cast<const Rectangle*>(s);
	if(rectangleType!=NULL) 
	{
		//Supported
		return contains(rectangleType);
	}
	//By default
	return Shape::contains(s);
}

bool Circle::contains(const Point2D *p)
{
	double dif;
	dif = (p->getX()-center.getX())*(p->getX()-center.getX());
	dif = dif + (p->getY()-center.getY())*(p->getY()-center.getY());
	dif = dif - radius*radius;
	
	if(dif > 0.0)
	return false;
	else return true;
}

bool Circle::contains(const Circle *rhs)
{
	double dif;
	dif = (rhs->center.getX()-center.getX())*(rhs->center.getX()-center.getX());
	dif = dif + (rhs->center.getY()-center.getY())*(rhs->center.getY()-center.getY());
	dif = sqrt(dif);
	if(dif > rhs->radius+radius)
	return false;
	else return true;
}

bool Circle::contains(const Rectangle *p)
{
	double k,q;
    k = center.getX();
    q = center.getY();
    if(p->getbot().getX()<=k && (k-p->getbot().getX()+radius) > p->gettop().getX())
    return false;
    else if(p->gettop().getX()>=k && (p->gettop().getX()-k+radius) > (p->gettop().getX()-p->getbot().getX()))
    return false;
    if(p->getbot().getY()<=q && (q-p->getbot().getY()+radius) > p->gettop().getY())
    return false;
    else if(p->gettop().getY()>=q && (p->gettop().getY()-q+radius) > (p->gettop().getY()-p->getbot().getY()))
    return false;
    else
    return true;
}


class Point3D : public Point2D
{
    double z;
public:
    Point3D(); //already implemented
    Point3D(STYPE type, double argx, double argy, double argz); //implement this
    void print(); //already implemented
    //double area(); Not needed, base version is sufficient
    void setxyz(double argx, double argy, double argz);
    double getZ() {return z;}
	bool contains(const Shape *rhs); //implement this
	bool contains(const Point3D *rhs);  //implement this
	~Point3D(){}
};

Point3D::Point3D()
{
    z = 0;
}

Point3D::Point3D(STYPE type, double argx, double argy, double argz) : Point2D(type, argx, argy)
{
	z = argz;
}

void Point3D::setxyz(double argx, double argy, double argz)
{
	setX(argx);
	setY(argy);
	z = argz;	
}

bool Point3D::contains(const Shape *rhs)
{
	Point3D * pointType = dynamic_cast<Point3D*>(rhs);
	if(pointType!=NULL) 
	{
		//Supported
		return contains(pointType);
	}
	//By default, use base
	return Shape::contains(rhs);
}

bool Point3D::contains(const Point3D *rhs)
{
	if(getX() == rhs->getX() && getY() == rhs->getY() && z == rhs->z)
	return true;
	else return false;
}

void Point3D::print()
{
	Shape::print();
    cout << " (" << getX() << "," << getY() << "," << z << ")";
}

class Shape3D : public Shape
{
public:
	Shape3D();
	Shape3D(STYPE type);
	virtual double volume();
	~Shape3D(){}
};

Shape3D::Shape3D()
{
	
}

Shape3D::Shape3D(STYPE argtype) : Shape(argtype)
{
	
}

double Shape3D::volume()
{
	cout << "You see this, because appropriate function is missing in the derived class";
	return 0.0;
}

class Sphere : public Shape3D
{
	Point3D center;
	double radius;
public:
	Sphere();//implement this
	Sphere(STYPE type, Point3D c, double r);//implement this
	void print(); //implement this
	double area(); //implement this
	double volume(); //implement this
	bool contains(const Shape * rhs); //implement this for checking containgment of Point3D, Sphere inside sphere
	bool contains(const Point3D * p); //implement this
	bool contains(const Sphere * s); //implement this
	~Sphere(){}
};

Sphere::Sphere()
{
	center.setxyz(0.0, 0.0, 0.0);
	radius = 0.0;
}

Sphere::Sphere(STYPE type, Point3D c, double r) : Shape3D(type)
{
	center.setxyz(c.getX(), c.getY(), c.getZ());
	radius = r;
}

double Sphere::area()
{
	return 4.0*3.1416*radius*radius;
}

double Sphere::volume()
{
	return ((4.0*3.1416*radius*radius*radius*radius)/3.0);
}

bool Sphere::contains(const Shape *rhs)
{
	const Point3D * pointType = dynamic_cast<const Point3D*>(rhs);
	if(pointType != NULL){
		return contains(pointType);
	}
	const Sphere * sphereType = dynamic_cast<const Sphere*>(rhs);
	if(sphereType != NULL){
		return contains(sphereType);
	}
	return Shape::contains(rhs);
}
bool Sphere::contains(const Point3D *p)
{
	double diff;
	
	diff = (p->getX()-center.getX())*(p->getX()-center.getX());
	diff = diff + (p->getY()-center.getY())*(p->getY()-center.getY());
	diff = diff + (p->getZ()-center.getZ())*(p->getZ()-center.getZ());
	diff = diff - radius*radius;
	if(diff>0.0)
	return false;
	else return true;
}
bool Sphere::contains(const Sphere *s)
{
	double diff;
	
	diff = (s->getX()-center.getX())*(s->getX()-center.getX());
	diff = diff + (s->getY()-center.getY())*(s->getY()-center.getY());
	diff = diff + (s->getZ()-center.getZ())*(s->getZ()-center.getZ());
	diff = sqrt(diff);
	if(diff > radius+s->radius)
	return false;
	else return true;
}

int main(void)
{
	//Write main function to demonstrate your code
	//Create circles, rectanges, point2d,point3d,and sphere objects using base class pointers
	//then call the virtual methods to show that polymorphism works!
	while(1)
	{
		int choice = 10;
		Shape * shape;
		Shape3D * shape3D;
		switch(choice)
		{
			cout << "1. Point2D 2. Rectangle 3. Circle\n";
			cout << "4. Point3D 5. Sphere. 0. Exit\n";
			cout << "Your choice:";
			cin >> choice;
			case 1:
				shape = new Point2D(POINT2D, 5.0,10.0);
				shape->print();
				cout << "\nArea: " << shape->area();
				break;
			case 2:
				Point2D p1(POINT2D,5.0,5.0);
				Point2D p2(POINT2D,20.0,20.0);
				shape = new Rectangle(RECTANGLE, p1, p2);
				shape->print();
				cout << "\nArea: " << shape->area();
				break;
			case 3:
				Point2D p1(POINT2D,0.0,0.0);
				shape = new Circle(CIRCLE,p1,10.0);
				break;
			case 4:
				shape3D = new Point3D(POINT3D,5.0,10.0,20.0);;
				shape3D->print();
				cout << "\nArea: " << shape3D->area();
				cout << "\nVolume: " << shape3D->volume();
				break;
			case 5:
				Point3D p1(POINT3D,0.0,0.0,0.0);
				shape3D = new Sphere(SPHERE,p1,10.0);
				shape3D->print();
				cout << "\nArea: " << shape3D->area();
				cout << "\nVolume: " << shape3D->volume();
				break;
		}
		if(choice==0.0)break;		
	}
	
	//add other functions for demonstration
	return 0;
}
