#include<iostream>
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
