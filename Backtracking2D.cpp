#include<iostream>
#include<climits>

#define n 5
using namespace std;
int minimum=INT_MAX;

bool isSafe(int A[n][n],int x,int y)
{
	if(x>=0 && y>=0 && x<n && y<n && A[x][y])
		return true;
	return false;
}

void numberOfStepRequired(int A[n][n],int i,int j,int current)
{
	if(j==n-1 && i==n-1)
	{
		if(A[i][j]==1 && current<minimum)
		{
			current=current+1;
			minimum=current;
		}
		return ;
	}
	if(isSafe(A,i+1,j))
		numberOfStepRequired(A,i+1,j,current+1);
	if(isSafe(A,i,j+1))
		numberOfStepRequired(A,i,j+1,current+1);
	if(isSafe(A,i-1,j))
		numberOfStepRequired(A,i-1,j,current+1);
	if(isSafe(A,i,j-1))
		numberOfStepRequired(A,i,j-1,current+1);
	return;
	
}
int main()
{
	int arr[5][5]={{1,1,1,0,1},{0,1,1,0,0},{1,1,1,0,1},{0,1,1,1,1},{1,0,1,1,1}};
	if(arr[0][0]==1)
		numberOfStepRequired(arr,0,0,0);

	cout<<minimum<<endl;
	return 0;
}