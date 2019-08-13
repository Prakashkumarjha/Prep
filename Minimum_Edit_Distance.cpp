#include<iostream>
using namespace std;
int minedit(string s1,string s2,int m,int n)
{
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(s1[m-1]==s2[n-1])
		return minedit(s1,s2,m-1,n-1);
	else
		return 1+min(min(minedit(s1,s2,m,n-1),minedit(s1,s2,m-1,n)),minedit(s1,s2,m-1,n-1));
}

int mineditdp(string s1,string s2,int m,int n)
{
	int A[m][n];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0)
				A[i][j]=j;
			else if(j==0)
				A[i][j]=i;
			else if(A[i-1]==A[j-1])
				A[i][j]=A[i-1][j-1];
			else
				A[i][j]=1+min(min(A[i-1][j],A[i][j-1]),A[i-1][j-1]);	
		}
	}
	return A[m][n];
}
int main()
{
	string str1="GeeksForGeeks";
	string str2="Geeps";
	cout<<mineditdp(str1,str2,str1.length(),str2.length())<<endl;

}