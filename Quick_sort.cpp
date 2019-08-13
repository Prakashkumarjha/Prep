#include<iostream>
using namespace std;

void swap(int a, int b)  
{  
    int t = a;  
    a = b;  
    b = t;  
} 

int partition(int A[],int low, int high)
{
	
	int pivot =A[high];
	//cout<<A[high]<<endl;
	int i=low-1;
	for(int j=0;j<high;j++)
	{
		if(A[j]<=pivot)
		{
			i++;
			//cout<<i<<endl;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[high]);
	return (i+1);
	
}

void quick_sort(int A[],int low ,int high)
{
	if(high>low)
	{
		int pi=partition(A,low,high);
		quick_sort(A,low,pi-1);
		quick_sort(A,pi+1,high);
	}
}


int main()
{
	int A[6]={21 ,67 ,37, 18 ,4, 65};
	//selection_sort(A,6);
	//insertion_sort(A,6);
	quick_sort(A,0,5);
	for(int i=0;i<6;i++)
		cout<<A[i]<<"   ";
}