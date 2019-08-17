#include<iostream>
using namespace std;
bool A[4][3];
bool I[4];
bool J[3];
void M()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(A[i][j]==1)
			{
				 I[i]=1;
				 J[j]=1;
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		if(I[i])
		{
			for(int j=0;j<3;j++)
			{
				A[i][j]=1;
			}
		}
	}
	for(int j=0;j<3;j++)
	{
		if(J[j])
		{
			for(int i=0;i<4;i++)
			{
				A[i][j]=1;
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
			cout<<A[i][j]<<"  ";
		cout<<endl;
	}
}
int main()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
			cin>>A[i][j];
	}
	M();



	return 0;
}