#include<iostream>
using namespace std;
int countNumberOfStations(int A[], int D[] , int n)
{
	int max_count=1;
	int count=1;
	int i=1;
	int j=0;
	while(i<n && j<n && i>j)
	{
		if(A[i]<D[j])
		{
			count+=1;
			//cout<<count<<endl;
			if(count>max_count)
				max_count=count;
			i++;

		}
		else if(j==i-1 && A[i]>D[j])
		{

			i++;
			j++;
		}
		else if(A[i]>D[j])
		{
			j++;
			count--;
		}
		//cout<<i<<"  "<<j<<endl;
	}
	//cout<<i<<"  "<<j<<endl;
	return max_count;
}
int main()
{
	int A[5]={900,1000, 1030,1100, 1400};
	int D[5]={930,1130, 1120,1110, 1500};
	cout<<countNumberOfStations(A,D,5)<<endl;
	return 0;
}