#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int vertex;
vector<int> A[105];
queue<int> q;
int visited[105];
stack<int> s;
void addEdge(int u, int v)
{
	A[u].push_back(v);
}

void BFS(int &k)
{
	//cout<<"hi"<<endl;
	if(q.empty())
		return ;
	int i=q.front();
	//cout<<i<<"-->";
	k=k+1;
	q.pop();
	for(int j=0;j<A[i].size();j++)
	{
		if(!visited[A[i][j]])
		{
			q.push(A[i][j]);
			visited[A[i][j]]=1;
		}
	}
	BFS(k);
}

void DFS(int &k)
{
	if(s.empty())
		return ;
	int i=s.top();
	
	int j=0;
	//cout<<"hi"<<endl;
	for(j=0;j<A[i].size();j++)
	{
		
		if(visited[A[i][j]]!=1)
		{
			//cout<<"Hi"<<endl;
			visited[A[i][j]]=1;
			k=k+1;
			s.push(A[i][j]);
			break;
		}
	}
	if(j==A[i].size())
		s.pop();
	
	DFS(k);

}
int main()
{
	int edges;
	cin>>vertex;
	int u,v;
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v;
		addEdge(u,v);
	}
	
	// for(int i=0;i<vertex;i++)
	// {

	// 	for(int j=0;j<vertex;j++)
	// 		visited[j]=0;
	// 	q.push(i);
	// 	visited[i]=1;
	// 	int k=0;
	// 	BFS(k);
	// 	if(k==vertex)
	// 	{
	// 		cout<<i<<endl;
	// 		break;
	// 	}
	// 	cout<<endl<<endl;
	// }

	for(int i=0;i<vertex;i++)
	{

		for(int j=0;j<vertex;j++)
			visited[j]=0;
		s.push(i);
		visited[i]=1;
		int k=1;
		DFS(k);
		if(k==vertex)
		{
			cout<<i<<endl;
			break;
		}
		//cout<<endl<<endl;
	}
	return 0;
}