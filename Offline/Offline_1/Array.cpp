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
        a[i] = e;
        // your code
    }
    int getElementAt(int i)
    {
        if(i >= length)
        {
            cout << "Invalid Index" << endl;
            exit(0);
        }
        return a[i];
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
    void clone(Array p)
    {
    	for(int i = 0; i < p.length; i++)
    	{
    		a[i] = p.a[i];
		}
	}
    // your code
};
