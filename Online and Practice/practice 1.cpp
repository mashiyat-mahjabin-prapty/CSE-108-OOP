#include<iostream>
#include<cmath>
using namespace std;


class Point2D
{
    int x,y;
public:
    Point2D()
    {
        x = 0;    //default constructor initializes to (0,0)
        y = 0;
    }
    Point2D(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void print();
    ~Point2D()
    {
        x = 0;    //destructor that sets all values to 0
        y = 0;
    }
};

Point2D::Point2D(int argx,int argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(int argx)
{
    x = argx;
}

void Point2D::setY(int argy)
{
    y = argy;
}

int Point2D::getX()
{
    return x;
}

int Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

class Circle
{
    Point2D center;
    double radius;
public:
    Circle();
    Circle(Point2D c, double r);
    void setX(int argx);
    void setY(int argy);
    int getX();
    int getY();
    double getRad(){return radius;};
    void setRad(double argr){radius = argr;};
    double area(); //returns area of the circle
    void print(); //prints the circle in the output
    int intersect(Circle rhs); //determine if this circle intersects with rhs
    int contains(Point2D p); //determine if this circle contains point p
    double perimeter(); //returns perimeter of the circle
    //write a destructor that sets all values to 0
    ~Circle(){
        center.setX(0);
        center.setY(0);
        radius = 0.0;
    }
};

Circle::Circle()
{
    center.setX(0);
    center.setY(0);
    radius = 0.0;
}

Circle::Circle(Point2D c, double r)
{
    center.setX(c.getX());
    center.setY(c.getY());
    radius = r;
}

void Circle::setX(int argx)
{
    center.setX(argx);
}

void Circle::setY(int argy)
{
    center.setY(argy);
}

int Circle::getX()
{
    return center.getX();
}

int Circle::getY()
{
    return center.getY();
}
double Circle::area()
{
    return 3.1416*radius*radius;
}

int Circle::intersect(Circle rhs)
{
    int p, q;
    p = rhs.getX();
    q = rhs.getY();
    double distance = (getX()-p)*(getX()-p) + (getY()-q)*(getY()-q);
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
    double distance = (getX()-p)*(getX()-p) + (getY()-q)*(getY()-q);
    distance = sqrt(distance);
    if(distance <= radius)
    return 1;
    else
    return 0;
}

void Circle::print()
{
    cout << "Center: ";
    cout << getX() << ' ' << getY() << endl;
    cout << "Radius: " << radius;
}

double Circle::perimeter()
{
    return 2*3.1416*radius;
}

class Rectangle
{
    Point2D top_right, bot_left;
    //define two variables that specifies the rectangle in a 2d space
    //the variables should represent: top-right point, bottom-left point
    //consider the rectangle is axes parallel
public:
    Rectangle(){
            top_right.setX(0);
            top_right.setY(0);
            bot_left.setX(0);
            bot_left.setY(0);
    }
    //write a default constructor that initializes all values to 0
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
    //write a constructor that accepts values of all member variables and set the members
    //variables accordingly
    //write get and set methods for this class
    double area(); //returns area of the rectangle
    int intersect(Rectangle rhs); //determine if this rectangle intersects with rhs
    int contains(Point2D p); //determine if this rectangle contains point p
    int inside(Circle c); //determine if this rectangle is completely inside the circle c
    double perimeter(); //returns perimeter of the rectangle
    //write a destructor that sets all values to 0
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
    r = c.getRad();
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

int main(void)
{
    Circle c1(Point2D(2,5), 3), c2(Point2D(1, 1), 5);
    c1.print();
    cout << endl;
    cout << "Area: " << c1.area() << ' ' << "Perimeter: " << c1.perimeter() << endl;
    if(c1.intersect(c2))
    cout << "Intersects\n";
    else
    cout << "Does not\n";
    if(c1.contains(Point2D(100, 100)))
    cout << "Inside\n";
    else
    cout << "Outside\n";
    Rectangle rt1(Point2D(3,3), Point2D(2,2)), rt2(Point2D(5,4), Point2D(1,1));
    cout << rt1.area() << ' ' << rt1.perimeter() << endl;
    Point2D p(4,4);
    if(rt1.contains(p))
    cout << "Inside\n";
    else
    cout << "Outside\n";
    if(rt1.inside(c1))
    cout << "Inside\n";
    else
    cout << "Outside\n";
    if(rt1.intersect(rt2))
    cout << "Inside\n";
    else
    cout << "Outside\n";

    return 0;
    //Demonstrate your circle class which will have a point and a radius
    //Demonstrate your area funciton showing that it successfully prints area of a circle
    //Demonstrate intersect(Circle) function by creating appropriate circles and showing that they intersect
    //Demonstrate contains(Point) function by creating appropriate point and showing that the circle
    //contains the point


    //Demonstrate your Rectangle class
    //Demonstrate your area funciton showing that it successfully prints area of a rectangle
    //Demonstrate intersect(Rectangle) function by creating appropriate rectangle and showing that
    //they intersect
    //Demonstrate contains(Point) function by creating appropriate points and showing that the rectangle
    //contains the point
    //Demonstrate inside(Circle) function by creating appropriate rectangle and circle and showing that
    //a rectange is completely inside a circle


    return 0;
}

