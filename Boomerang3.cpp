#include<iostream>
#include<fstream>
using namespace std;
void countwords()
{
	ifstream fin;
	fin.open("/Users/prakashjha/Desktop/myfile.txt");
	char word[30];
	int count=0;
	while(!fin.eof())
	{
		fin>>word;
		count++;
	}
	cout<<"Number of words in file are "<<count-1;
	fin.close();
	
}
int main()
{

	countwords();
	
	return 0;
}