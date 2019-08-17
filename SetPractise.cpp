#include<iostream>
#include<set>
using namespace std;
set<int >A[50];
set<int >B[50];
int main()
{
	int z=0,y;
	for(int i=0;i<3;i++)
	{
		cin>>z;
		for(int j=0;j<z;j++)
		{
			cin>>y;
			A[i].insert(y);
		}

	}
	set<int >:: iterator it;
	set<int >:: iterator it1;
	for(it=A[0].begin();it!=A[0].end();it++)
		B[0].insert(*it);
	int j=0;
	int p=-1;
	for(int i=1;i<3;i++)
	{

		for( it=A[i].begin();it!=A[i].end();it++)
		{

			for(int k=0;k<=j;k++)
			{
				for(it1=B[k].begin();it1!=B[k].end();it1++)
				{
					if(*it1==*it)
					{
						p=k;
						break;
					}
				}
				if(p>=0)
					break;
			}
			if(p>=0)
				break;
		}
		if(p>=0)
		{
			for( it=A[i].begin();it!=A[i].end();it++)
			{
				B[p].insert(*it);
			}
			p=-1;
		}
		else
		{
			j++;
			for( it=A[i].begin();it!=A[i].end();it++)
			{
				B[j].insert(*it);
			}
		}
		
	}

	int i=1;
	int l=8;
	bool b=false;
	bool c=false;

	for(int k=0;k<=j;k++)
	{
		//cout<<" Hi I am here"<<endl;
		for(it=B[k].begin();it!=B[k].end();it++)
		{
			//cout<<i<<"   "<<*it<<endl;
			if(*it==i)
			{
				b=true;
			}
			else if(*it==l)
			{
				c=true;
			}

		}
		if(b && c)
		{
			cout<<" YES "<<endl;
			break;
		}
		b=false;
		c=false;
	}
	if( !(b&&c))
	{
		cout<<" NO "<<endl;
	}
	return 0;
}