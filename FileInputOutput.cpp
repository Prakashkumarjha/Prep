#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	int InputArray[100];
	int i=0;
	int sizeOfRange,largestElement=0;
	
	int Output[100];
	memset(Output,0,sizeof(Output));
	ifstream input;
	input.open("/Users/prakashjha/Desktop/cleartax.txt");
	if(input.fail())
	{
		cout<<"File not found";
	}
	else
	{

		string a,p;
		int c=0;
		while(input>>a)
		{
			
			if(a[a.length()-1]==',')
			{

				InputArray[i]=stoi(a.substr(0,a.length()-1));
				if(largestElement<InputArray[i])
					largestElement=InputArray[i];
				i++;
				
			}
			else if(c==0)
			{
				c=1;
				InputArray[i]=stoi(a.substr(0,a.length()));
				if(largestElement<InputArray[i])
					largestElement=InputArray[i];
				i++;
				
			}
			else if(c==1)
			{
				sizeOfRange=stoi(a.substr(0,a.length()));
			}
			
			
		}
		input.close(); 
		input.clear(); 
		int end;
		if(largestElement%sizeOfRange==0)
			end=largestElement/sizeOfRange-1;
		else
			end=largestElement/sizeOfRange;

		for(int j=0;j<i;j++)
		{
			if(InputArray[j]%sizeOfRange==0)
				Output[(InputArray[j]/sizeOfRange)-1]+=1;
			else
				Output[(InputArray[j]/sizeOfRange)]+=1;
		}
		ofstream OutputFile;
		OutputFile.open("/Users/prakashjha/Desktop/cleartaxoutput.txt");

		string s;

		for(int j=0;j<=end;j++)
		{
			OutputFile<<sizeOfRange*j+1<<" to "<<sizeOfRange*(j+1)<<" : "<<Output[j]<<endl;
		}
		OutputFile.close(); 
		OutputFile.clear(); 
	}
	return 0;
}