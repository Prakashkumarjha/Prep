#include<iostream>
#include<vector>
using namespace std;
struct Node{
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
vector<Node* >visited ;
Node* flawn(Node* root)
{
	if(root==NULL)
		return root;
	//cout<<visited.size()<<endl<<endl;
	for(int i=0;i<visited.size();i++)
	{
		//cout<<visited[i]<<". "<<root->data<<endl;
		if(visited[i]==root)
		{
			//cout<<root->data<<"  ";
			return NULL;
		}
	}
	visited.push_back(root);
	//cout<<visited[visited.size()-1]<<endl<<endl<<visited.size()<<endl;
	root->left=flawn(root->left);
	root->right=flawn(root->right);
	return root;
}


void InOrder(Node* root)
{
	if(root==NULL)
		return;
	InOrder(root->left);
	cout<<root->data<<endl;
	InOrder(root->right);
}
int main()
{
	Node* root=newNode(5);
	root->left=newNode(6);
	root->right=newNode(7);
	root->right->left=root->left;
	
	flawn(root);
	InOrder(root);
	return 0;
}