#include<iostream>
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
Node* mirrorImage(Node* root)
{
	if(root==NULL)
		return root;
	root->left=mirrorImage(root->left);
	root->right=mirrorImage(root->right);
	Node* node=root->left;
	root->left=root->right;
	root->right=node;
	return root;
}
void InOrder(Node* root)
{
	if(root==NULL)
		return;
	InOrder(root->left);
	cout<<root->data;
	InOrder(root->right);
}

int main()
{
	Node* root=newNode(5);
	root->left=newNode(6);
	root->right=newNode(7);
	root->left->right=newNode(8);
	mirrorImage(root);
	InOrder(root);
	return 0;
}