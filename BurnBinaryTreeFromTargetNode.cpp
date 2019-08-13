#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data)
{
	Node* node=new Node();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

class BurningTree{
	map<int, vector<int> > map1;
	public:
		void burnBelow(Node* root,int k)
		{
			if(root==NULL)
				return;
			map1[k].push_back(root->data);
			burnBelow(root->left,k+1);
			burnBelow(root->right,k+1);
		}
		int  burn(Node* root,int burnpoint,int k)
		{
			if(root==NULL)
				return -1;
			if(root->data==burnpoint)
			{
				burnBelow(root,0);
				//k=0;
				return 0;
			}
			if(k==-1)
				k=burn(root->left,burnpoint,k);
			if(k!=-1)
			{
				k=k+1;
				map1[k].push_back(root->data);
				burnBelow(root->right,k);
			}

			if(k==-1)
				k=burn(root->right,burnpoint,k);
			if(k!=-1)
			{
				k=k+1;
				map1[k].push_back(root->data);
				burnBelow(root->left,k);
			}

		}

		void print()
		{
			for(int i=0;i!=map.end();i++)
			{
				for(int j=0;j<map[i].size();j++)
				{
					cout<<map[i][j]<<"  ";
				}
			}
		}
};




int main()
{
	Node* root=newNode(12);
	root->left=newNode(13);
	root->right=newNode(10);
	root->right->left=newNode(14);
	root->right->right=newNode(15);
	root->right->left->left=newNode(21);
	root->right->left->right=newNode(24);
	root->right->right->left=newNode(22);
	root->right->right->right=newNode(23);
	int burnpoint=14;
	BurningTree b;
	b.burn(root,burnpoint,-1);
	b.print();
	return 0;

}