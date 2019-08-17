#include<iostream>
#include<stack>
using namespace std;
int Arr[10];

void stockspan1(int A[] ,int n)
{
	int Ans[n];
	stack<int>s;
	s.push(0);
	Ans[0]=1;
	for(int i=1;i<n;i++)
	{
		while(!s.empty() && A[s.top()]<=A[i])
			s.pop();
		Ans[i]=(s.empty())?(i+1):(i-s.top());
		s.push(i);
	}
	for(int i=0;i<n;i++)
		cout<<Ans[i]<<"   ";

}
void stockspan(int A[], int n )
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		j=i-1;
		while(j>0 && A[i]>=A[j])
		{
			Arr[i]+=1;
			j--;

		}
		Arr[i]+=1;
	}

	for(int i=0;i<n;i++)
		cout<<Arr[i]<<"   ";
}
int main()
{
	int A[7]={100, 80, 60, 70, 60, 75, 85};
	int n=7;
	stockspan1(A,n);

	return 0;	
}