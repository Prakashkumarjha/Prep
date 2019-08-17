#include<iostream>
#include<deque>
using namespace std;
void findMinInWindow(int A[], int n, int k)
{
	deque<int > dq;
	for(int i=0;i<k;i++)
	{
		while(!dq.empty() && A[i]<A[dq.back()])
			dq.pop_back();
		dq.push_back(i);
		
	}
	for(int i=k;i<n;i++)
	{
		cout<<A[dq.front()]<<"  ";
		while(!dq.empty() && dq.front()<=i-k)
		{
		//	cout<<i<<".  Hi"<<endl;
			dq.pop_front();
		}
		while(!dq.empty() && A[i]<=A[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	cout<<A[dq.front()]<<"  ";
}
int main()
{
	int A[]={1,3,2,5,6,4,2};
	findMinInWindow(A,7,3);
	return 0;
}