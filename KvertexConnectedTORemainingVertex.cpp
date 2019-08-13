#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
vector<int>A[105];
vector<int >B[2];
int visited[105];
queue<int> q;
int vertex=0;
stack<int>s;
void addEdge(int u,int v)
{
	A[u].push_back(v);
	A[v].push_back(u);
}
void DFS(int d)
{
	
	if(s.empty())
		return;
	
	int t= s.top();
	int i=0;
	//cout<<A[t].size()<<endl;
	while(i<A[t].size())
	{
		if(visited[A[t][i]]==0)
		{
			visited[A[t][i]]=1;
			B[d].push_back(A[t][i]);
			s.push(A[t][i]);
			break;
		}
		i++;
		if(i==A[t].size())
		{
			s.pop();
		}
	}
	//cout<<d<<"  "<<t<<endl;
	DFS(d^1);
	
}

void BFS(int d)
{
	if(q.empty())
		return;
	int t=q.front();
	q.pop();
	
	for(int i=0;i<A[t].size();i++)
	{
		if(!visited[A[t][i]])
		{
			visited[A[t][i]]=1;
			B[d].push_back(A[t][i]);
			q.push(A[t][i]);
		}
	}
	BFS(d^1);
	
}

void kvertex()
{
	q.push(0);
	//s.push(0);
	visited[0]=1;
	// B[0].push_back(0);
	// DFS(1);
	B[0].push_back(0);
	BFS(1);
	//cout<<B[0][1]<<endl;
	if(B[0].size()<B[1].size())
	{
		for(int j=0;j<B[0].size();j++)
			cout<<B[0][j]<<"   ";
	}
	else
	{
		for(int j=0;j<B[1].size();j++)
			cout<<B[1][j]<<"   ";
	}

}

int main()
{
	vertex=4;
	addEdge(0,1);
	addEdge(2,3);
	addEdge(1,2);

	kvertex();
	return 0;
}