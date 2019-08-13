#include<iostream>
#include <stack>
using namespace std;
stack<int> s;
class Reverse
{
	 
	public:
		void Reverse_method(int x)
		{
			if(s.empty())
			{
				s.push(x);
				return;
			}
			int y=s.top();
			s.pop();
			Reverse_method(x);
			s.push(y);

		}
		void Reverse_Stack()
		{
			if(!s.empty())
			{
				int x=s.top();
				s.pop();
				Reverse_Stack();
				Reverse_method(x);
			}
		}
};
int main()
{
	//stack<int> st;
	s.push(1); 
    s.push(2); 
    s.push(3); 
    s.push(4);
   // cout<<s.top()<<"   "; 
    Reverse r; 
    r.Reverse_Stack();
     while(!s.empty()) 
    { 
        cout<<s.top()<<"   "; 
        s.pop(); 
        
    }

}