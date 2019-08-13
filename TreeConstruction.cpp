#include <iostream>
using namespace std;
struct Node
{
	char data;
	Node* left;
	Node* right;
};
struct Node1
{
	int data;
	Node* left;
	Node* right;
};
Node* newNode1(int data)
{
	Node* node=new Node();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
Node* newNode(char data)
{
	Node* node=new Node();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
class TreeConstruction
{
	public:
		int search(int In[],int start,int end,int data)
		{
			
			for(int i=start;i<=end;i++)
			{
				if(In[i]==data)
					{
						return i;
						
					}
			}
			return -1;
		}
		Node* newTree(char Pre[],char In[],int start,int end)
		{
			if(start>end)
				return NULL;
			static int n=0;

			Node* root=newNode(Pre[n++]);

			if(start==end)
				return root;
			int Index=0;
			for(int i=start;i<=end;i++)
			{
				if(In[i]==root->data)
					{
						Index=i;
						break;
					}
			}
			
			root->left=newTree(Pre,In,start,Index-1);
			root->right=newTree(Pre,In,Index+1,end);
			return root;
		}
		Node* newTree1(int Level[],int In[],int start,int end,int n)
		{
			if(start>end)
				return NULL;
			Node* root=newNode1(Level[n]);
			if(start==end)
				return root;
			int Index=search(In,start,end,root->data);
			
			int Level1[100];
			int k=0;
			int Level2[100];
			int l=0;
			for(int j=0;j<n;j++)
			{
				if(search(In,start,end,Level[j])!=-1)
				{
					Level1[k]=Level[j];
					k++;
				}
				else
				{
					Level2[l]=Level[j];
					l++;
				}

			}
			root->left=newTree1(Level1,In,start,Index-1,k);
			root->right=newTree1(Level2,In,Index+1,end,l);
			
			return root;

			
		}
		void inOrder(Node* root)
		{
			if(root==NULL)
				return;
			inOrder(root->left);
			cout<<root->data<<endl;
			inOrder(root->right);
		}
};

int main()
{
	char In[6]={ 'D' ,'B' ,'E', 'A', 'F', 'C'};
	char Pre[6]={'A', 'B', 'D', 'E', 'C', 'F'};
	int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
	TreeConstruction tree;
	Node* root=tree.newTree(Pre,In,0,5);

	Node* root1=tree.newTree1(level,in,0,7,8);
	//cout<<root->data<<endl;
	tree.inOrder(root1);
	return 0;
}