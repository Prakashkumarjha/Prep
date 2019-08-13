#include<iostream>
using namespace std;
void merge(int A[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for (int i=0;i<n1;i++)
		L[i]=A[l+i];
	for (int j=0;j<n2;j++)
		R[j]=A[m+1+j];
	
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
		

		A[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		
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
	merge_sort(A,0,5);
	for(int i=0;i<6;i++)
		cout<<A[i]<<"   ";
}