#include<iostream>
using namespace std;
int ReturnCountSubstringContainingVowel(string s)
{
	int start=0,j,end,a=0,e=0,i=0,o=0,u=0;
	int count=0;
	int n=s.length();
	while(start<n)
	{

		while(start!=n && s[start]!='a' && s[start]!='e' && s[start]!='i' && s[start]!='o' && s[start]!= 'u')
		{
			start++;
		}


		j=start;
		//cout<<j<<endl;
		while(j!=n && (s[j]=='a' || s[j] == 'e' || s[j]=='i' || s[j]=='o' || s[j]=='u'))
			j++;
		
		end=start;
		//cout<<j<<endl;
		while(end<j)
		{
			if(!(a>0 && e>0 && i>0 && o>0 && u>0)  )
			{	
			if(s[end]=='a')
			{
				a+=1;
				//cout<<end<<".  "<<start<<endl;
				end++;
			}
			else if(s[end]=='e')
			{
				e+=1;
				end++;
			}
			else if(s[end]=='i')
			{
				i+=1;
				end++;
			}
			else if(s[end]=='o')
			{
				o+=1;
				end++;
			}
			else if(s[end]=='u')
			{
				u+=1;
				end++;
			}
		}
			//cout<<"end=="<<end<<"    a=="<<a<<".   e=="<<e<<"    i=="<<i<<".   o=="<<o<<"    u=="<<u<<endl;
			if(a>0 && e>0 && i>0 && o>0 && u>0)
			{
				//cout<<s[end-1]<<endl;
				count=count+j-end+1;
				if(s[start]=='a')
				{
					a-=1;
					
				}
				else if(s[start]=='e')
				{
					e-=1;
					
				}
				else if(s[start]=='i')
				{
					i-=1;
					
				}
				else if(s[start]=='o')
				{
					o-=1;
					
				}
				else if(s[start]=='u')
				{
					u-=1;
					
				}
			
				start++;
			}
			//cout<<endl<<endl;
			//cout<<"end=="<<end<<"    a=="<<a<<".   e=="<<e<<"    i=="<<i<<".   o=="<<o<<"    u=="<<u<<".   count=="<<count<<endl;
			
			
			//cout<<end<<endl;

		}

		while(start<end)
	{
		if(a>0 && e>0 && i>0 && o>0 && u>0)
			{
				//cout<<s[end-1]<<endl;
				count=count+j-end+1;
				if(s[start]=='a')
				{
					a-=1;
					
				}
				else if(s[start]=='e')
				{
					e-=1;
					
				}
				else if(s[start]=='i')
				{
					i-=1;
					
				}
				else if(s[start]=='o')
				{
					o-=1;
					
				}
				else if(s[start]=='u')
				{
					u-=1;
					
				}
			
				
			}
			start++;
	}
		start=j;

		a=0;
		e=0;
		i=0;
		o=0;
		u=0;

	}

	
	return count;
}
int main()
{
	string s;
	cin>>s;
	cout<<ReturnCountSubstringContainingVowel(s)<<endl;
	return 0;
}