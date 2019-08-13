#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;
vector< pair<int,int> > A[55][55];
int visited [55][55], N,M,In[55][55];
void Matrixcontaining1()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(In[i][j])
			{
				if(i-1>=0 && j-1>=0 && In[i-1][j-1])
					A[i][j].push_back(make_pair(i-1,j-1));
				if(i-1>=0 && In[i-1][j])
					A[i][j].push_back(make_pair(i-1,j));
				if(i-1>=0 && j+1<M && In[i-1][j+1])
					A[i][j].push_back(make_pair(i-1,j+1));
				if(j-1>=0 && In[i][j-1])
					A[i][j].push_back(make_pair(i,j-1));
				if(j+1<M && In[i][j+1])
					A[i][j].push_back(make_pair(i,j+1));
				if(i+1<N &&j-1>=0 && In[i+1][j-1])
					A[i][j].push_back(make_pair(i+1,j-1));
				if(i+1<N && In[i+1][j])
					A[i][j].push_back(make_pair(i+1,j));
				if(i+1<N && j+1<M && In[i+1][j+1])
					A[i][j].push_back(make_pair(i+1,j+1));
			}
		}
	}
}

int NumberOfIsland()
{
	queue<pair<int,int> > q;

	Matrixcontaining1();
	
	int x2,y2,x,y,i,j,k,c=0;
	
	memset(visited,0,sizeof(visited));

	
	for ( i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(In[i][j] && visited[i][j]==0)
			{
				cout<<i<<"  "<<j<<endl;
				visited[i][j]=1;
				q.push(make_pair(i,j));
				c+=1;

				while(!q.empty())
				{
					 x=q.front().first;
					 y=q.front().second;
					 q.pop();

					for( k=0;k<A[x][y].size();k++)
					{
						x2 = A[x][y][k].first;
						y2 = A[x][y][k].second;
						if(visited[x2][y2]==0)
						{
							visited[x2][y2]=1;
							q.push(make_pair(x2,y2));
						}
						
					}
				}
			}
		}
	}
	return  c;
}
int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>N>>M;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				cin>>In[i][j];
				A[i][j].clear();
			}
		}
		
		cout<<NumberOfIsland()<<endl;
		//cout<<"Hi I am here. 2"<<endl;
	}


	return 0;
}