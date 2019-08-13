#include<iostream>
using namespace std;
struct Node
{
	Node* left;
	Node* right;
	int data;
};
Node* newNode(int data)
{
	Node* node=new Node();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void minmaxtree(Node* root, int &min, int &max, int curr)
{
	if(root==NULL)
		return;
	if(curr<min)
		min=curr;
	if(curr>max)
		max=curr;
	minmaxtree(root->left, min,max,curr-1);
	minmaxtree(root->right,min,max,curr+1);
}
void printVerticalLevel(Node* root,int level ,int currlevel)
{
	if(root==NULL)
		return;
	if(level==currlevel)
		cout<<root->data<<"    ";
	printVerticalLevel(root->left,level,currlevel-1);
	printVerticalLevel(root->right,level,currlevel+1);
} 
void printTreeVertically(Node* root)
{
	int min=0;
	int max=0;
	minmaxtree(root,min,max,0);
	
	for(int i=min;i<=max;i++)
	{
		cout<<endl;
		printVerticalLevel(root,i,0);
	}
}

int main()
{
	Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
	printTreeVertically(root);
}