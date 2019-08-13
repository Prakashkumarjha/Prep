#include<iostream>
#include<map>
using namespace std;
bool AnagramOrNot(string s1,string s2)
{
	int n=s1.length();
	int m=s2.length();
	if(n!=m)
		return false;
	map<char,int> ma;
	for(int i=0;i<n;i++)
	{
		if(ma.find(s1[i])==ma.end())
			ma[s1[i]]=1;
		else
			ma[s1[i]]=ma[s1[i]]+1;
	}
	for(int j=0;j<m;j++)
	{
		if(ma.find(s2[j])==ma.end()|| ma[s2[j]]==0)
			return false;
		else
			ma[s2[j]]-=1;
	}
	return true;
}

int main()
{
	int t,n;

	cin>>t;
	while(t--)
	{
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		
		int visited[n],count;
		int A[n];
		for(int i=0;i<n;i++)
			visited[i]=0;
		for(int i=0;i<n-1;i++)
		{
			count=1;
			int j=i+1;
			while(j<n)
			{
				if(visited[j]!=1 && AnagramOrNot(s[i],s[j]))
				{
					//cout<<s[i]<<"   "<<s[j];
					count+=1; 
					visited[j]=1;
				}
				j=j+1;
			}
			if(visited[i]!=1 && count>1)
			{
				A[p]=count;
				p+=1;
			}
		}
		cout<<endl;
		
	}
	return 0;
}