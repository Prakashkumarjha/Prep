#include<iostream>
using namespace std;
#define MAX 1000
class Queue
{
	int A[MAX];
	int front=0;
	int rear=-1;
	public:
		bool enqueue(int x)
		{
			if(rear>MAX)
				return false;
		
			rear++;
			A[rear]=x;
			
			return true;
		}
		int dequeue()
		{
			//cout<<front<<".    "<<rear<<endl;
			if(front>rear)
				return 0;
			front++;
			return A[front];
		}
		int rear1()
		{
			if(front>rear)
				return 0;
			return A[rear];
		}
		int front1()
		{
			if(front>rear)
				return 0;
			//cout<<front;
			return A[front];
		}
		bool empty()
		{
			if(front>rear)
				return true;
			return false;
		}
};
int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(3);
	q.enqueue(8);
	cout<<q.front1()<<endl;
	cout<<q.rear1()<<endl;
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	cout<<q.empty()<<endl;
	q.dequeue();
	cout<<q.empty()<<endl;
	cout<<q.front1()<<endl;
	cout<<q.rear1()<<endl;

}