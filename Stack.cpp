#include<iostream>
#include <stack>
using namespace std;
#define MAX 1000
stack<int> sta;
class Stack
{
	int top=-1;
	int A[MAX];
	public:

		int prec(char c){
			if(c=='^')
				return 3;
			else if(c=='/' || c=='*')
				return 2;
			else if(c=='+'|| c=='-')
				return 1;
			else 
				return 0;
		}

		int top1()
		{
			if(top>=0)
				return A[top];
			else
				return 0;
		}
	

		
		bool push(char x)
		{
			top++;
			if(top>MAX)
				return false;
			A[top]=x;
			return true;
		}

		int pop1()
		{
			if(top>=0)
				return A[top--];
			else 
				return 0;
		}

		bool empty()
		{
			if(top>=0)
				return false;
			return true;
		}

		void infixToPostfix(string s)
		{
			stack <char>stack2;
			int i=0;
			//cout<<s[0]<<endl;
			while(i<s.length())
			{
				
				if(prec(s[i])==0)
				{
					//cout<<"hi"<<endl<<i<<endl<<s[i]<<endl<<prec(s[i])<<endl;
					cout<<s[i];
					//cout<<endl;
				}
				else if(prec(s[i])==3)
				{
					if(!stack2.empty() && prec(stack2.top())<3)
						stack2.push(s[i]);
					else
						cout<<s[i];
					//cout<<"hey"<<endl;
				}
				else if(prec(s[i])==2)
				{
					if(!stack2.empty() && prec(stack2.top())>2)
					{
						while(!stack2.empty() && prec(stack2.top())>2)
						{
							cout<<stack2.top();
							stack2.pop();
						
						}
						stack2.push(s[i]);
					}
					else if( !stack2.empty() && prec(stack2.top())<2)
					{
						
						stack2.push(s[i]);
					}
						
					else if(stack2.empty())
						stack2.push(s[i]);
					else
					{
						cout<<stack2.top();
						stack2.pop();
						stack2.push(s[i]);
					}
					//stack2.push(s[i]);
				//cout<<"ho"<<endl;
				}
				else if(prec(s[i])==1)
				{
					//cout<<prec(s[i])<<endl;
					if(!stack2.empty() &&  prec(stack2.top())>1)
					{
						//cout<<prec(s[i])<<endl;
						while(!stack2.empty() && prec(stack2.top())>1)
						{
							cout<<stack2.top();
							stack2.pop();
						}
						stack2.push(s[i]);
					}
					if(!stack2.empty() &&  prec(stack2.top())==1)
					{
						cout<<stack2.top();
						stack2.pop();
						stack2.push(s[i]);
					}
					if(stack2.empty())
						stack2.push(s[i]);
					//cout<<"hopshuiad"<<endl;
				}
				i++;
				//cout<<"-------------"<<i<<endl;
			}
			while(!stack2.empty())
			{
				//cout<<"hi.  "<<endl;
				cout<<stack2.top();
				stack2.pop();
			}
			cout<<endl;
		}
		bool BalancedParethesis(string s)
		{
			stack<char> stack3;
			int i=0;
			while(i<s.length())
			{
				if(s[i]=='('||s[i]=='{'||s[i]=='[')
					stack3.push(s[i]);
				else if(s[i]=='}')
				{
					if(!stack3.empty() && stack3.top()=='{')
						stack3.pop();
					else
						return false;
				}
				else if(s[i]==']')
				{
					if(!stack3.empty() && stack3.top()=='[')
						stack3.pop();
					else
						return false;
				}
				else if(s[i]==')')
				{
					if(!stack3.empty() && stack3.top()=='(')
						stack3.pop();
					else
						return false;
				}
				i++;
			}
			if(!stack3.empty())
				return false;
			return true;
		}

		void nextGreater(int A[], int n)
		{
			stack<int> s1;
			int i=0;
			while(i<n-1)
			{

				if(A[i]<A[i+1])
				{

					if(!s1.empty())
					{

						while(!s1.empty() && A[i+1]>s1.top())
						{
							cout<<s1.top()<<" -----> "<<A[i+1]<<endl;
							
							s1.pop();
							
						}

					}
					cout<<A[i]<<" -----> "<<A[i+1]<<endl;
				}
				else 
					s1.push(A[i]);

				i++;
			}
			s1.push(A[n-1]);
			while(!s1.empty())
			{
				cout<<s1.top()<<" -----> -1"<<endl;
				s1.pop();
			}
		}
		void putIntegerAtEndOfStack(int x)
		{
			if(sta.size()==0)
				sta.push(x);
			else
			{
				int y=sta.top();
				sta.pop();
				putIntegerAtEndOfStack(x);
				sta.push(y);
			}
		}
		void reverse()
		{
			if(sta.size()>0)
			{
				int i=sta.top();
				sta.pop();
				reverse();
				putIntegerAtEndOfStack(i);
				
			}

		}

};

int main()
{
	Stack stack1;
	Stack stack2;
	stack1.push(5);
	stack1.push(7);
	stack1.push(9);
	stack2.push(3);
	stack2.push(6);
	stack2.push(8);
	Stack s;
	int A[]={2,1,4,6,5,3,8};
	sta.push(5);
	sta.push(6);
	sta.push(7);
	s.reverse();
	cout<<sta.top();
	//s.infixToPostfix("2+1-3*4");
	//s.nextGreater(A,7);
	//cout<<s.BalancedParethesis("{[]}")<<endl;
	//cout<<stack2.top1()<<endl;
	//cout<<stack1.top1()<<endl;
	//cout<<stack1.pop()<<endl;
	//cout<<stack2.pop()<<endl;
	//cout<<stack1.pop()<<endl;
	//cout<<stack2.pop()<<endl;
	//cout<<stack1.pop()<<endl;
	//cout<<stack2.pop()<<endl;
	//cout<<stack1.pop()<<endl;
	//cout<<stack2.pop()<<endl;
}