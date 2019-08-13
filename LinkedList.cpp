#include<iostream>
using namespace std;
#include<unordered_set>
struct Node
{
	int data;
	Node *next;
};

Node* newNode(int data){
	Node* node=new Node();
	node->data=data;
	node->next=NULL;
	return node;
}

class LinkedList
{
	public:
		void insertNodeAfter(Node* &prev_node,int data)
		{
			if(prev_node==NULL)
			{
				cout<<"Previous Node is NULL ";
				return ;
			}
			Node* new_node=newNode(data);
			new_node->next=prev_node->next;
			prev_node->next=new_node;
			return ;

		}
		void insertAtBegining(Node* &head,int data)
		{
			if(head==NULL){
				cout<<"Head is NULL ";
				Node* new_node=newNode(data);
				head= new_node;
				return ;
			}
			Node* new_node=newNode(data);
			new_node->next=head;
			head=new_node;
			return ;
		}
		void deleteKey(Node* &head,int data)
		{
			if(head==NULL)
			{
				//cout<<"Head is NULL ";
				return ;
			}
			if(head->data==data)
			{
				head=head->next;
				return ;
			}
			Node* prev_node;
			Node* node;
			node=head;
			while(node->next!=NULL && node->data!=data)
			{
				prev_node=node;
				node=node->next;
			}
			if(node->data==data)
			{
				prev_node->next=node->next;
				node->next=NULL;
				return ;
			}
			else
			{
				cout<<"Node not found ";
				return;
			}

		}
		void deleteNodeByPosition(Node* &head,int pos)
		{
			if(head==NULL)
			{
				cout<<"Head is NULL ";
			}
			if(pos==0)
			{
				head=head->next;
				return ;
			}	
			Node* node=NULL;
			Node* prev_node=NULL;
			node=head;

			while(pos-- && node->next!=NULL)
			{
				prev_node=node;
				node=node->next;
			}
			if(pos==0)
			{
				prev_node->next=node->next;
				node->next=NULL;
			}

			else if(pos>0)
				cout<<"Node not Found";
			

		}
		void traverse(Node* head)
		{
			while(head!=NULL)
			{
				cout<<head->data<<endl;
				head=head->next;
			}
		}
		void traverseRecursive(Node* head)
		{
			if(head==NULL)
				return;
			if(head!=NULL)
				cout<<head->data<<endl;
			traverseRecursive(head->next);
		}
		int loopDetection(Node* head)
		{
			if(head==NULL)
			{
				cout<<"No Loop"<<endl;
				return 0;
			}
			int index=1;
			Node* node;
			Node* node1;
			node=head;
			unordered_set<Node*> s;
			while(node->next!=NULL)
			{
				
				if(s.find(node)!=s.end())
				{
					cout<<node->data<<endl<<node1->data<<endl;
					while(node!=node1)
					{
						index++;
						node=node->next;
						
					}
					return index;
				}
				s.insert(node);
				node1=node;
				node=node->next;
			}
			return index;
		}

		Node* findMiddle(Node* head)
		{
			if(head==NULL)
				return head;
			Node* temp=head;
			int count=1;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				count++;
			}
			count=(count/2);

			while(count--)
			{
				 //cout<<count<<endl;
				head=head->next;
			}
			return head;
		}
};

int main()
{
	LinkedList linklist;
	
	Node* head =newNode(5);
	linklist.insertAtBegining(head,4);
	linklist.insertAtBegining(head,3);
	linklist.insertAtBegining(head,2);
	linklist.insertAtBegining(head,1);
	//cout<<head->data<<endl;
	//linklist.insertNodeAfter(head->next,8);
	//linklist.insertNodeAfter(head->next,9);
	//head->next->next->next=head;
	//linklist.traverse(head);
	//linklist.deleteKey(head,6);
	//linklist.traverse(head);
	//linklist.traverseRecursive(head);
	//int index=linklist.loopDetection(head);
	Node* output=linklist.findMiddle(head);
	cout<<output->data<<endl;
	//cout<<index<<endl;
}