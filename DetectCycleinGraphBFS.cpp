#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int vertex;
vector<int> v[105];
int visited[105];
void addEdge(int u,int k)
{
	v[u].push_back(k);
	v[k].push_back(u);
}
bool BFS(int start)
{
	int t;
	queue<int>que;
	visited[start]=1;
	que.push(start);
	//cout<<"Hi I am here "<<endl;
	while(!que.empty())
	{
		t=que.front();
		//cout<<t<<endl;
		que.pop();
		for(int i=0;i<v[t].size();i++)
		{
			if(!visited[v[t][i]])
			{
				que.push(v[t][i]);
				visited[v[t][i]]=1;
			}
			else
				return true;
		}
	}
	return false;
}
int main()
{
	int edge,u,k;
	cin>>vertex;
	//cin>>edge;
	// for(int i=0;i<edge;i++)
	// {
	// 	cin>>u>>k;
	// 	addEdge(u,k);
	// }


    addEdge(0, 1); 
   // addEdge(0, 2); 
    addEdge(1, 2); 
   // addEdge(2, 0); 
    //addEdge(2, 3); 
   // addEdge(3, 3); 

	cout<<BFS(0)<<endl;


}