#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
int visited[105];
vector<int> A[105];
queue<int>q;
stack<int> s;
int vertex;
int C[100][100];
void addEdge(int u,int v)
{
	A[u].push_back(v);
}
void BFS()
{
	if(q.empty())
		return;
	int i=q.front();
	q.pop();
	for(int j=0;j<A[i].size();j++)
	{
		//cout<<A[i][j]<<"  ";
		if(!visited[A[i][j]])
		{
			//cout<<A[i][j]<<" ";
			visited[A[i][j]]=1;
			q.push(A[i][j]);
		}
	}
	BFS();
}

void DFS()
{
	if(s.empty())
		return;
	int i=s.top();
	int j=0;
	for(j=0;j<A[i].size();j++)
	{
		if(!visited[A[i][j]])
		{
			visited[A[i][j]]=1;
			s.push(A[i][j]);
			break;
		}
	}
	if(j==A[i].size())
		s.pop();
	DFS();
}

int main()
{
	cin>>vertex;
	int edge;
	cin>>edge;
	int u,v;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		addEdge(u,v);
	}
	//  for(int i=0;i<vertex;i++)
	//  {
	//  	for(int j=0;j<vertex;j++)
	//  		visited[j]=0;
	// 	q.push(i);
	// 	visited[i]=1;
	// 	BFS();
	// 	for(int k=0;k<vertex;k++)
	// 		cout<<visited[k]<<"   ";
	// 	cout<<endl<<endl;
	// }

	for(int i=0;i<vertex;i++)
	 {
	 	for(int j=0;j<vertex;j++)
	 		visited[j]=0;
		s.push(i);
		visited[i]=1;
		DFS();
		for(int k=0;k<vertex;k++)
			cout<<visited[k]<<"   ";
		cout<<endl<<endl;
	}

	return 0;
}