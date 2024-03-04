#include<iostream>
using namespace std;

class Fraction{
	int numerator;
	int denominator;
	public:
		Fraction(){
			numerator = 0;
			denominator = 0;
		}
		Fraction(int i, int j){
			numerator = i;
			denominator = j;
		}
		void setNumerator(int i){
			numerator = i;
		}
		void setDenominator(int j){
			denominator = j;
		}
		int getNumarator(){
			return numerator;
		}
		int getDenominator(){
			return denominator;
		}
		void printFraction() {
			cout << numerator << '/' << denominator << endl;
		}
		Fraction addFraction(Fraction a){
			Fraction p;
			p.numerator = numerator * a.denominator + a.numerator * denominator;
			p.denominator = denominator * a.denominator;
			//p.printFraction();
			return p;
		}	
		Fraction divFraction(int n){
			Fraction p;
			p.numerator = numerator;
			p.denominator = denominator * n;
			//p.printFraction();
			return p;
		}
		Fraction divFraction(Fraction p){
			Fraction q;
			q.numerator = numerator * p.denominator;
			q.denominator = denominator * p.numerator;
			//q.printFraction();
			return q;
		}
		Fraction subFraction(Fraction p){
			Fraction q;
			q.numerator = numerator * p.denominator - p.numerator * denominator;
			q.denominator = denominator * p.denominator;
			//q.printFraction();
			return q;
		}
		Fraction mulFraction(Fraction p){
			Fraction q;
			q.numerator = numerator * p.numerator;
			q.denominator = denominator * p.denominator;
			//q.printFraction();
			return q;
		}
};

class Point{
	Fraction x, y;
	public:
		Point(){
			x.setNumerator(0);
			x.setDenominator(0);
			y.setNumerator(0);
			y.setDenominator(0);	
		}	
		Point(Fraction i, Fraction j){
			x.setNumerator(i.getNumarator());
			x.setDenominator(i.getDenominator());
			y.setNumerator(j.getNumarator());
			y.setDenominator(j.getDenominator());
		}
		void setX(Fraction i){
			x.setNumerator(i.getNumarator());
			x.setDenominator(i.getDenominator());
		}
		void setY(Fraction j){
			y.setNumerator(j.getNumarator());
			y.setDenominator(j.getDenominator());
		}
		Fraction getX(){
			return x;
		}
		Fraction getY(){
			return y;
		}
};

class Line{
	Point start, end;
	public:
		Line(){
			start.setX(Fraction(0,0));
			start.setY(Fraction(0,0));
			end.setX(Fraction(0,0));
			end.setY(Fraction(0,0));
		}
		Line(Point i, Point j){
			start.setX(i.getX());
			start.setY(i.getY());
			end.setX(j.getX());
			end.setY(j.getY());
		}
		Point midPoint(){
			Point p;
			p.setX((start.getX().addFraction(end.getX())));
			p.setX(p.getX().divFraction(2));
			p.setY((start.getY().addFraction(end.getY())));
			p.setY(p.getY().divFraction(2));
			return p;
		}
		int contains(Point p){
			Fraction m, n;
			m = p.getX().subFraction(start.getX());
			n = start.getY().subFraction(end.getY());
			double tec = (m.getNumarator()*n.getNumarator()*1.0) / (m.getDenominator()*n.getDenominator()*1.0);
			m = p.getY().subFraction(start.getY());
			n = start.getX().subFraction(end.getX());
			double rec = (m.getNumarator()*n.getNumarator()*1.0) / (m.getDenominator()*n.getDenominator()*1.0);
			if(tec ==  rec)
			return 1;
			else
			return 0;
		}
		Point intersection(Line l){
			Fraction m1, m2;
			Point p;
			m1 = end.getY().subFraction(start.getY()).divFraction(end.getX().subFraction(start.getX()));
			m1.printFraction();
			m2 = l.end.getY().subFraction(l.start.getY()).divFraction(l.end.getX().subFraction(l.start.getX()));
			m2.printFraction();
			p.setX(start.getX().mulFraction(m1).addFraction(l.start.getY()));
			p.getX().printFraction();
			p.setX(p.getX().subFraction(start.getY().addFraction(l.start.getX().mulFraction(m2))));
			p.getX().printFraction();
			p.setX(p.getX().divFraction(m1.subFraction(m2)));
			p.setY(start.getY().addFraction(p.getX().mulFraction(m1)));
			p.setY(p.getY().subFraction(start.getX().mulFraction(m1)));
			return p;
		}
};

int main()
{
	Fraction f1(2, 5), f2(3, 5), f3;
	Fraction c1(2,3), c2(4,5);
	
	f1.printFraction();
	f2.printFraction();
	
	f3 = f1.addFraction(f2);
	f3.printFraction();
	f3 = f2.divFraction(4);
	f3.printFraction();
	
	Line l1(Point(f1, f2), Point(c1, c2)), l2(Point(Fraction(3,5), Fraction(7,8)), Point(Fraction(1,2), Fraction(3,4)));
	Point q = l1.midPoint();
	Fraction f5, f4;
	f4 = q.getX();
	f5 = q.getY();
	cout << "x co-ordinate of mid-point: ";
	f4.printFraction();
	cout << "y co-ordinate of mid-point: ";
	f5.printFraction();
	int cont = l1.contains(Point(Fraction(2,4), Fraction(5,6)));
	if(cont) cout << "On the line\n";
	else cout << "Not on the line\n";
	Point p = l1.intersection(l2);
	f1 = p.getX();
	f1.printFraction();
	f2 = p.getY();
	f2.printFraction();
	
	return 0;
}
