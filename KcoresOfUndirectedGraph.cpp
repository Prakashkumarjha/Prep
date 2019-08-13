#include<iostream>
#include<vector>
using namespace std;

vector<int> A[105];
void newNode(int u,int v)
{
	A[u].push_back(v);
	A[v].push_back(u);
}

void Kcores(int k)
{
	int j=0;
	for(int i=0;i<vertex;i++)
	{
		if(A[i].size<=k)
		{
			B[j]=i;
			j=j+1;
		}
	}
}

int main()
{
	return 0;
}