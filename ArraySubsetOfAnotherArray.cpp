#include<iostream>
#include<unordered_set>
#include<iterator>
using namespace std;

bool SubsetofArray(int A[],int m, int B[],int n)
{
	unordered_set <int> map1;
	//map<int, int> ::iterator it ;

	if(m>n)
	{
		for(int i=0;i<m;i++)
		{
			map1.insert(A[i]);
		}
		for(int j=0;j<n;j++)
		{
			if(map1.find(B[j])==map1.end() )
				return false;
		}
		
		return true;
	}
	else 
	{
		for(int i=0;i<n;i++)
		{
			map1.insert(B[i]);
		}
		for(int j=0;j<m;j++)
		{
			if(map1.find(A[j])==map1.end())
				return false;
		}
		return true;
	}
}

int main()
{
	int A[]={11, 1, 13, 21, 3, 7};
	int m=6;
	int B[]={11, 13, 7, 1};
	int n=4;
	cout<<SubsetofArray(A,m,B,n);
	return 0;
}