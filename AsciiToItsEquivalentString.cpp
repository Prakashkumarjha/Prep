#include<iostream>
using namespace std;

void AsciiToLine(string s, int len)
{
	int a=-1;
	for(int i=0;i<len;i++)
	{
		string p(1,s[i]);
		if(a==-1)
			a=stoi(p);
		else
			a=a*10+stoi(p);
		if(a>31 && a<123)
		{
			char c=a;
			cout<<c;
			a=-1;
		}
	}
	cout<<endl;
}

int main()
{
	string s;
	cin>>s;
	int len=s.length();
	AsciiToLine(s,len);
	return 0;
}