#include<iostream>
#include<cmath>
using namespace std;

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
	const Point3D * pointType = dynamic_cast<const Point3D*>rhs;
	if(pointType != NULL){
		return contains(pointType);
	}
	const Sphere * sphereType = dynamic_cast<const Sphere*>rhs;
	if(sphereType != NULL){
		return contains(sphereType);
	}
	return Shape::contains(rhs);
}
bool Sphere::contains(const Point3D *p)
{
	double diff;
	
	diff = (p.getX()-center.getX())*(p.getX()-center.getX());
	diff = diff + (p.getY()-center.getY())*(p.getY()-center.getY());
	diff = diff + (p.getZ()-center.getZ())*(p.getZ()-center.getZ());
	diff = diff - radius*radius;
	if(diff>0.0)
	return false;
	else return true;
}
bool Sphere::contains(const Sphere *s)
{
	double diff;
	
	diff = (p.getX()-center.getX())*(p.getX()-center.getX());
	diff = diff + (p.getY()-center.getY())*(p.getY()-center.getY());
	diff = diff + (p.getZ()-center.getZ())*(p.getZ()-center.getZ());
	diff = sqrt(diff);
	if(diff > radius+s.radius)
	return false;
	else return true;
}

