#include<iostream>
using namespace std;
int main()
{
	int arr[]={4,2,3,6,5,7};
	int n=6;
	sort(arr,arr+n);
	double median=0;
	if(n%2==0)
	{
		median=arr[n/2]+arr[n/2-1];
		median=median/2;
	}
	else
		median=arr[n/2];
	
	cout<<median<<endl;

	return 0;
}