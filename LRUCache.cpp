// #include <iostream>
// #include <map>
// #include <vector>
// #include <iterator>
// using namespace std;
// struct Node{
// 	int data;
// 	Node* prev;
// 	Node* next;
// };

// Node* newNode(int data)
// {
// 	Node* node =new Node();
// 	node->data=data;
// 	Node* prev=NULL;
// 	Node* next=NULL;
// 	return node;
// }
// map<int, vector<Node*> > map1;
// Node* root=new Node();
// Node* rear=new Node();
// void push(int x)
// {

// 	Node* node=newNode(x);
// 	root->prev=node;
// 	node->next=root;
// 	root=node;
// 	if(map1.size()==0)
// 		rear=root;
// }

// void pop()
// {
// 	rear=rear->prev;
// 	rear->next=NULL;
// }
// void SwitchtoTop(Node* node)
// {
// 	node->prev->next=node->next;
// 	node->next->prev=node->prev;
// 	push(node->data);
// }
// void refer(int x)
// {
// 	if(map1.find(x)==map1.end())
// 	{
		
// 		if(map1.size() >=5)
// 		{
// 			//cout<<rear->data<<endl;
// 			map1[rear->data].push_back(NULL);
// 			cout<<rear->data<<"    "<<map1.size()<<endl;
// 			pop();
// 			cout<<rear->data<<"     "<<map1.size()<<endl;
// 			push(x);
// 			//cout<<rear->data<<endl;
// 			map1[x].push_back( root );
// 			//cout<<rear->data<<endl;

// 		}
// 		else
// 		{

// 			push(x);
// 			map1[x].push_back( root );
// 		}
// 	}
// 	else
// 	{
// 		if(map1.size()==1)
// 		{
// 			//push(x);
// 			map1[x].push_back(root);
// 		}
// 		else{
// 			SwitchtoTop(map1[x][0]);
// 			//cout<<" hi"<<endl;
// 			map1[x].push_back(NULL );
// 			//cout<<" hi I am here"<<endl;
// 			map1[x].push_back(root);
// 			//cout<<" hi I am here also  "<<x<<endl;
// 		}
// 	}
// }
// void Print()
// {
// 	//cout<<"hi  hey you "<<map1.size()<<endl;
// 	for(int i =1;i<map1.size();i++)
// 		cout<<map1[i][0]->data<<"   ";
// }

// int main()
// {
// 	refer(1);
// 	refer(2);
// 	refer(3);
// 	refer(2);
// 	refer(4);
// 	refer(5);
// 	refer(6);
// 	refer(2);
// 	refer(1);
// 	refer(2);
// 	Print();
// 	return 0;
// }





#include<iostream>
#include<list>
#include<unordered_map>
#include<iterator>
using namespace std;

class LRUCache
{
	list<int> dq;
	
	unordered_map<int ,list<int> > map;
	int csize;
	public:
		LRUCache(int n)
		{
			csize=n;
		}
		void refer(int x)
		{
			if(map.find(x)==map.end())
			{
				if(dq.size()==csize)
				{
					int last=dq.back();
					dq.pop_back();
					map.erase(last);

				}
			}
			else
				dq.erase(map[x]);
			dq.push_front(x); 
    		map[x] = dq.begin();
			
		}
		void print()
		{
			list<int> :: iterator it;
			for(it= dq.begin(); it!=dq.end(); it++)
			{
				cout<<*it<<"    ";
			}
		}
};

int main()
{
	LRUCache l(4);
	l.refer(1);
	l.refer(2);
	l.refer(3);
	l.refer(1);
	l.refer(4);
	l.refer(5);

	return 0;
}