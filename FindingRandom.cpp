#include<iostream>
using namespace std;
int main()
{
	int A[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int i=n,k=0;
	while(i>0)
	{
		int j=rand()%i+k+1;
		swap(A[k],A[j]);
		i--;
		k++;
	}
	for(int i=0;i<n;i++)
		cout<<A[i]<<endl;
	return 0;
}
