#include<iostream>
using namespace std;
int main()
{
	string s="geeksforgeeks";
	int A[100];
	int k=1;
	for(int i=0;i<s.length();i++)
		A[i]=s[i];
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<s.length();j++)
		{
			if(A[i]-A[j]==k && j>i)
			{
				cout<<s[i]<<" "<<s[j]<<endl;
			}
			else if(A[i]-A[j]==k && j<i)
			{
				cout<<s[j]<<" "<<s[i]<<endl;
			}
		}
		
	}
	cout<<endl;
	
	return 0;
}