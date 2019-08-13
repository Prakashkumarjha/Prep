#include <iostream>
using namespace std;
long long int noOfWays(long long int n)
{
    long long int table[n+1];
    for(int i=0;i<n+1;i++)
        table[i]=0;
    table[0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            table[j]+=table[j-i];
           
        }
      
    }
    return table[n];
}

int main() {
	int t;
	
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    cout<<noOfWays(n)<<endl;
	}
	return 0;
}