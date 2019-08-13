#include<iostream>
using namespace std;

void coordinate(int &x,int &y,string command, string &current_facing)
{
	if(current_facing=="N")
	{
		if(command=="Turn_left")
			current_facing="W";

		else if(command=="Turn_right")
			current_facing="E";
		
		else if(command=="Move_ahed")
			y=y+1;
		
		else if(command=="Move_back")
			y=y-1;
	}
	else if(current_facing=="S")
	{
		if(command=="Turn_left")
			current_facing="E";

		else if(command=="Turn_right")
			current_facing="W";
		
		else if(command=="Move_ahed")
			y=y-1;
		
		else if(command=="Move_back")
			y=y+1;
	}
	else if(current_facing=="E")
	{
		if(command=="Turn_left")
			current_facing="N";

		else if(command=="Turn_right")
			current_facing="S";
		
		else if(command=="Move_ahed")
			x=x+1;
		
		else if(command=="Move_back")
			x=x-1;
	}
	else if(current_facing=="W")
	{
		if(command=="Turn_left")
			current_facing="S";

		else if(command=="Turn_right")
			current_facing="N";
		
		else if(command=="Move_ahed")
			x=x-1;
		
		else if(command=="Move_back")
			x=x+1;
	}
}
int main()
{
	int x=0;
	int y=0;
	string current_facing="N";
	string command;
	int i=5;
	while(i--)
	{
		cin>>command;
		coordinate(x,y,command,current_facing);
		cout<<x<<"  "<<y<<endl;
	}
	
}