#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;

		cin>>n;
		int A[n];
		for(int i=0;i<n;i++)
			cin>>A[i];
		sort(A,A+n);
		int absolute_sum=INT_MAX;
		int sum=INT_MIN;
		int i=0;
		int j=n-1;
		while(i<j)
		{
			if(A[i]+A[j]==0)
			{
				cout<<"0"<<endl;
				break;
			}
			else if(A[i]+A[j]<0)
			{
				if((0-A[i]-A[j])<absolute_sum)
				{
					absolute_sum=0-A[i]-A[j];
					sum=A[i]+A[j];
				}
				i++;
			}
			else 
			{
				if(A[i]+A[j]<absolute_sum)
				{
					absolute_sum=0-A[i]-A[j];
					sum=A[i]+A[j];
				}
				j--;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}