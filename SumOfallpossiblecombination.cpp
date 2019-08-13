#include<iostream>
using namespace std;
void allPossibleCombination(int n,int i,int sum)
{
	if(i==n+1)
	{
		if(sum>0)
			cout<<sum<<endl;
		return;
	}
	allPossibleCombination(n,i+1,sum);	
	allPossibleCombination(n,i+1,sum+i);
}
int main()
{
	int n=3;
	allPossibleCombination(n,1,0);
	return 0;
}