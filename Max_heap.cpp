#include<iostream>
using namespace std;

class Max_heap
{
	int heap_size ;
	int A[100];
	int B[100];
	int p;
	public:
		Max_heap()
		{
		
   		 heap_size = 0; 
   		 p=0;
    //capacity = cap; 
   // harr = new int[cap]; 
		}
		

		int parent(int i){
			return (i-1)/2;
		}
		int  leftchild(int i){
			return 2*i+1;
		}
		int rightchild(int i){
			return 2*i+2;
		}
		void insert(int x)
		{
			A[heap_size]=x;
			heap_size++;
			int i=heap_size-1;
			while(i!=0 && A[i]>A[parent(i)])
			{
				swap(A[i],A[parent(i)]);
				i=parent(i);
			}
		}
		void delete1()
		{

			
			B[p]=A[0];
			swap(A[heap_size-1],A[0]);
			
			p++;
			heap_size--;

			int i=0;
			while(leftchild(i)<heap_size && rightchild(i)<heap_size && A[i]<max(A[leftchild(i)],A[rightchild(i)]))
			{
				if(A[leftchild(i)]>A[rightchild(i)])
				{
					swap(A[i],A[leftchild(i)]);
					i=leftchild(i);

				}
				else
				{
					swap(A[i],A[rightchild(i)]);
					i=rightchild(i);
					//cout<<i<<endl;
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
			int l=leftchild(i);
			int r=rightchild(i);
			if(l>=heap_size && r>=heap_size)
				return;
			int small=i;
			if(A[l]>A[r] && A[l]>A[i])
			{
				swap(A[l],A[i]);
				small=l;
			}
			else
			{
				swap(A[r],A[i]);
				small=r;

			}
			Maxheapify(small);	
		}


		void print()
		{
			for(int i=0;i<heap_size;i++)
				cout<<A[i]<<"    ";
		}
		void print2()
		{
			for(int i=0;i<p;i++)
				cout<<B[i]<<"    ";
		}
};
int main()
{
	
	Max_heap m;
	m.insert(5);
	m.insert(7);
	m.insert(8);
	m.insert(9);
	m.insert(6);
	m.Maxheapify(1);
	//m.delete1();
	//m.delete1();
	//m.delete1();
	//m.delete1();
	//m.delete1();
	//m.Maxheapify(0);
	m.print();

	return 0;
}