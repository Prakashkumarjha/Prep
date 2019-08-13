#include <iostream>
using namespace std;
int trappingRainWater(int A[],int n)
{
    int sum=0;
    int L[n];
    int R[n];
    L[0]=A[0];
    for(int i=1;i<n;i++)
    {
        L[i]=max(L[i-1],A[i]);
    }
    R[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
        R[i]=max(R[i+1],A[i]);
    
    for(int j=0;j<n;j++)
    {
        sum=sum+min(R[j],L[j])-A[j];
    }
    return sum;
}
int main() {
	int t;
	int n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int A[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>A[i];
	    }
	    cout<<trappingRainWater(A,n)<<endl;
	}
	return 0;
}