#include<iostream>
using namespace std;
int minimumAsciiValueSumAfterRemovingOneCharacter(string s, int len)
{
	int countOfCharacter[26]={};
	int sum=0;
	for(int i=0;i<len;i++)
	{
		countOfCharacter[s[i]-'a']+=1;
		sum+=s[i];
	}
	int maximumSum=0;
	for(int i=0;i<26;i++)
	{
		if(maximumSum<countOfCharacter[i]*('a'+i))
			maximumSum=countOfCharacter[i]*('a'+i);
	}
	return sum-maximumSum;
}
int main()
{
	string s;
	cin>>s;
	int len=s.length();
	int minimumAsciiValueSum = minimumAsciiValueSumAfterRemovingOneCharacter(s,  len);
	cout<<minimumAsciiValueSum<<endl;
	return 0;
}