#include<iostream>
using namespace std;

void patternWithoutLoop(int n)
{
	if(n>0)
	{
		cout<<n<<endl;
		patternWithoutLoop(n-5);
	}
	cout<<n<<endl;
	
}
int main()
{
	patternWithoutLoop(16);
	patternWithoutLoop(10);
	return 0;
}