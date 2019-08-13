#include<iostream>
#include<map>

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
class Hash
{

	map<int, vector<Node*> > map;
	public:
		void verticalOrderTraversal(Node* root,int level,int curr)
		{
			if(root==NULL)
				return;
			if(curr==level)
			{
				map[level].push_back(root);
			
			}
			
			verticalOrderTraversal(root->right,level,curr+1);
			
			verticalOrderTraversal(root->left,level,curr-1);
		}
		void verticalOrderBinaryTree(Node* root)
		{
			Node* node=root;

			int l=0;
			while(node->left!=NULL)
			{
				node=node->left;
				l=l-1;
			}
			int r=0;
			node=root;
			while(node->right!=NULL)
			{
				node=node->right;
				r=r+1;
			}
			
			for(int i=l;i<=r;i++)
			{
				verticalOrderTraversal(root,i,0);
			}
			for(int i=l;i<=r;i++)
			{
				cout<<"vertical Order "<<i<<":- ";
				for(int j=0;j<map[i].size();j++)
				{
					//cout<<map[i].size()<<endl<<endl;
					cout<<map[i][j]->data<<"    ";
				}
				cout<<endl;
			}
		}

	


};
int main()
{
	Node* root=newNode(4);
	root->left=newNode(5);
	root->left->left=newNode(2);
	root->left->right=newNode(1);
	root->right=newNode(3);
	Hash h;
	h.verticalOrderBinaryTree(root);

	return 0;
}