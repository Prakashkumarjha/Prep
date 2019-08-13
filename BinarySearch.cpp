#include<iostream>
using namespace std;
class BinarySearch
{
	public:
		int Binary(int A[],int start,int end ,int data)
		{
			if(start<=end)
			{
				int mid=start+(end-start)/2;
				if(A[mid]==data)
				{
					//cout<<mid<<endl;
					return mid;
				}
				if(A[mid]>data)
					return Binary(A,start,mid-1,data);
			
				return Binary(A,mid+1,end,data);
			}
			return -1;
		}
};
int main()
{
	int A[]={1,2,3,4,5,6,7};
	BinarySearch binary;
	cout<<binary.Binary(A,0,6,6)<<endl;
	
}