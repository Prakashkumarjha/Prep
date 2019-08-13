#include<iostream>
using namespace std;
int partition(int A[],int low,int high)
{
	if(low<high)
	{
		int pivot=A[high];
		int i=low-1;
		for(int j=low;j<high;j++)
		{
			if(A[j]<=pivot)
			{
				i++;
				swap(A[i],A[j]);
			}
		}
		
		swap(A[i+1],A[high]);
		return i+1;
	}
	return -1;
}
void Quick_sort(int A[],int low,int high)
{
	if(low<high)
	{
		int pivot=partition(A,low,high);
		Quick_sort(A,low,pivot-1);
		Quick_sort(A,pivot+1,high);
	}
}
int main()
{
	int A[6]={-21 ,  -67  , -37 ,  -18 ,  4  , -65};
	Quick_sort(A,0,5);
	for(int i=0;i<6;i++)
		cout<<A[i]<<"   ";
}