#include<iostream>
using namespace std;
int summax=0;
void sum1(int A[],int n,int i, int sum)
{
	if(i==n-2||i==n-1)
	{
		sum=sum+A[i];
		if(summax<sum)
			summax=sum;
	}
	if(i+2<n)
		sum1(A,n,i+2,sum+A[i]);
	if(i+3<n)
		sum1(A,n,i+3,sum+A[i]);
}
int main()
{
	int A[]={5,5,10,100,10,5};
	sum1(A,6,0,0);
	sum1(A,6,1,0);
	cout<<summax<<endl;
	return 0;
}