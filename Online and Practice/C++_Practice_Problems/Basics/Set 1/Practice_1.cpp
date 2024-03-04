#include<iostream>
using namespace std;

class Circle{
    int x, y, radius;
public:
    Circle(){
        x = 0;
        y = 0; 
        radius = 0;
    }
    Circle(int a, int b, int c){
        x = a;
        y = b;
        radius = c;
    }
    void setX(int a){x = a;}
    void setY(int b){y = b;}
    void setRadius(int c){radius = c;}
    int getX(){return x;}
    int getY(){return y;}
    int getRadius(){return radius;}
}    

class Rectangle{
    int x1, y1, x2, y2, x3, y3, x4, y4;
public:
    Rectangle(){
        x1=y1=x2=y2=x3=y3=x4=y4=0;
    }
    Rectangle(int a, int b, int c, int d, int e, int f, int g, int h){
        x1 = a; y1 = b; x2 = c; y2 = d; x3 = e; y3 = f; x4 = g; y4 = h; 
    }
    void setValues(int a, int b, int c, int d, int e, int f, int g, int h){
        x1 = a; y1 = b; x2 = c; y2 = d; x3 = e; y3 = f; x4 = g; y4 = h; 
    }
    int isInscribed(Circle c){
        double dis1, dis2, dis3, dis4;
        dis1 = abs(())
    }
}

int main()
{
    int a, b, c, d, e, f, g, h;
    Circle cir;
    Rectangle rec;
    cin >> a >> b >> c;
    cir.setX(a);
    cir.setY(b);
    cir.setRadius(c);
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    rec.setValues(a,b,c,d,e,f,g,h);

}

