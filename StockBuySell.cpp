#include<iostream>
using namespace std;
int maxprofit=0;
void totalProfit(int A[], int n, bool b, int i, int profit, int buy)
{
	if(i==n)
	{
		if(maxprofit<profit)
			maxprofit=profit;
		return;
	}

	if(b)
	{
		totalProfit(A,n,0,i+1,profit+A[i]-buy, 0);
		totalProfit(A,n,b,i+1,profit, buy);
	}
	else
	{
		totalProfit(A,n,1,i+1,profit, A[i]);
		totalProfit(A,n,b,i+1,profit, 0);
	}

}

int totalProfit1(int A[], int n , int profit1 )
{
	int i=0;
	bool b=0;
	int buy=0;
	while(i<n)
	{

		if(b==0 && A[i]>A[i+1])
		{
			i++;
		}
		else if(b==0 && A[i]<A[i+1])
		{
			buy=A[i];
			i++;
			b=1;
		}
		else if(b==1 && A[i]<A[i+1])
		{
			i++;
		}
		else if(b==1 && A[i]>A[i+1])
		{
			profit1+=A[i]-buy;
			i++;
			buy=0;
			b=0;
		}


	}
	return profit1;

}
int main()
{
	int A[7]={100,180,260,310,40,535,695};
	int n=7;
	totalProfit(A,n,0,0,0,0);
	cout<<maxprofit<<endl;

	cout<<totalProfit1(A, n, 0)<<endl;
}