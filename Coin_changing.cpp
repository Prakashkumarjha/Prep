#include<iostream>
using namespace std;


void coin_changing_problem(int S[],int m,int N,int sum,int &count)
{

	if(sum>N || m==0)
		return;
	if(sum==N)
	{
		count=count+1;
		return ;
	}
	coin_changing_problem(S,m,N,sum+S[m-1],count);
	coin_changing_problem(S,m-1,N,sum,count);
}

int coin_changing(int S[],int m, int N)
{
	//sort(S,S+m);
	int A[m][N+1];
	for(int i=1;i<=N;i++)
	{
		if(i%S[0]==0)
			A[0][i]=i/S[0];
		else
			A[0][i]=0;
		//cout<<"A["<<"0"<<"]["<<i<<"]:-"<<A[0][i]<<endl;
	}
	for(int i=0;i<m;i++)
	{
		//cout<<"A["<<i<<"]["<<"0"<<"]:-"<<A[i][0]<<endl;
		A[i][0]=0;
	}
	
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(S[i]>j)
			{

				A[i][j]=A[i-1][j];
				//cout<<"A["<<i<<"]["<<j<<"]:-"<<A[i][j]<<endl;
			}
			else
			{
				if(A[i-1][j]>A[i][j-S[i]]+1)
				{
					A[i][j]=A[i][j-S[i]]+1;
					//cout<<"A["<<i<<"]["<<j<<"]:-"<<A[i][j]<<endl;
				}
				else
				{
					
					A[i][j]=A[i-1][j];
					//cout<<"A["<<i<<"]["<<j<<"]:-"<<A[i][j]<<endl;
				}
			}
		}
	}
	
	return A[m-1][N];
}

int main()
{
	int S[4]={1,5,6,8};
	int count=0;
	
	//coin_changing_problem(S,4,11,0,count);
	cout<<coin_changing(S,4,11)<<endl;

}