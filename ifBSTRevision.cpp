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

// bool ifBst(Node* root)
// {
// 	if(root==NULL)
// 		return true;
// 	bool b=false,c=false;
	
// 		b=ifBst(root->left);
	
// 		c=ifBst(root->right);
// 	bool d=true;
// 	if(root->left !=NULL && root->right!=NULL && (root->data <root->left->data || root->data>root->right->data))
// 	{
// 		d=false;
// 	}
// 	else if(root->left!=NULL && root->data <root->left->data )
// 	{
// 		d=false;
// 	}
// 	else if(root->right!=NULL && root->data> root->right->data)
// 	{
// 		//cout<<b<<c<<d<<endl;
// 		d=false;
// 		cout<<root->data<<endl;
// 		//cout<<b<<c<<d<<endl;
// 	}
// 	return b && c && d;
//}

// void mirrorTree(Node* root)
// {
// 	if(root==NULL)
// 		return ;
// 	Node* n=root->left;
// 	root->left=root->right;
// 	root->right=n;
// 	mirrorTree(root->left);
// 	mirrorTree(root->right);
// }

// void Inorder(Node* root)
// {
// 	if(root==NULL)
// 		return;
// 	Inorder(root->left);
// 	cout<<root->data<<"  ";
// 	Inorder(root->right);

// }

void printKdistanceBelowNode(Node* root,int k)
{
	if(root==NULL)
		return;
	if(k==0)
		cout<<root->data<<"  ";
	printKdistanceBelowNode(root->left,k-1);
	printKdistanceBelowNode(root->right,k-1);
}

int printKdistanceNode(Node* root,Node* temp,int k)
{
	if(root==NULL)
		return -1;
	if(root==temp)
	{
		printKdistanceBelowNode(root,k);
		return 0;
	}
	int lr=printKdistanceNode(root->left,temp,k);
	if(lr!=-1)
	{
		if(k-lr-1==0)
			cout<<root->data<<"  ";

		printKdistanceBelowNode(root->right,k-lr-2);
		return lr+1;
	}
	int rr=printKdistanceNode(root->right,temp,k);
	if(rr!=-1)
	{
		
		if(k-rr-1==0)
			cout<<root->data<<"  ";

		printKdistanceBelowNode(root->left,k-rr-2);
		return rr+1;
	}
	return 0;
}


Node*  parentNode(Node* root, Node* temp, Node* temp2)
{
	if(root==NULL)
		return root;
	if(root==temp || root==temp2)
		return root;
	// Node* left1=NULL;
	// Node* right1=NULL;
	Node* left1=parentNode(root->left,temp, temp2);
	Node* right1=parentNode(root->right,temp,temp2);
	if(left1!=NULL && right1!=NULL)
		return root;
	if(left1==NULL && right1==NULL)
		return NULL;
	return left1!=NULL?left1:right1;

}
int main()
{
	Node* root=newNode(5);
	root->left=newNode(4);
	root->right=newNode(6);
	root->left->left=newNode(7);
	//cout<<ifBst(root);
	//Inorder(root);
	//mirrorTree(root);
	cout<<endl;
	//printKdistanceNode(root,root->left,1);
	cout<<parentNode(root,root->left->left,root->right)->data<<endl;
	//Inorder(root);
	return 0;
}