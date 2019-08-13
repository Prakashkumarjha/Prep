#include<iostream>
using namespace std;
struct  Node{
	int data;
	Node* left;
	Node* right;
};
Node* newNode(int data)
{
	Node* node =new Node();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;	
}
class SumTree{
	public:
		void sumT(Node* root)
		{
			if(root==NULL)
				return 0;
			root->left=sumT(root->left);
			root->right=sumT(root->right);
			if(root->left!=NULL && root->right!=NULL)
				root->data=root->left->data+root->right->data;
			else if(root->left==NUll)
				root->data=root->right->data;
			else
				root->data=root->left->data;
		}
};
int main()
{
	
}