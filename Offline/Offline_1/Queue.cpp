#include <iostream>
#include <cstdlib>
using namespace std;

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

