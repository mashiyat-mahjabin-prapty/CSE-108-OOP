#include<iostream>
#define UNDEFINED 0
#define LINE 1
#define RECTANGLE 2
#define CUBE 3

using namespace std;


class Shape
{
    int type;
public:
	Shape()
	{
		cout << "Constructing shape" << endl;
		this->type = 0;
	}
	
    Shape(int type)
    {
    	cout << "Constructing shape" << endl;
        this->type = type;
        cout<<"In Shape with Type "<<type<<endl;
    }

    virtual int area()
    {
        cout<<"In Base Class, Overload this function in derived class"<<endl;
        return -1;
    }

    virtual int volume()
    {
        cout<<"In Base Class, Overload this function in derived class"<<endl;
        return -1;
    }

    int get_type(){ return type; }
    void set_type(int type){ this->type = type; }
    
    ~Shape()
	{
		cout << "Destructing shape class" << endl;
	}
};


class Line: public Shape
{
public:
    int length;
    Line(int type, int length) : Shape(type)
    {
    	cout << "Constructing line" << endl;
        this->length = length;
        cout<<"In Line with length "<<length<<endl;
    }

    ///override area() and volume()
    int area()
    {
        return 0;
    }

    int volume()
    {
        return 0;
    }
	
	void set_length(int length) { this->length = length; }
	int get_length() { return length; }
    ///setter getter if required
	
	~Line()
	{
		cout << "Destructing line class" << endl;
	}
};

class Rectangle: private Line
{
    int width;
public:
    Rectangle(int type, int length, int width) : Line(type, length)
    {
    	cout << "Constructing rectangle" << endl;
        this->width = width;
        cout<<"In Rectangle with width "<<width<<endl;
    }

    ///override area() and volume()
    int area()
    {
    	int a;
    	a = get_length();
        return a*width;
    }

    int volume()
    {
        return 0;
    }

	void set_width(int width) { this->width = width; }
	void set_length(int length) { Line::set_length(length); }
	int get_width() { return width; }
	int get_length() { Line::get_length(); }
    ///setter getter if required
	
	~Rectangle()
	{
		cout << "Destructing rectangle class" << endl;
	}
};

class Cube: private Rectangle
{
    int height;
public:
    Cube() : Rectangle(0, 0, 0)
    {
    	cout << "Constructing cube" << endl;
        height = 0;
        cout<<"In Rectangle with height "<<height<<endl;
        /// set length and width
    }

    Cube(int type, int length, int width, int height) : Rectangle(type, length, width)
    {
    	cout << "Constructing cube" << endl;
        this->height = height;
        cout<<"In Rectangle with height "<<height<<endl;
    }

    ///override area() and volume()
    int area()
    {
    	int a, b;
    	a = get_length();
    	b = get_width();
        return 2*(a*b+a*height+b*height);
    }

    int volume()
    {
    	int a, b;
    	a = Rectangle::get_length();
    	b = get_width();
        return a*b*height;
    }
	
	~Cube()
	{
		cout << "Destructing cube class" << endl;
	}
    ///setter getter if required

};


int main()
{
    Shape s;
    s.area();
    ///In Base Class, Overload this function in derived class
    s.volume();
    ///In Base Class, Overload this function in derived class

    Line l(LINE, 5);
    ///Implement area and volume function
    cout << "Area: " << l.area() << endl;
    ///Area is 0
    cout << "Volume: " << l.volume() << endl;
    ///Volume is 0

    Rectangle r(RECTANGLE, 5, 2);
    ///Notice that access modifier is private
    cout << "Area: " << r.area() << endl;
    ///Area is 10
    cout << "Volume: " << r.volume() << endl;
    ///Volume is 0

    Cube c(CUBE, 5, 2, 4);
    ///You can not access length due to private modifier in rectangle
    ///write necessary methods in rectangle to access length
    cout << "Area: " << c.area() << endl;
    ///Area is 76
    cout << "Volume: " << c.volume() << endl;
    ///Volume is 40

    ///Demonstration of Virtual Function in Shape
    Shape *s1;
    s1 = &l;
    cout << "Area: " << s1->area() << endl;
    ///Area is 0
    cout << "Volume: " << s1->volume() << endl;
    ///Volume is 0


    Shape* s2;
    s2 = &l;
    cout << "Area: " << s2->area() << endl;
    ///Area is 0
    cout << "Volume: " << s2->volume() << endl;
    ///Volume is 0

    ///write destructor function and observe (by printing something) the order of constructor and destructor call

    return 0;
}
