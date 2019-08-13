#include<iostream>
using namespace std;
class Max_Heap
{
	int heap_size;
	int A[100];
	public:
		int parent(int i)
		{
			return (i-1)/2;
		}

		int leftchild(int i)
		{
			return 2*i+1;
		}
		
		int rightchild(int i)
		{
			return 2*i+2;
		}

		void insert(int x)
		{
			A[heap_size]=x;
			heap_size++;
			int i=heap_size-1;
			while(A[i]>A[parent(i)])
			{
				swap(A[i],A[parent(i)]);
				i=parent(i);
			}
		}

		void deleteTop()
		{
			swap(A[0],A[heap_size-1]);
			heap_size=heap_size-1;
			int i=0;
			while(leftchild(i)<heap_size && rightchild(i)<heap_size && A[i]<max(A[leftchild(i)],A[rightchild(i)]))
			{
				if(A[rightchild(i)]<A[leftchild(i)])
				{
					swap(A[i],A[leftchild(i)]);
					i=leftchild(i);
				}
				else if(A[rightchild(i)]>A[leftchild(i)])
				{
					swap(A[i],A[rightchild(i)]);
					i=rightchild(i);
				}
			}
			if(rightchild(i)==heap_size && A[i]<A[leftchild(i)])
			{
					swap(A[i],A[leftchild(i)]);
					i=leftchild(i);
			}
		}

		void Maxheapify(int i)
		{
			int largest=i;
			int l=leftchild(i);
			int r=rightchild(i);
			if(l<heap_size && A[i]<A[l])
				largest=l;
			if(r<heap_size && A[largest]<A[r])
				largest=r;
			if(largest!=i)
			{
				swap(A[i],A[largest]);
				Maxheapify(largest);
			}
		}

		void print()
		{
			for(int i=0;i<heap_size;i++)
				cout<<A[i]<<"    ";
		}
};

int main()
{
	Max_Heap m;
	m.insert(5);
	m.print();
	cout<<endl;
	m.insert(7);
	m.print();
	cout<<endl;
	m.insert(8);
	m.print();
	cout<<endl;
	m.insert(6);
	m.print();
	cout<<endl;
	m.insert(9);
	m.print();
	cout<<endl;
	//m.deleteTop();
	//m.deleteTop();
	//m.print();
	return 0;
}
