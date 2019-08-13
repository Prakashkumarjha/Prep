#include<iostream>
#include<queue>
using namespace std;

int vertex;
queue<int> q;
bool visited[500];
int A[105][105];
void BFSTraversal()
{
	if(q.empty())
	{
		
		return;
	}
	//cout<<q.top()<<endl;
	int i=q.front();
	q.pop();
	cout<<i<<"-->";
	for(int j=i;j<vertex;j++)
	{
		//cout<<A[i][j]<<endl;
		if(A[i][j]==1 && visited[j]!=1)
		{
			//cout<<"Hi I am here"<<endl;
			visited[j]=1;
			q.push(j);
		}
	}
	BFSTraversal();
}
int main()
{
	vertex=5;
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<vertex;j++)
			cin>>A[i][j];
	}
	//  A[vertex][vertex] = { {0,1,1,0,1},
	// 	{1,0,0,1,0},
	// 	{1,0,0,0,1},
	// 	{0,1,0,0,0},
	// 	{1,0,1,0,0}
	// };
	//bool visited[5];
	for(int i=0;i<5;i++)
		visited[i]=0;
	
	q.push(0);
	BFSTraversal();
	return 0;
}