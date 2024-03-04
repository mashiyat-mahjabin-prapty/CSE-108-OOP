#include<iostream>
#include<cmath>
using namespace std;

class pointType
{
    private:
    double xCoordinate;
    double yCoordinate;

    public:
    pointType(double x = 0.0, double y = 0.0)
    {
        xCoordinate = x;
        yCoordinate = y;
    }
    void setPoint(double x, double y)
    {
        xCoordinate = x;
        yCoordinate = y;
    }
    void print()
    {
        cout << "(" << xCoordinate << ", " << yCoordinate << ")" << endl;
    }
};

class circleType:public pointType{
	double radius;
	public:
		circleType(double x, double y, double r=0.0):pointType(x, y) { radius = r; }
		void setRadius(double r) { radius = r; }
		void print()
    	{
        	cout << radius << endl;
    	}
    	double getRadius() {return radius;}
};

class cylinderType:public circleType{
	double height;
	public:
		cylinderType(double x=0.0, double y=0.0, double r=0.0, double h=0.0):circleType(x, y, r) { height = h; }
		void setHeight(double h) { height = h; }
		void setCenterRadiusHeight(double x, double y, double r, double h){
			height = h;
			setPoint(x, y);
			setRadius(r);
		}
		void print(){
			cout << "Base Center: ";
			pointType::print();
			cout << "Base Radius: ";
			circleType::print();
			cout << "Base Circumference: " << 2*acos(-1)*getRadius() << endl;
			cout << "Base Area: " << acos(-1)*getRadius()*getRadius() << endl;
			cout << "Cylinder Height: " << height << endl;
			cout << "Cylinder Surface Area: " << 2.0*acos(-1)*getRadius()*getRadius() + 2*acos(-1)*getRadius()*height << endl;
			cout << "Cylinder Volume: " << acos(-1)*getRadius()*getRadius()*height << endl;
		}
};

int main()
{
    cylinderType cylinder1(3, 2.5, 4, 2.5);
    cylinderType cylinder2;

    cout << "***** Cylinder 1 *****" << endl;
    cylinder1.print();
    cout << endl;

    cylinder2.setPoint(-2.5, 7);
    cylinder2.setRadius(4);
    cylinder2.setHeight(3.9);
    cout << "***** Cylinder 2 *****" << endl;
    cylinder2.print();
    cout << endl;

    double x, y;
    double r;
    double h;

    cylinderType cylinder3;

    cout << "Enter x Coordinates of the center: ";
    cin >> x;
    cout << endl;

    cout << "Enter y Coordinate of the center: ";
    cin >> y;
    cout << endl;

    cout << "Enter base radius: ";
    cin >> r;
    cout << endl;

    cout << "Enter cylinder height: ";
    cin >> h;
    cout << endl;

    cylinder3.setCenterRadiusHeight(x, y, r, h);

    cout << "***** Cylinder 3 *****" << endl;
    cylinder3.print();
    cout << endl;

    return 0;
}
