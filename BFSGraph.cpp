#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
void addEdge(vector<int>A[], int u,int v)
{
	A[u].push_back(v);
	A[v].push_back(u);
}


void BFS(vector<int>A[], int start, int vertex)
{
	queue<int> q;
	bool visited[vertex];
	for(int i=0;i<vertex;i++)
		visited[i]=false;
	q.push(start);
	visited[start]=true;
	while(!q.empty())
	{
		cout<<q.front()<<"-->";
		for(int i=0;i<A[q.front()].size();i++)
		{
			if(visited[A[q.front()][i]]==false)
			{
				q.push(A[q.front()][i]);
				visited[A[q.front()][i]]=true;
			}
		}
		q.pop();
	}
	cout<<endl;
}

void DFS(vector<int >A[], int start, int vertex)
{
	stack<int> s;
	bool visited[vertex];
	for(int i=0;i<vertex;i++)
	{
		visited[i]=false;
	}
	s.push(start);
	//visited[start]=true;
	//cout<<s.top()<<"-->";
	while(!s.empty())
	{
		int p=s.top();
		//cout<<s.top()<<"-->"<<endl;
		s.pop();
		//cout<<" Hi I am here"<<endl;
		//cout<<!visited[p]<<endl;
		if(!visited[p])
		{
			cout<<p<<"-->";
			visited[p]=true;
			//cout<<s.top();
		}
		//cout<<" Hi I am here too "<<endl;
		for(int i=0;i<A[p].size();i++)
		{
			if(!visited[A[p][i]])
				s.push(A[p][i]);
		}
	}
}

int main()
{
	int vertex=0;
	int edge=0;
	cin>>vertex;
	cin>>edge;
	vector<int> A[vertex];
	int u,v;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		addEdge(A,u,v);
	}
	for(int i=0;i<vertex;i++)
	{
		cout<<i<<"-->";
		for(int j=0; j<A[i].size();j++)
			cout<<A[i][j]<<"-->";
		cout<<endl;
	}

	cout<<endl<<endl<<endl;
	BFS(A,0,vertex);
	cout<<endl<<endl<<endl;
	DFS(A,0,vertex);
	cout<<endl<<endl<<endl;

	return 0;
}