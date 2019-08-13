#include<iostream>
#include<deque>
#include<vector>
using namespace std;
void  slidingWindow(int arr[],int n, int k)
{
	
	deque<int> dq;
	for(int i=0;i<k;i++)
	{
		while(!dq.empty() && arr[i]>=arr[dq.back()])
			dq.pop_back();
		
		dq.push_back(i);
	}
	for(int i=k;i<n;i++)
	{
		//cout<<
		cout<<arr[dq.front()]<<endl;

		if(!dq.empty() && arr[i]>arr[dq.back()])
		{
			
			
			while(!dq.empty() && arr[i]>arr[dq.back()] )
				dq.pop_back();
			
		}
		else if(!dq.empty() && (i-k)>=dq.front())
		{
			dq.pop_front();
			
		}
		dq.push_back(i);
		
	}
	cout<<arr[dq.front()]<<endl;
}
int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
	slidingWindow(arr,n,k);
	return 0;
}