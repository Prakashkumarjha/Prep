#include<iostream>
using namespace std;
int c=0;
int longestCommonSubsequence(int A[],int n,int i,int count, int lastincluded)
{
	if(i==n)
	{

		if(c<count)
			c=count;
		return c;
	}
	if(lastincluded==-10000)
	{
		longestCommonSubsequence(A,n,i+1,count+1,A[i]);
		longestCommonSubsequence(A,n,i+1,count,lastincluded);
	}
	else if(A[i]>lastincluded)
	{
		longestCommonSubsequence(A,n,i+1,count+1,A[i]);
		longestCommonSubsequence(A,n,i+1,count,lastincluded);
	}
	else
		longestCommonSubsequence(A,n,i+1,count,lastincluded);
	return c;
}
void longestincreasingsubsequence(int A[],int n)
{
	int B[n];
	for(int i=0;i<n;i++)
		B[i]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(A[i]>A[j])
				B[i]=max(B[i],B[j]+1);
		}
	}
	int largest=B[0];
	for(int i=0;i<n;i++)
	{
		if(largest<B[i])
			largest=B[i];
	}
	cout<<largest<<endl;
}
int main()
{
	int arr[] = {3, 4, -1, 0, 6, 2,3};
	//.cout<<longestCommonSubsequence(arr, 7,0,0,-10000)<<endl;
	longestincreasingsubsequence(arr,7);

}