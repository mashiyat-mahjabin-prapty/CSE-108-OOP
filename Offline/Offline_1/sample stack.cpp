#include <iostream>
#include <cstdlib>
#define SIZE 100
#define EMPTY -99
using namespace std;

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

class Stack
{
    Array s;
    int size;
    int top;
    // you are not allowed to add any field; you can only add methods
public:
    // your code
    Stack()
    {
    	size = 0;
    	top = 0;
	}
    Stack(int p)
    {
    	size = p;
    	top = 0;
    	s.setLength(p);
	}
	int isFull()
	{
		if(top == SIZE)
		return 1;
		
		return 0;
	}
    void push(int x)
    {
        if(isFull())
        {
            cout << "Stack is full" << endl;
            exit(0);
        }
        s.setElementAt(top++, x);
        // your code
    }
    int isEmpty()
    {
    	if(top == 0)
    	return 1;
    	
    	return 0;
	}
    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty" << endl;
            exit(0);
        }
        return s.getElementAt(--top);
        // your code
    }
    void clone(Stack old)
    {
    	size = old.size;
    	top = old.top;
    	s.setLength(size);
    	for(int i = top-1, j = 0; i >= 0; i--, j++){
    		s.setElementAt(j, old.s.getElementAt(i));
		}
    	//s.clone(old.s);
	}
    // your code
};

class Queue
{
    Array s;
    int size;
    int front;
    int rear;
    // you are not allowed to add any field; you can only add methods
public:
    // your code
    Queue()
    {
    	size = 0;
    	front = 0;
    	rear = 0;
	}
    Queue(int p)
    {
    	size = p;
    	front = 0;
    	rear = 0;
    	s.setLength(p);
	}
    int isFull()
	{
		if(rear == SIZE)
		return 1;
		
		return 0;
	}
	int isEmpty()
    {
    	if(rear == 0)
    	return 1;
    	
    	return 0;
	}
    void enqueue(int x)
    {
        if(isFull())
        {
            cout << "Queue is full" << endl;
            exit(0);
        }
        s.setElementAt(rear++, x);
        // your code
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            exit(0);
        }
        int m = s.getElementAt(front);
        for(int j = 1; j < rear; j++){
        	s.setElementAt(j-1, s.getElementAt(j));
		}
		rear--;
		return m;
        // your code
    }
    void clone(Queue old)
    {
    	size = old.size;
    	rear = old.rear;
    	s.setLength(size);
    	s.clone(old.s);
	}
    // your code
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
    
	Stack s(10); // create a Stack with size 10
    for (int i = 0; i < 5; i++)
    {
        s.push(i+1);
    }
    Stack t; // create an empty Stack
    t.clone(s); // Stack t will be a clone of Stack s
    cout << "Elements of Stack t: " << endl;
    while(!t.isEmpty())
    {
        cout << t.pop() << " " ;
    }
    cout << endl;
    cout << "Elements of Stack s: " << endl;
    while(!s.isEmpty())
    {
        cout << s.pop() << " " ;
    }
    
    cout << endl;
    
    Queue q(10); // create a Queue with size 10
    for (int i = 0; i < 5; i++)
    {
        q.enqueue(i+1);
    }
    Queue r; // create an empty Queue
    r.clone(q); // Queue r will be a clone of Queue q
    cout << "Elements of Queue r: " << endl;
    while(!r.isEmpty())
    {
        cout << r.dequeue() << " " ;
    }
    cout << endl;
    cout << "Elements of Stack q: " << endl;
    while(!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }
    
    cout << endl;
}
