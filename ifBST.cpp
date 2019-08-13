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
bool ifBST(Node* root)
{
	if(root==NULL)
		return true;
	
	
	bool b=ifBST(root->left);
	
	bool c=ifBST(root->right);
	bool d=true;

	if(root->left!=NULL && root->right!=NULL)
	{

		if(root->data<root->right->data && root->data>root->left->data)
			d=true;
		else
			d=false;
		
	}
	return (b && c &&d);
}
int height(Node* root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}
int diagonalOfTree(Node* root)
{
	if(root==NULL)
		return 0;
	return max(max(diagonalOfTree(root->left),diagonalOfTree(root->right)),height(root->left)+height(root->right)+1);
}
Node* lca(Node* root , int n1,int n2)
{
	if(root==NULL)
		return root;
	if(root->data>n1 && root->data>n2)
		return lca(root->left,n1,n2);
	else if(root->data<n1 && root->data<n2)
		return lca(root->right,n1,n2);

	return root;		
}
void kthsmallest(Node* root ,int &i, int k)
{
	if(root==NULL)
		return;
	kthsmallest(root->left,i,k);
	i++;
	if(i==k)
		cout<<root->data<<endl;
	kthsmallest(root->right,i,k);
}
void printkdistanceNodeDown(Node* root,int k)
{
	if(root==NULL)
		return;
	if(k==0)
	{
		cout<<root->data<<endl;
		return;
	}
	printkdistanceNodeDown(root->left,k-1);
	printkdistanceNodeDown(root->right,k-1);
}
int printkdistanceNode(Node* root,Node* target,int k)
{
	if(root==NULL)
		return -1;
	if(root==target)
	{
		printkdistanceNodeDown(root,k);
		return 0;
	}
	int dl=printkdistanceNode(root->left,target,k);
	if(dl!=-1)
	{
		if(dl+1==k)
			cout<<root->data<<endl;
		else
			printkdistanceNodeDown(root->right,k-dl-2);
		return dl+1;
	}
	int dr=printkdistanceNode(root->right,target,k);
	if(dr!=-1)
	{
		if(dr+1==k)
			cout<<root->data<<endl;
		else
			printkdistanceNodeDown(root->left,k-dr-2);
		return dr+1;
	}
	return -1;
}
int main()
{
	Node* root=newNode(8);
	root->left=newNode(4);
	root->right=newNode(9);
	root->left->left=newNode(3);
	root->left->left->left=newNode(2);
	root->left->left->left->left=newNode(1);
	root->left->right=newNode(5);
	root->left->right->right=newNode(6);
	root->left->right->right->right=newNode(7);
	//cout<<lca(root,1,7)->data<<endl;
	//cout<<diagonalOfTree(root)<<endl;
	//cout<<ifBST(root)<<endl;
	printkdistanceNode(root,root->left->left,3);
	int i=0;
	//kthsmallest(root,i,4);
	return 0;
}