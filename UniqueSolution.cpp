#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int p=0;
	for(int i=1 ;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int l=1;l<=n;l++)
				{
					if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l)
					{
						int a=i*i*i;
						int b=j*j*j;
						int c=k*k*k;
						int d=l*l*l;
						int e=a+b;
						int f=c+d;
						if(e==f)
						{
							cout<<i<<"  "<<j<<"  "<<k<<"  "<<l<<"  "<<endl;
							p++;
						}

					}
				}
			}
		}
	}
	if(p==0)
		cout<< "No such elements"<<endl;
}