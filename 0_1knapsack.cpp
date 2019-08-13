#include<iostream>
using namespace std;
int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
int knapsack(int wt[],int val[],int n,int W)
{
	int A[n+1][W+1];
	
	for(int i=0;i<=n;i++)
	{
		
		for(int j=0;j<=W;j++)
		{
			if(i==0||j==0)
			{
				//cout<<"hi I am here"<<endl;
				A[i][j]=0;
			}
			else if(j<wt[i])
				A[i][j]=A[i-1][j];
			else
				A[i][j]=max(val[i]+A[i-1][j-wt[i]],A[i-1][j]);
		}
	}
	//cout<<n<<endl;
	return A[n][W];

}
int main()
{
	int val[] = {60, 100, 120}; 
    int wt[]  = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    cout<< knapsack( wt, val, n,W); 
    return 0; 
}