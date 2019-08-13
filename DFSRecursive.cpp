#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int>A[],int u,int v)
{
	A[u].push_back(v);
}
void DFSUtil(vector<int >A[],int v,bool visited[])
{
	visited[v]=true;
	cout<<v<<"  ";
	for(int i=0;i<A[v].size();i++)
	{
		if(!visited[A[v][i]])
			DFSUtil(A,A[v][i],visited);

	}

}
void DFS(vector<int>A[],int v,int vertex)
{
	bool visited[vertex];
	for(int i=0;i<vertex;i++)
		visited[i]=false;
	DFSUtil( A,v,visited);
}

bool isSafe(int A[][5],int i,int j,bool visited[], int vertex)
{
	return i>=0 && j>=0 && i<=vertex && j<=vertex && !visited[A[i][j]];
}
void IsIslandUtil(int A[][5],int i, int j, bool visited[], int vertex)
{
	int P[8]={-1,-1,-1,0,0,1,1,1};
	int Q[8]={-1,0,1,-1,1,-1,0,1};
	visited[A[i][j]]=true;
	for(int k=0;k<8;k++)
	{
		if(isSafe(A,i+P[k],j+Q[k],visited,vertex))
			IsIslandUtil(A,i+P[k],j+Q[k],visited,vertex);
	}
}
void NumberofIsland(int A[][5],int vertex)
{
	bool visited[vertex];
	for(int i=0;i<vertex;i++)
		visited[i]=false;
	
	int count=0;
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<vertex;j++)
		{
			if (A[i][j] && !visited[i][j]) {
			IsIslandUtil( A,i,j,visited, vertex);
			count++;
		}
		}

			
	}
	cout<<count<<endl;
}
int main()
{
	// int vertex=0;
	// int edge=0;
	// cin>>vertex;
	// cin>>edge;
	// vector<int> A[vertex];
	// int u,v;
	// for(int i=0;i<edge;i++)
	// {
	// 	cin>>u>>v;
	// 	addEdge(A,u,v);
	// }
	// DFS(A,2,vertex);
	int M[][5] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
  
  NumberofIsland(M,5); 
	return 0;
}