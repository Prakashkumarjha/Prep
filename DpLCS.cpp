#include<iostream>
#include<map>

using namespace std;
map <string,int> m;
class Dp
{
	public:
		void subsequence(string input,string output,int index)
		{
			if(index==input.length())
			{
				cout<<output<<endl;
				return;
			}
			string tmp=output+input[index];
			subsequence(input,output,index+1);
			subsequence(input,tmp,index+1);	
		}
		void commonSubSequence(string input,string output,int index,string input2,string output2,int index2)
		{
			if(index==input.length() )
			{
				//if(output==output2)
				//	cout<<output<<endl;
				return;
			}
			if( index2==input2.length())
			{
				if(output==output2)
					m.insert(pair<string,int>(output,output.length()));
					//cout<<output<<endl;
				return;
			}
			//if(output!="" && output==output2)
					//cout<<output<<endl;
			string tmp=output+input[index];
			
			string tmp2=output2+input2[index2];
			cout<<tmp2<<endl;
			commonSubSequence(input,output,index+1,input2,output2,index2+1);
			commonSubSequence(input,output,index+1,input2,tmp2,index2+1);
			//subsequence(input2,output2,index2+1);
			commonSubSequence(input,tmp,index+1,input2,tmp2,index2+1);
			commonSubSequence(input,tmp,index+1,input2,output2,index2+1);
			//subsequence(input2,tmp2,index2+1);	
		}
		string LCSLength(string X, string Y, int m, int n )
		{
			string T[m][n];
			for (int i = 0; i < m; i++)
  				for (int j = 0; j < n; j++)
    				T[i][j] = {};
			//string T[m][n]={{},{},{},{},{}};
	
			for(int i=0;i<m;i++)
			{
				if(X[i]==Y[0])
					T[i][0]=X[i];

			}
			for(int i=0;i<n;i++)
			{
				if(Y[n]==X[m])
					T[0][i]=Y[n];
			}

			for (int i=0;i<m;i++)
			{
				for (int j=0;j<n;j++)
				{
					if(X[m]==Y[n])
						T[m][n]=T[m-1][n-1]+X[m];
					else
						T[m][n]=max(T[m-1][n],T[m][n-1]);
				}
			}
			return T[m-1][n-1];
		}

};
int main()
{

	Dp p;
	
	p.LCSLength("ABCBDAB","BDCABA",7,6);
	//p.commonSubSequence("ABCD","",0,"BCD","",0);
	//cout<<map.key("BC");
}