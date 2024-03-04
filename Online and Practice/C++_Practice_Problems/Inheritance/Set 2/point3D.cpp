#include<iostream>
using namespace std;

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
	Point3D * pointType = dynamic_cast<Point3D*>(s);
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
	if(getX() == rhs.getX() && getY() == rhs.getY() && z == rhs.z)
	return true;
	else return false;
}

void Point3D::print()
{
	Shape::print();
    cout << " (" << getX() << "," << getY() << "," << z << ")";
}
