#include<iostream>
#include<map>
#include<vector>
using namespace std;
void Valuepairs(int n)
{
	
	
	map<int ,vector<vector<int > > > ma;
	vector<int> v;
	int A[n][4];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				int a=i*i*i;
				int b=j*j*j;
				v.push_back(i);
				v.push_back(j);
				ma[a*b].push_back(v);
			}
		}
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int c=i*i*i;
			int d=j*j*j;
			if(ma.find(c*d)!=ma.end())
			{
				for(int p=0;p<=k;p++)
				{
					int s=0;
					for(int q=0;q<4;q++)
					{
						if(A[p][q]==i)
						{

							for(int r=0;r<4;r++)
							{
								if(A[p][r]==i)
									s++;
								if(A[p][r]==j)
									s++;
								if(A[p][r]==ma[c*d][j][0])
									s++;
								if(A[p][r]==ma[c*d][j][1])
									s++;
							}
						}
					}
					if(s!=4)
					{
						A[k][0]=ma[c*d][j][0];
						A[k][1]=ma[c*d][j][1];
						A[k][2]=i;
						A[k][3]=j;
						k++;
					}
				}
				
			}
		}
	}

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<A[i][j]<<"  ";
		}
		cout<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	Valuepairs(n);

	return 0;
}