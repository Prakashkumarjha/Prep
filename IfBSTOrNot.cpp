#include<iostream>
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
bool ifBST(Node* root)
{
	if(root==NULL)
		return true;
	bool b=ifBST(root->left);
	bool c=ifBST(root->right);

	bool d=true;
	if(root->left!=NULL && root->right!=NULL && (root->data<root->left->data || root->data>root->right->data))
		d=false;
	else if(root->left!=NULL &&  root->data<root->left->data)
		d=false;
	else if(root->right!=NULL && root->data>root->right->data)
		d=false;
	return b&&c&&d;
}
int main()
{
	Node* root=newNode(5);
	root->left=newNode(4);
	root->right=newNode(7);

	cout<<ifBST(root)<<endl;
	return 0;
}