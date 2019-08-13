#include<iostream>
using namespace std;
int platformRequired(int Arr[],int Dept[],int n)
{
	int i=0;
	int j=0;
	int platformRequired=0;
	int minimum=0;
	sort(Arr,Arr+n);
	sort(Dept,Dept+n);

	while(i<n && j<n)
	{
		if(Arr[i]<Dept[j])
		{
			platformRequired=platformRequired+1;
			if(platformRequired>minimum)
				minimum=platformRequired;
			i++;
		}
		else if(Dept[j]<Arr[i])
		{
			platformRequired=platformRequired-1;
			j++;
		}
	}
	return minimum;
}

int main()
{
	int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required = " 
         << platformRequired(arr, dep, n); 
    return 0; 
}