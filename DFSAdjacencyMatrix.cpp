#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int vertex;
int A[105][105];
int visited[105];
void DFS()
{
	if(s.empty())
		return;
	int i=s.top();
	//cout<<i<<"-->";
	int j=i;
	while(j<vertex && !(A[i][j]==1 && visited[j]!=1))
	{
		j++;
		if(j<vertex && A[i][j]==1 && visited[j]!=1)
		{
			cout<<j<<"-->";
			s.push(j);
			visited[j]=1;
			break;
		}
	}
	if(j==vertex)
		s.pop();
	DFS();	
	
}
int main()
{
	vertex=5;
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<vertex;j++)
		{
			cin>>A[i][j];
		}
	}
	for(int i=0;i<vertex;i++)
		visited[i]=0;
	s.push(0);
	cout<<0<<"-->";
	visited[0]=1;
	DFS();
	return 0;
}