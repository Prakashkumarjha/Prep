#include<iostream>
#include<queue>
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
queue<Node* > q;
int BurningTree(Node* root, int target)
{
	if(root==NULL)
		return 0;
	if(root->data ==target)
	{
		if(root->left!=NULL)
		{
			//cout<<root->left->data<<endl;
			q.push(root->left);
		}
		if(root->right!=NULL)
			q.push(root->right);
		cout<<root->data<<endl;
		return 1;
	}
	int l=BurningTree(root->left,target);
	if(l==1)
	{

		int qsize=q.size();
		while(qsize--)
		{
			Node* temp= q.front();
			cout<<temp->data<<"  ";
			q.pop();
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
		if(root->right!=NULL)
			q.push(root->right);
		cout<<root->data<<" ";
		cout<<endl;
		return 1;
	}

	int r=BurningTree(root->right ,target);
	if(r==1)
	{
		int qsize=q.size();
		while(qsize--)
		{
			Node* temp=q.front();
			cout<<temp->data<<"  ";
			q.pop();
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
		if(root->left!=NULL)
			q.push(root->left);
		cout<<root->data<<" ";
		cout<<endl;
		return 1;
	}
}

void BurnTree(Node* root, int target)
{
	//queue<Node* >q;
	BurningTree(root,target);
	while(!q.empty())
	{
		Node* temp=q.front();
		cout<<temp->data<<"  ";
		q.pop();
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}

int main()
{

	 Node* root = newNode(10); 
    root->left = newNode(12); 
    root->right = newNode(13); 
  
    root->right->left = newNode(14); 
    root->right->right = newNode(15); 
  
    root->right->left->left = newNode(21); 
    root->right->left->right = newNode(22); 
    root->right->right->left = newNode(23); 
    root->right->right->right = newNode(24); 
    int targetNode = 14; 
      
 
    BurnTree(root, targetNode); 
	return 0;
}