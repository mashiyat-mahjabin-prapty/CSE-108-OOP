#include<iostream>
#include<math.h>
#include<cmath>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

class Vector{

    private:
        int i;
        int j;
        int k;

    public:

        Vector(){
            cout<<"Default Construction"<<endl;
        }

        Vector(int a,int b,int c){
            i=a;
            j=b;
            k=c;
        }
		
		friend Vector& addVector(Vector &a, Vector &b);
		friend double getMagnitude(Vector &a);
		friend void scale(Vector &a, int n);
		friend void printVector(Vector &a);
		
        ~Vector(){
            cout<<"Destructing ("<<i<<","<<j<<","<<k<<")"<<endl;
        }
};

double getMagnitude(Vector &a){

	double d;
	d = a.i*a.i+a.j*a.j+a.k*a.k;
	d = sqrt(d);
    return d;
}


Vector& addVector(Vector &a, Vector &b){
	Vector c;
	c.i = a.i+b.i;
	c.j = a.j+b.j;
	c.k = a.k+b.k;
	return c;
}

void scale(Vector &a, int n){
	a.i = a.i*n;
	a.j = a.j*n;
	a.k = a.k*n;
}


void printVector(Vector &a){
	cout << "value of i: " << a.i << endl;
	cout << "value of j: " << a.j << endl;
	cout << "value of k: " << a.k << endl;
	
}


int main(){

    ///you must be able to explain construct and destructing output sequence
    Vector line1(1,2,3);
    Vector line2(4,5,6);

    cout<<getMagnitude(line1)<<endl;

    printVector(line1);
    Vector &line3=addVector(line1,line2);

    printVector(line1);
    printVector(line3);

    scale(line1,2);
    printVector(line1);
    printVector(line3);



    return 0;
}
