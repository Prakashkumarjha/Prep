#include<iostream>
using namespace std;



struct Node {
	int data;
	Node *left;
	Node *right; 
};

Node* createNode(int data) {
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
class Binary{
	public:
		struct Node* addNode( Node* root,int data) {
			if (root==NULL) {
				Node* node = createNode(data);
				return node;
			} 

			if (root->data>data) {
				root->left =  addNode(root->left,data);
				return root;
			} else { 
				root->right =  addNode(root->right,data);
				return root;
			}
		}

		struct Node* deleteNode(struct *root,int data)
		{
			if(root==NULL)
				return root;

			if(root->data>data)
				root->left=deleteNode(root->left,data);

			else if(root->data<data)
				root->right=deleteNode(root->right,data);

			else
			{
				Node* node=new Node();
				node=root;
				if(root->right==NULL)
				{
					root=root->left;
					while(root->right!=NULL)
						root=root->right;
					root->left=node->left;
					return root;
				}
				else if(root->left==NULL)
				{
					root=root->right;
					while(root->left!=NULL)
						root=root->left;
					root->right=node->right;
					return root;
				}
				else
				{
					root=root->right;
					while(root->left!=NULL)
						root=root->left;
					root->left=node->left;
					root->right=node->right;
					return root;
				}
			}
			return root;
			
		}

		struct Node* sucessor(struct *root,int data)
		{
			if(root==NULL)
				return root;
			if(root->data>data)
			{
				root->left=sucessor(root->left,data);
				return root;
			}

			else if(root->data<data)
			{
				root->right=sucessor(root->right,data);

			}
			else
			{
				if(root->right!=NULL)
				{
					root=root->right;
					while(root->left!=NULL)
						root=root->left;
				}
				return root;
			}

			
		}

		void inorderTraversal(struct *root)
		{
			if(root->left==NULL)
			{
				cout<<root;
				
			}
			if(root->left!=NULL)
				inorderTraversal(root->left);
			else if(root->right!=NULL)
				inorderTraversal(root->right);
		}

	/*	struct Node* deleteNode(Node* root,int data,Node* parent)
		{
			if(root==NULL)
				return root;

			if(parent == NULL && root->data == data) {
				//Node* node=new Node();
				parent=root;
				if(root->right!=NULL)
				{
					root=root->right;
					while(root->left!=NULL)
						root=root->left;
				}
				else if(root->left!=NULL)
				{
					root=root->left;
					while(root->right!=NULL)
						root=root->right;
				}
				else
				{
					root = NULL;
					return parent;
				}
				root->left=parent->left;
				root->right=parent->right;
				parent->left=NULL;
				parent->right=NULL;
				return parent;
			}
			
			if(root->data==data)
			{
				Node* node=new Node();
				node=root;
				if(root->right!=NULL)
				{
					root=root->right;
					while(root->left!=NULL)
						root=root->left;
				}
				else if(root->left!=NULL)
				{
					root=root->left;
					while(root->right!=NULL)
						root=root->right;
				}
				else
				{
					if(parent->left==root)
						parent->left=NULL;
					else
						parent->right=NULL;
					return node;
				}
				if(node->right==root)
				{
					root->left=node->left;
					node->left=NULL;
					node->right=NULL;
					return node;
				}
				if(node->left==root)
				{
					//root->left=node->left;
					node->left=NULL;
					node->right=NULL;
					return node;
				}
				root->left=node->left;
				root->right=node->right;
				node->left=NULL;
				node->right=NULL;
				return node;
			}
			else if(root->data>data)
			{
				parent=root;
				return deleteNode(root->left,data,parent);
			}
			else
			{
				parent=root;
				return deleteNode(root->right,data,parent);
			}
		}*/

		struct Node* searchNode(Node* root,int data)
		{
			if(root==NULL || root->data==data)
				return root;
			if(root->data>data)
				return searchNode(root->left,data);

			return searchNode(root->right,data);
		}
	};


int main()
{
	Binary binary;
	Node* root = binary.addNode(NULL,5);
	root=binary.addNode(root,4);
	root=binary.addNode(root,6);
	root=binary.addNode(root,3);
	root=binary.addNode(root,5);
	root=binary.addNode(root,8);
	Node* root1=new Node();
	root1=binary.searchNode(root,6);
	cout<<"\n"<<root1->left->data<<"\n";

	return 0;
}