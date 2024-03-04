#include<iostream>
using namespace std;

class Setter{
	int i;
	public:
		Stack setVal(Stack s, int value){
			int cnt = 0;
			while(!s.isEmpty()){
				s.pop();
				cnt++;
			}
			while(cnt--){
				s.push(value);
			}
			return s;
		};
		Queue setVal(Queue q, int value){
			int cnt = 0;
			while(!q.isEmpty()){
				q.dequeue();
				cnt++;
			}
			while(cnt--){
				q.enqueue(value);
			}
			return q;
		};
};
