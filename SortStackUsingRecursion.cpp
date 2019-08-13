#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
void Reverse(int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	if(s.top()>x)
	{
		s.push(x);
		return;
	}
	int y=s.top();
	s.pop();
	Reverse(x);
	s.push(y);
}
void Reverse_stack()
{
	if(!s.empty())
	{
		int x=s.top();
		s.pop();
		Reverse_stack();
		Reverse(x);
	}
}
int main()
{
	s.push(1); 
    s.push(4); 
    s.push(3); 
    s.push(2);
   // cout<<s.top()<<"   "; 
    //Reverse r; 
    Reverse_stack();
     while(!s.empty()) 
    { 
        cout<<s.top()<<"   "; 
        s.pop(); 
        
    }
}