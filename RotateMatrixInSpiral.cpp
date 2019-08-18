#include<iostream>
using namespace std;
int A[100][100];
int M,N;
void RotateMatrixclockwise()
{
	int R=M,S=N;
	int row=0,coloumn=0,prev,curr;
	while(row<M && coloumn<N)
	{
		if(row+1==M ||coloumn+1==N)
			break;
		prev=A[row+1][coloumn];
		for(int i=coloumn;i<N;i++)
		{
			curr=A[row][i];
			A[row][i]=prev;
			prev=curr;
		}
		row++;
		for(int i=row;i<M;i++)
		{
			curr=A[i][N-1];
			A[i][N-1]=prev;
			prev=curr;
		}
		N--;
		if(coloumn<N)
		{
			for(int i=N-1;i>=coloumn;i--)
			{
				curr=A[M-1][i];
				A[M-1][i]=prev;
				prev=curr;
			}
			M--;
		}
		if(row<N)
		{
			for(int i=M-1;i>=row;i--)
			{
				curr=A[i][coloumn];
				A[i][coloumn]=prev;
				prev=curr;
			}
			coloumn++;
		}
	}

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<S;j++)
		{
			cout<<A[i][j]<<"   ";
		}
		cout<<endl<<endl<<endl;
	}
}


void RotateMatrix90degree()
{
	int row=0,coloumn=0;
	int prev,curr;
	while(row<M && coloumn<N)
	{
		prev=A[N-1][coloumn];
		for(int i=coloumn;i<M;i++)
		{
			curr=A[row][i];
			A[row][i]=prev;
			prev=curr;
		}
		for(int i=row;i<N;i++)
		{
			curr=A[i][M-1];
			A[i][M-1]=prev;
			
		}
	}
} 


int main()
{
	M=4,N=4;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
			cin>>A[i][j];
	}
	    // A[M][N] = { {1,  2,  3,  4}, 
     //    {5,  6,  7,  8}, 
     //    {9,  10, 11, 12}, 
     //    {13, 14, 15, 16}  }; 

        RotateMatrixclockwise();

	return 0;
}