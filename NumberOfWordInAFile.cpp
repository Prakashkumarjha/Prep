#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	// ifstream infile;
	// infile.open("/Users/prakashjha/Desktop/myfile.txt");
	// string s;
	// int numberOfWords=0;
	int numberOfLines=0;
	// while(infile>>s)
	// {
	// 	numberOfWords+=1;
	// }
	// infile.close();
	// infile.clear();
	ifstream infile1;
	int numberOfWordsInSecondLine=1;
	infile1.open("/Users/prakashjha/Desktop/myfile.txt");
	string s1;
	while(getline(infile1, s1))
	{
		numberOfLines+=1;
		if(numberOfLines==2)
		{
			int i=0;
			//cout<<s1<<endl;
			//char s=' ';
			while(i<s1.length())
			{
				if(s1[i]==' ')
					numberOfWordsInSecondLine+=1;
				i++;
			}
			break;
		}
		
	}
	infile1.close();
	infile1.clear();
	//cout<<"Number of Words in File :-"<<numberOfWords<<"Number of Lines in File :-"<<numberOfLines<<endl;
	cout<<"Number of Words in 2nd line of File :-"<<numberOfWordsInSecondLine<<endl;
}
