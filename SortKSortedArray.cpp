#include<iostream>
using namespace std;
void minHeapify(int A[],int n,int i)
{
	int l=(2*i)+1;
	int r=(2*i)+2;
	int small=i;
	if(l<n && A[l]<A[i])
		small=l;
	if(r<n && A[small]>A[r])
		small=r;
	if(i!=small)
	{
		swap(A[i],A[small]);
		minHeapify(A,n,small);
	}
}

void buildHeap(int arr[], int n) 
{ 
   
    int startIdx = (n / 2) - 1; 
  
  
    for (int i = startIdx; i >= 0; i--) { 
        minHeapify(arr, n, i); 
    } 
} 

int main()
{
	int A[]={6, 5, 3, 2, 8, 10, 9};
	int n=7;
	int k=3;
	int l=k+1;
	int B[n];
	for(int i=0;i<n-k;i++)
	{
		for(int j=i;j<i+l;j++)
		{
			B[j-i]=A[j];
			//cout<<B[j-i]<<endl;
		}
		
		buildHeap(B,l);
		if(i==n-k-1)
			sort(B,B+l);
		for(int j=0;j<l;j++)
			A[i+j]=B[j];

		
	}

	for(int i=0;i<n;i++)
		cout<<A[i]<<endl;

	return 0;
}