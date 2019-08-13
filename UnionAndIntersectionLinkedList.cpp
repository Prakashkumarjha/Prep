#include<iostream>
#include<unordered_set>
#include<list>
using namespace std;

class HashMap
{
	public:
		void Union(list<int>l1,list<int>l2)
		{
			unordered_set<int> map;
			list<int>::iterator it;
			list<int>::iterator it2;
			list<int>::iterator it3;
			for(it=l1.begin();it!=l1.end();it++)
			{
				map.insert(*it);
			}
			list<int >l3;
			for(it2=l2.begin();it2!=l2.end();it2++)
			{
				if(map.find(*it2)==map.end())
				{
					l3.push_back(*it2);
				}
			}
			for(it=l1.begin();it!=l1.end();it++)
			{
				l3.push_back(*it);
			}
			for(it3=l3.begin();it3!=l3.end();it3++)
			{
				cout<<*it3<<"->";
			}

		}
		void Intersection(list<int>l1,list<int>l2)
		{
			unordered_set<int> map;
			list<int>::iterator it;
			list<int>::iterator it2;
			list<int>::iterator it3;
			for(it=l1.begin();it!=l1.end();it++)
			{
				map.insert(*it);
			}
			list<int >l3;
			for(it2=l2.begin();it2!=l2.end();it2++)
			{
				if(map.find(*it2)!=map.end())
				{
					l3.push_back(*it2);
				}
			}
			for(it3=l3.begin();it3!=l3.end();it3++)
			{
				cout<<*it3<<"->";
			}
		}
};

int main()
{
	list<int >l1;
	l1.push_back(10);
	l1.push_back(15);
	l1.push_back(4);
	l1.push_back(20);
	list<int >l2;
	l2.push_back(8);
	l2.push_back(4);
	l2.push_back(2);
	l2.push_back(10);
	HashMap h;
	h.Union(l1,l2);
	cout<<endl;
	h.Intersection(l1,l2);
	cout<<endl;
	return 0;
}
