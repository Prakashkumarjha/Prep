#include<iostream>
using namespace std;
void selection_sort(int A[],int n)
{
	int small=0;
	int k=0;
	for(int i=0;i<n;i++)
	{
		k=i;
		small=A[i];
		for (int j=i;j<n;j++)
		{
			if(A[j]<small)
			{
				k=j;
				small=A[j];
			}
		}
		swap(A[i],A[k]);
	}
}
void bubble_sort(int A[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(A[j+1]<A[j])
				swap(A[j+1],A[j]);
		}
	}
}
void insertion_sort(int A[],int n)
{
	for (int i=1;i<n;i++)
	{
		int j=i;
		while(j>0 && A[j]<A[j-1])
		{
			swap(A[j-1],A[j]);
			j--;
		}
	} 
}
void merge(int A[],int l,int m,int r)
{
	cout<<l<<".  "<<r<<endl;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1];
	int R[n2];
	for (int i=0;i<n1;i++)
		L[i]=A[l+i];
	for (int j=0;j<n2;j++)
		R[j]=A[m+l+j];
	
	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2)
	{

		if(L[i]<R[j])
		{

			A[k]=L[i];
			i++;
			
		}
		else
		{
			A[k]=R[j];
			j++;
			
		}
		k++;
	}
	while(i<n1)
	{
		//cout<<i<<endl;

		A[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		//cout<<"I am here1"<<endl;
		A[k]=R[j];
		j++;
		k++;
	}

}



void merge_sort(int A[],int l,int n)
{
	if(l<n)
	{

	
		int mid=l+(n-l)/2;
		merge_sort(A,l,mid);
		merge_sort(A,mid+1,n);
		merge(A,l,mid,n);
	}
}
int main()
{
	int A[6]={5,3,6,2,4,7};
	//selection_sort(A,6);
	//insertion_sort(A,6);
	quick_sort(A,0,5);
	for(int i=0;i<6;i++)
		cout<<A[i]<<"   ";
}