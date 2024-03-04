#include<iostream>
#include<cmath>
#include "point.cpp"
#include "circle.cpp"
#include "rectangle.cpp"
using namespace std;

int main(void)
{
	Point2D p1(3.2, 5.6), p2(3.2, 5.6), p3(6.1, 7.9), p4;
	
	cout << "Point p1: ";
	p1.print();
	cout << "Point p2: ";
	p2.print();
	cout << "Point p3: ";
	p3.print();
	p4 = p1 + p3;
	cout << "p1+p3 = ";
	p4.print();
	p4 = p2 * 4;
	p4.print();
	if(p1 == p2) cout << "(p1==p2) is true\n";
	else cout << "(p1==p2) is false\n";
	if(p1 != p3) cout << "(p1!=p3) is true\n";
	else cout << "(p1!=p3) is false\n";
	
	Circle c1(p1, 3.5), c2(p3, 4.8), c3, c4(p2, 3.5);
	cout << "For circle c1: ";
	c1.print();
	cout << "For circle c2: ";
	c2.print();
	c3 = c1+p2;
	cout << "The circle c1 translated by point p2 is: ";
	c3.print();
	c3 = c2*4.5;
	cout << "The circle c2 scaled by a factor 4.5 is:\n";
	c3.print();
	c3 = c1+c2;
	cout << "The sum of the circles c1 and c2 results in the new circle c3:\n";
	c3.print();
	c3 = c2 - c1;
	cout << "The subtraction of the first circle from the second circle results in circle c3:\n";
	c3.print();
	if(c1 == c4) cout << "(c1==c4) is true\n";
	else cout << "(c1==c4) is false\n";
	if(c1 >= c2) cout << "(c1>=c2) is true\n";
	else cout << "(c1>=c2) is false\n";
	if(c1 <= c4) cout << "(c1<=c4) is true\n";
	else cout << "(c1<=c4) is false\n";
	if(c1 > c2) cout << "(c1>c2) is true\n";
	else cout << "(c1>c2) is false\n";
	if(c1 < c2) cout << "(c1<c2) is true\n";
	else cout << "(c1<c2) is false\n";
	c1++.print();
	(++c1).print();
	
	Rectangle r1(c3.getCenter(), p1), r2(p4, p3), r3;
	cout << "The rectangle r1 is:\n";
	r1.print();
	cout << "The rectangle r2 is:\n";
	r2.print();
	r3 = r1+p2;
	cout << "Rectangle r1 translated by point p2 is: ";
	r3.print();
	r3 = r2*0.5;
	cout << "Rectangle r2 scaled by a factor half is: ";
	r3.print();

	return 0;
}
