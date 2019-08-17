#include<iostream>
#include<fstream>
#include<map>
using namespace std;
int main()
{
	int A[100];
	int i=0;
	int range,greatest=0;
	
	int B[100];
	memset(B,0,sizeof(B));
	ifstream infile;
	infile.open("/Users/prakashjha/Desktop/cleartax.txt");
	if(infile.fail())
	{
		cout<<"File not found";
	}
	else
	{

		string a,p;
		int c=0;
		while(infile>>a)
		{
			
			if(a[a.length()-1]==',')
			{

				A[i]=stoi(a.substr(0,a.length()-1));
				if(greatest<A[i])
					greatest=A[i];
				i++;
				
			}
			else if(c==0)
			{
				c=1;
				A[i]=stoi(a.substr(0,a.length()));
				if(greatest<A[i])
					greatest=A[i];
				i++;
				
			}
			else if(c==1)
			{
				range=stoi(a.substr(0,a.length()));
			}
			
			
		}
		infile.close(); 
		infile.clear(); 
		int end;
		if(greatest%range==0)
			end=greatest/range-1;
		else
			end=greatest/range;

		for(int j=0;j<i;j++)
		{
			if(A[j]%range==0)
				B[(A[j]/range)-1]+=1;
			else
				B[(A[j]/range)]+=1;
		}
		ofstream ofile;
		ofile.open("/Users/prakashjha/Desktop/cleartaxoutput.txt");

		string s;

		for(int j=0;j<=end;j++)
		{
			ofile<<range*j+1<<" to "<<range*(j+1)<<" : "<<B[j]<<endl;
		}
		infile.close(); 
		infile.clear(); 
	}
	return 0;
}