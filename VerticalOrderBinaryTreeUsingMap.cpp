#include<iostream>
#include<map>
#include<vector>
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
void preOrderEnhance(Node* root,int i,map<int,vector<int> > &m)
{
	if(root==NULL)
		return;
	m[i].push_back(root->data);
	preOrderEnhance(root->left,i-1,m);
	preOrderEnhance(root->right,i+1,m);
}
void verticalOrder(Node* root)
{
	
	map<int, vector<int> > m;
	preOrderEnhance(root,0,m);
	 map< int,vector<int> > :: iterator it; 
    for (it=m.begin(); it!=m.end(); it++) 
    {
		 for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
        cout << endl; 
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
	verticalOrder(root);
	return 0;
}