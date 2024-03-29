#include<iostream>
#include<list>
using namespace std;
class BFS{
	int V;
	list <int > *adj;
	public:
		BFS(int V)
		{
			this->V=V;
			adj=new list<int>[V];

		}
		void addEdge(int u, int v)
		{
			adj[u].push_back(v);
		}
		void Graph(int s)
		{
			bool visited =new bool[V];
			for(int i=0;i<V;i++)
				visited[i]=false;
			
			list<int >queue;

			visited[s]=true;
			queue.push_back(s);
			while(!queue.empty())
			{
				s=queue.front();
				cout<<s<<"   ";
				queue.pop();
				for(int i=adj[s].begin;i!=adj[s].end();i++)
				{
					if(!visited[i])
					{
						visited[i]=true;
						queue.push_back(i);
					}
				}
			}

		}
};
int main()
{
	BFS g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.Graph(2); 
  
    return 0;
}