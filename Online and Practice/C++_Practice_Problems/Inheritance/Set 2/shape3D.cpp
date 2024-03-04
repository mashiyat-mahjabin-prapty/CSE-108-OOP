#include<iostream>
using namespace std;

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
