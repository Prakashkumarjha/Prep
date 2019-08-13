#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int > graph[],int u,int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}


int main()
{
	int vertex;
	cin>>vertex;
	vector<int >graph[vertex];
	int edges,u,v;
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v;
		if(u>=0 && u<edges && v>=0 && v<edges)
		{
			addEdge(graph,u,v);
		}
	}
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<graph[i].size();j++)
		{
			cout<<graph[i][j]<<"  |  ";
		}
		cout<<endl;
	}
}