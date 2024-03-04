#include<iostream>
#include<cmath>
using namespace std;

class Rectangle
{
	Point2D top_right, bot_left;
public:
	Rectangle(){
            top_right.setX(0);
            top_right.setY(0);
            bot_left.setX(0);
            bot_left.setY(0);
    }
    Rectangle(Point2D a, Point2D b){
            top_right.setX(a.getX());
            top_right.setY(a.getY());
            bot_left.setX(b.getX());
            bot_left.setY(b.getY());
    }
    void settop(Point2D argx);
    void setbot(Point2D argy);
    Point2D gettop();
    Point2D getbot();
	double area(); //returns area of the rectangle
	int intersect(Rectangle rhs); //determine if this rectangle intersects with rhs
	int contains(Point2D p);
	//int contains(Rectangle rhs); //determine if this rectangle contains rhs
	int inside(Circle c); //determine if this rectangle is completely inside the circle c
	double perimeter(); //returns perimeter of the circle
	Rectangle operator+(Point2D p);
	Rectangle operator*(double n);
	void print();
	~Rectangle()
    {
        top_right.setX(0);
        top_right.setY(0);
        bot_left.setX(0);
        bot_left.setY(0);
    }
};

void Rectangle::settop(Point2D a)
{
    top_right.setX(a.getX());
    top_right.setY(a.getY());
}
void Rectangle::setbot(Point2D a)
{
    bot_left.setX(a.getX());
    bot_left.setY(a.getY());
}
Point2D Rectangle::getbot()
{
    return bot_left;
}

Point2D Rectangle::gettop()
{
    return top_right;
}
double Rectangle::area()
{
    double p,q;
    p = top_right.getX() - bot_left.getX();
    q = top_right.getY() - bot_left.getY();
    return p*q;
}
double Rectangle::perimeter()
{
    double p,q;
    p = top_right.getX() - bot_left.getX();
    q = top_right.getY() - bot_left.getY();
    return 2*(p+q);
}
int Rectangle::contains(Point2D p)
{
    int l, m;
    l = p.getX();
    m = p.getY();
    if(l >= bot_left.getX() && l <= top_right.getX() && m >= top_right.getY() && m <= top_right.getY())
    return 1;
    else
    return 0;
}
int Rectangle::inside(Circle c)
{
    double r;
    int p, q;
    r = c.getRadius();
    p = c.getX();
    q = c.getY();
    if(bot_left.getX()<=p && (p-bot_left.getX()+r) > top_right.getX())
    return 0;
    else if(top_right.getX()>=p && (top_right.getX()-p+r) > (top_right.getX()-bot_left.getX()))
    return 0;
    if(bot_left.getY()<=q && (q-bot_left.getY()+r) > top_right.getY())
    return 0;
    else if(top_right.getY()>=q && (top_right.getY()-q+r) > (top_right.getY()-bot_left.getY()))
    return 0;
    else
    return 1;
}
int Rectangle::intersect(Rectangle rhs)
{
    int points = 0;
    if(contains(rhs.top_right))
    points++;
    if(contains(rhs.bot_left))
    points++;
    if(contains(Point2D(rhs.top_right.getX(), rhs.bot_left.getY())))
    points++;
    if(contains(Point2D(rhs.bot_left.getX(), rhs.top_right.getY())))
    points++;
    return points%4;
}

Rectangle Rectangle::operator+(Point2D p)
{
	Rectangle r;
	r.setbot(bot_left+p);
	r.settop(top_right+p);
	return r;
}

Rectangle Rectangle::operator*(double n)
{
	Rectangle r;
	r.setbot(bot_left*n);
	r.settop(top_right*n);
	return r;
}

void Rectangle::print()
{
	cout << "The bottom left point: ";
	bot_left.print();
	cout << "The top right point: ";
	top_right.print();
}
