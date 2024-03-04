#include <iostream>
#include <cstdlib>
using namespace std;

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
