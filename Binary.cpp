#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* nextNode;
};


Node* createNode(int data)
{
	Node *node =new Node();
	node->data=data;
	node->left=NULL;
	node ->right=NULL;
	node->nextNode=NULL;
	return node;
}
class Binary{
	public:
		Node* sumT(Node* root)
		{
			if(root==NULL)
				return root;
			root->left=sumT(root->left);
			root->right=sumT(root->right);
			if(root->left!=NULL && root->right!=NULL)
				root->data=root->left->data+root->right->data+root->data;
			else if(root->left==NULL && root->right!=NULL)
				root->data=root->right->data+root->data;
			else if(root->right==NULL && root->left!=NULL)
				root->data=root->left->data+root->data;
			return root;
		}
		Node* addNode(Node* root,int data)
		{
			if(root==NULL)
			{
				Node* node=createNode(data);
				return node;
			}

			if(data<root->data)
			{
				root->left=addNode(root->left,data);
				return root;
			}
			else
			{
				root->right =addNode(root->right ,data);
				return root;
			}
		}

		Node* deleteNode(Node* root, int data)
		{
			if(root==NULL)
				return root;
			if(data<root->data)
			{
				root->left=deleteNode(root->left,data);
			}
			else if(data>root->data)
				root->right=deleteNode(root->right,data);
			else
			{
				if(root->left==NULL)
				{
					Node* tmp=root->right;
					root->right=NULL;
					root->data=0;
					return tmp;
				}
				else if(root->right==NULL)
				{
					Node* tmp=root->left;
					root->left=NULL;
					root->data=0;
					return tmp;
				}
				Node* tmp=root;
				tmp=tmp->right;
				while(tmp->left!=NULL)
					tmp=tmp->left;
				root->data=tmp->data;
				tmp->data=0;
				return root;
			}
			return root;
		}

		Node* searchNode(Node* root,int data)
		{
			if(root==NULL || root->data==data)
				return root;
			if(root->data>data)
				return searchNode(root->left,data);
			else
				return searchNode(root->right,data);
		}

		void inOrder(Node* root)
		{
			if(root==NULL)
				return ;

			inOrder(root->left);
			cout<<root->data<<"\n";
			inOrder(root->right);
		}
		void preOrder(Node* root)
		{
			if(root==NULL)
				return;
			cout<<root->data<<"\n";
			preOrder(root->left);
			preOrder(root->right);
		}
		void postOrder(Node* root)
		{
			if(root==NULL)
				return;
			postOrder(root->left);
			postOrder(root->right);
			cout<<root->data<<"\n";
		}
		void successor(Node* root,int data,int A[],int &i)
		{
			//cout<<"hello"<<endl;
			if(root==NULL)
				return ;
			successor(root->left,data,A,i);
			if(root->data>data)
			{
				A[i]=root->data;
				
				i++;
			
			}
			
			successor(root->right,data,A,i);
		}
		
		void leafNode(Node *root,int B[] ,int &j)
		{
			if(root==NULL)
				return;
			leafNode(root->left,B,j);
			if(root->left==NULL && root->right==NULL)
			{
				B[j]=root->data;
				j++;
			}
			leafNode(root->right ,B,j);
		}

		int heightOfTree(Node* root,int height)
		{
			if(root==NULL)
			{
				//cout<<"hi";
				return 0;
			}
			if(heightOfTree(root->left,height)>heightOfTree(root->right,height))
				height=heightOfTree(root->left,height)+1;
			else
				height=heightOfTree(root->right,height)+1;
			//cout<<height;
			return height;
		}
		void level(Node* root,  int level1)
		{
			if(root==NULL)
				return;
			if(level1==1)
			{
				
				cout<<root->data<<"  ";
			}
			
			level(root->left,level1-1);
			level(root->right,level1-1);
		}
		void levelwithLevelPointing(Node* root,  int level1,vector<Node*> A)
		{
			if(root==NULL)
				return;
			//cout<<level1<<root->data<<endl;
			if(level1==1)
			{
				//cout<<"hi"<<endl;
				//cout<<"hey"<<root->data<<i<<endl;
				A.push_back(root);
				//A[i]=root;
				//cout<<endl<<"hey"<<root->data<<endl;
				//cout<<"hello"<<endl;
				//i++;
				//cout<<root->data<<"  ";
			}
			
			levelwithLevelPointing(root->left,level1-1,A);
			levelwithLevelPointing(root->right,level1-1,A);
		}
		void levelOrderwithLevelPointer(Node* root,int h)
		{
			if(root==NULL)
				return;
			for(int i=1;i<=h;i++)
			{
				cout<<endl;
				
				
				vector<Node*> A;
				//Node* A[500];
				int j=0;
				levelwithLevelPointing(root,i,A);
				//vector<Node*>::iterator it ;
				//vector<int>::iterator it;
				cout<<"hello"<<endl<<A.size()<<endl;
				for(int i=0 ;i<A.size();i++)
				//for(it = A.begin();it!=A.end()-1;it++)
				{
					cout<<"hi"<<endl;
					cout<<A[i]<<endl;
					//cout<<*it<<endl;
					//*it->nextNode=*(it+1);
				}
			
			}
		}
		int totalNodesInTree(Node* root, int &total)
		{
			if(root==NULL)
				return total;
			totalNodesInTree(root->left,total);
			total++;
			totalNodesInTree(root->right,total);
			return total;
		}
		void levelzigzag(Node* root, int level1, int b)
		{
			if(root==NULL)
				return;

			if(level1==1)
			{
			
				cout<<root->data<<"  ";
			}
			
			if(b%2==0)
			{
				levelzigzag(root->left,level1-1,b);
				levelzigzag(root->right,level1-1,b);
			}
			else
			{
				levelzigzag(root->right,level1-1,b);
				levelzigzag(root->left,level1-1,b);
			}
		}

		void levelOrderTraversal(Node* root,int h)
		{
			if(root==NULL)
				return;
			for(int i=1;i<=h;i++)
			{
				cout<<endl;
				level(root,i);
			
			}
		}
		void levelOrderZigZagTraversal(Node* root,int h)
		{
			if(root==NULL)
				return;
			
			for(int i=1;i<=h;i++)
			{
				
				levelzigzag(root,i,i);
				
			}
		}
		void levelOrderTraversalWithQueue(Node* root)
		{
			if(root==NULL)
				return ;
			Node* node=new Node();
			node=root;
			queue<Node*>myqueue;
			myqueue.push(root);
			while(!myqueue.empty())
			{
				if(node->left!=NULL)
					myqueue.push(node->left);
				if(node->right!=NULL)
					myqueue.push(node->right);
				cout<<node->data<<endl;
				myqueue.pop();
				node=myqueue.front();
			}
		}
		void levelOrderZigZagTraversalWithStack(Node* root)
		{
			if(root==NULL)
				return;
			Node* node=new Node();
			node=root;
			stack<Node*>mystack1;
			stack<Node* >mystack2;
			mystack1.push(root);
			while(!mystack1.empty() || !mystack2.empty())
			{
				while(!mystack1.empty())
				{
					node=mystack1.top();
					if(node->left!=NULL)
						mystack2.push(node->left);
					if(node->right!=NULL)
						mystack2.push(node->right);
					cout<<node->data<<"  ";
					mystack1.pop();
				}
				while(!mystack2.empty())
				{
					node=mystack2.top();
					if(node->left!=NULL)
						mystack1.push(node->left);
					if(node->right!=NULL)
						mystack1.push(node->right);
					cout<<node->data<<"  ";
					mystack2.pop();
				}
			}
		}

		Node* levelOrderInsertioninBinaryTree(Node* root, int data)
		{
			if(root==NULL)
			{
				Node* node=createNode(data);
				return node;
			}
			Node* node=new Node();
			node=root;
			queue<Node*>myqueue;
			myqueue.push(root);
			while(!myqueue.empty())
			{
				if(node->left==NULL)
				{
					Node* node1=createNode(data);
					node->left=node1;
					return root;
				}
				if(node->right==NULL)
				{
					Node* node1=createNode(data);
					node->right=node1;
					return root;
				}
				if(node->left!=NULL)
					myqueue.push(node->left);
				if(node->right!=NULL)
					myqueue.push(node->right);
				//cout<<node->data<<endl;
				myqueue.pop();
				node=myqueue.front();
			
			}
			return root;
			
		}
		

};

int main()
{
	Node* root=new Node();
	Binary binary;
	root=binary.addNode(NULL,5);
	root=binary.addNode(root,3);
	root=binary.addNode(root,2);
	root=binary.addNode(root,1);
	root=binary.addNode(root,7);
	root=binary.addNode(root,6);
	//binary.inOrder(root);
	//cout<<endl;
	//binary.preOrder(root);
	//cout<<endl;
	//binary.postOrder(root);
	cout<<endl;
	int a=0;
	//cout<<binary.searchNode(root,7)->data<<endl;
	//if(binary.searchNode(root,9)==NULL)
	//	cout<<"NOT FOUND"<<endl;
	//else
	//	cout<<binary.searchNode(root,9)->data<<endl;
	int A[10];
	int i=0;

	//binary.successor(root,5,A,i);
	//cout<<A[0]<<endl;

	int B[10];
	int j=0;
	//binary.leafNode(root,B,j);
	//for(int k=0;k<j;k++)
	//	cout<<B[k]<<endl;
	int height=0;
	//cout<<binary.heightOfTree(root,height)<<endl;

	//int H[10];
	//int p=0;
	binary.level(root,2);
	//cout<<endl;
	//for(int i=0;i<p;i++)
	//	cout<<H[i]<<endl;

	cout<<endl<<endl<<endl;
	//binary.levelOrderTraversal(root,binary.heightOfTree(root,height));
	//binary.levelOrderZigZagTraversal(root,binary.heightOfTree(root,height));

	//binary.levelOrderTraversalWithQueue(root);
	//binary.levelOrderZigZagTraversalWithStack(root);
	//binary.levelOrderInsertioninBinaryTree(root,8);
	//binary.levelOrderTraversal(root,binary.heightOfTree(root,height));
	//binary.deleteNode(root,3);
	//binary.inOrder(root);

	//binary.levelOrderwithLevelPointer(root,binary.heightOfTree(root,height));
	//cout<<root->left->nextNode->data;
	//int total=0;
	//total=binary.totalNodesInTree(root,total);
	//root=binary.sumT(root);
	//binary.inOrder(root);
	//cout<<total<<"\n";
	//cout<<root->data<<"  "<<root->left->data<<"  "<<root->left->nextNode->data;

	return 0;
}