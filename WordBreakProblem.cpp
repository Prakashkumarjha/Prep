#include<iostream>
using namespace std;
bool dictionaryContains(string str)
{
	string dictionary[]={"mobile","samsung","sam","sung", 
                            "man","mango","icecream","and", 
                             "go","i","like","ice","cream"};
    int size= sizeof(dictionary)/sizeof(dictionary[0]);
    for(int i=0;i<size;i++)
    {
    	if(dictionary[i].compare(str)==0)
    	{
    		//cout<<str<<".   "<<size<<endl;
    		return true;
    	}
    }
    return false;

}
bool wordBreak(string str)
{
	int size=str.size();
	
	if(size==0)
		return true;
	for(int i=1;i<=size;i++)
	{
		//cout<<str<<".     "<<str.substr(i,size-i)<<endl;
		if(dictionaryContains(str.substr(0,i)) && wordBreak(str.substr(i,size-i)))
			return true;
	}
	return false;
}
bool wordBreakDp(string str)
{
	int size=str.size();
	if(size==0)
		return true;

	bool dp[size+1];

	for(int i=0;i<=size;i++)
		dp[i]=false;

	for(int i=1;i<=size;i++)
	{
		if(dp[i]==false && dictionaryContains(str.substr(0,i)))
			dp[i]=true;
		
		if(dp[i]==true)
		{
			if(i==size)
			return true;

			for(int j=i+1;j<=size;j++)
			{
				if(dp[j]==false && dictionaryContains(str.substr(i,j-i)))
					dp[j]=true;
				if(j==size && dp[j]==true)
					return true;
			}
		}
	}
	return false;
}
int main()
{
	wordBreakDp("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
    // wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
    // wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
    // wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
    // wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
    // wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
	return 0;
}


