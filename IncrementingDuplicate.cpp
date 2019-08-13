#include<iostream>
#include<unordered_set>
using namespace std;
void duplicateElementIncrease(int A[],int n)
{
	sort(A,A+n);
	for(int i=n-1;i>=0;i--)
	{
		if(A[i]==A[i-1])
		{
			int j=i+1;
			int k=A[i]+1;
			while(k==A[j])
			{
				k=k+1;
				j=j+1;
			}
			//A[i]=k;
			for(int l=i;l<j-1;l++)
			{
				//cout<<l<<endl;
				A[l]=A[l+1];
			}
			
			A[j-1]=k;
		}
	}
	for(int i=0;i<n;i++)
		cout<<A[i]<<"    ";
	
}
int main()
{
	int arr[6]= {3, 2, 1, 2, 3, 7};
	duplicateElementIncrease(arr,6);
	return 0;
}