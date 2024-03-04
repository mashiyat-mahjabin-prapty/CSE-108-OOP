#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 100
#define EMPTY -99

class Array
{
    int a[SIZE];
    int length;
    // you are not allowed to add any field; you can only add methods
public:
    // your code
    Array()
    {
        length = 0;
    }
    Array(int size)
    {
        length = size;
        for (int i = 0; i < size; i++)
        {
            a[i] = EMPTY;
        }
    }
    Array(int size, int init)
	{
    	length = size;
    	for(int i = 0; i < length; i++)
		{
    		a[i] = init;
		}
	}
	Array(int size, int p[])
	{
		length = size;
		for(int i = 0; i < length; i++)
		{
			a[i] = p[i];
		}
	}
    // your code
    void setLength(int size)
    {
        length = size;
    }
    int getLength()
    {
        return length;
    }
    void setElementAt(int i, int e)
    {
        if(i >= length)
        {
            cout << "Invalid Index" << endl;
            exit(0);
        }
        // your code
    }
    int getElementAt(int i)
    {
        if(i >= length)
        {
            cout << "Invalid Index" << endl;
            exit(0);
        }
        // your code
    }
    void print()
    {
        for(int i =0; i < length; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    // your code
    void clone(Array p)
    {
    	for(int i = 0; i < p.length; i++)
    	{
    		a[i] = p.a[i];
		}
	}
};


int main()
{
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Array a(10, 1); // create an  Array of length 10 and all values are initialized to 1
    Array b(5, x); // create an Array with first 5 elements of given x
    Array c(10); // create an Array of length 10
    c.clone(a); // Array c will be a clone of Array a
    cout << "Elements of Array a: " << endl;
    a.print();
    cout << "Elements of Array b: " << endl;
    b.print();
    cout << "Elements of Array c: " << endl;
    c.print();
    
    return 0;
}
