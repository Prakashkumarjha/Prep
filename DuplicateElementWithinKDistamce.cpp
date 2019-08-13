#include<iostream>
#include<unordered_set>
using namespace std;
bool DuplicateElement(int A[],int n,int k)
{
	unordered_set<int> un;
	for(int i=0;i<n;i++)
	{
		if(un.find(A[i])!=un.end())
			return true;
		un.insert(A[i]);
		if(i>=k)
			un.erase(A[i-k]);
		
	}
	return false;
}
int main()
{
	 int arr[] = {10, 5, 3, 4, 3, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<DuplicateElement(arr,n,3)<<endl; 
	return 0;
}
