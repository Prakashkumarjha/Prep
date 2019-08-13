#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Graph
{
	
	public:
		
		void addEdge(int u,int v,vector<int> A[])
		{
			A[u].push_back(v);
			A[v].push_back(u);
		}
};
int main()
{
	int vertex;
	cin>>vertex;
	vector<int>A[vertex];
	int edges;
	cin>>edges;
	Graph g;

	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u<vertex && v<vertex)
		{
			g.addEdge(u,v,A);
		}
		else
			cout<<"error"<<endl;
	}
	queue<int>q;
	stack<int>s;
	bool B[vertex];
	for(int i=0;i<vertex;i++)
		B[i]=0;
	// q.push(0);
	// //cout<<0<<"  ";
	// B[0]=1;
	// while(!q.empty())
	// {
	// 	int j=q.front();
	// 	for(int i=0;i<A[j].size();i++)
	// 	{
	// 		if(B[A[j][i]]==0)
	// 		{
	// 			q.push(A[j][i]);
	// 			B[A[j][i]]=1;
	// 		}
	// 	}
	// 	cout<<q.front()<<endl;
	// 	q.pop();
	// }
	s.push(0);
	B[0]=1;
	cout<<s.top()<<endl;
	while(!s.empty())
	{
		int j=s.top();
		
		for(int i=0;i<A[j].size();i++)
		{
			if(B[A[j][i]]==0)
			{
				cout<<A[j][i]<<endl;
				s.push((A[j][i]));
				B[A[j][i]]=1;
				break;
			}
		}
		if(j==s.top())
			s.pop();
	}
	return 0;
}