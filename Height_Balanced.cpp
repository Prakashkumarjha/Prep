#include<iostream>
#include <algorithm>
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
	node->right=NULL;
	node->left=NULL;
	return node;
}

class Height_Balanced
{
	public:
		int heightOfTree(Node* root)
		{
			if(root==NULL)
				return 0;
			int height=0;
			int leftHeight = heightOfTree(root->left);
			int rightHeight = heightOfTree(root->right);
			return max(leftHeight, rightHeight) + 1;
		}

		bool heightBalanced(Node* root) {
			if(root == NULL)
				return true;

			int lH  = heightOfTree(root->left);
			int rH = heightOfTree(root->right);

			bool result = false;	
			if(lH - rH == 0 || lH-rH == 1 || lH-rH == -1) {
				result = true;
			}
			return heightBalanced(root->left) && heightBalanced(root->right) && result;
		}
		bool heightBalancedBottomUp(Node* root)
		{
			if(root==NULL)
				return true;
			bool l=heightBalancedBottomUp(root->left);
			bool r=heightBalancedBottomUp(root->right);
			int lH=heightOfTree(root->left);
			int rH=heightOfTree(root->right);
			bool b=false;
			if(lH-rH == 0||lH-rH == 1||lH-rH == -1)
				b=true;
			return l && r && b;
		}
		void dataAtLevel(Node* root, int level)
		{
			if(root==NULL)
				return ;
			if(level==1)
			{
				cout<<root->data<<endl;
				return;
			}
			if(level>1)
			{
				dataAtLevel(root->left,level-1);
				dataAtLevel(root->right,level-1);
			}
		}

		void reverseLevelOrder(Node* root)
		{
			if(root==NULL)
				return;
			int height=heightOfTree(root);
			for(int j=height;j>=1;j--)
			{
				dataAtLevel(root,j);
			}
		}

		int level(Node* root,  int level1)
		{
			if(root==NULL)
				return 0;
			if(level1==1)
				return 1;
				
			else if(level1>1)
				return level(root->left,level1-1) + level(root->right,level1-1);
			return 0;
				
		}

		int maximumWidth(Node* root)
		{
			if(root==NULL)
				return 0;
			int k=0;
			int height=heightOfTree(root);
			//cout<<height<<endl;
			for(int p=1;p<=height;p++)
			{
				int j=0;
				j=level(root,p);
				//cout<<j<<endl;
				if(j>k)
				{
					//cout<<k<<endl;
					k=j;
				}
					
			}
			return k;
		}

};
int main()
{
	Node* root=newNode(4);
	root->left = newNode(5);
	root->right = newNode(6);
	root->left->left=newNode(8);
	Height_Balanced h;
	h.reverseLevelOrder(root);
	//cout<<h.dataAtLevel(root,1);
	//cout<<h.level(root,1)<<endl;
	//cout<<h.heightBalancedBottomUp(root)<<endl;
	//cout<<h.widthOfLevel(root,1)<<endl;
}