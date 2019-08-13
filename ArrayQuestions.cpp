#include<iostream>
#include<vector>
using namespace std;
int missingNumber(int A[],int lengthOfArray)
{
	int sum=0;
	sum=(lengthOfArray+2)*(lengthOfArray+1);
	sum=sum/2;
	int sumOfArray=0;
	for(int i=0;i<lengthOfArray;i++)
		sumOfArray=sumOfArray+A[i];
	return (sum-sumOfArray);

}

int duplicateNumber(int A[],int lengthOfArray)
{
	int sum=0;
	sum=(lengthOfArray-1)*(lengthOfArray);
	sum=sum/2;
	int sumOfArray=0;
	for(int i=0;i<lengthOfArray;i++)
		sumOfArray=sumOfArray+A[i];
	return ((lengthOfArray-1)-(sum-sumOfArray));
}
int arrayContainNumber(int A[], int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(A[i]==x)
			return i;
	}
	return -1;
}

void findLargest(int A[],int n)
{
	int largest =A[0];
	int smallest=A[0];
	for(int i=1;i<5;i++)
	{
		if(A[i]>largest)
			largest=A[i];
		if(A[i]<smallest)
			smallest=A[i];
	}
	cout<<"largest:-"<<largest<<endl<<"smallest:-"<<smallest<<endl;
}

void pairSumEqualToNumber(int A[],int n, int x)
{
	sort(A,A+n);
	int start=0;
	int end=n-1;
	while(start<=end)
	{
		if(A[start]+A[end]>x)
		{
			end--;
		}
		else if(A[start]+A[end]<x)
		{
			start++;
		}
		else
		{
			cout<<A[start]<<"     "<<A[end]<<endl;
			start++;
			end--;
		}
	}
}

void multipleDuplicates(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i]==A[j])
				cout<<A[i]<<endl;
		}
	}
}
void removeMultipleDuplicates(int A[],int n)
{
	int B[n];
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i]==A[j])
			{
				B[k]=j;
				k++;
			}
		}
	}
	
	int j=0;
	while(j<k)
	{
		for(int i=B[j];i<n;i++)
		{
			A[i]=A[i+1];
		}
		j++;
		B[j]=B[j]-j;
		
	}
	for(int i=0;i<n-j;i++)
		cout<<A[i]<<".  ";
	
}

int elementRepetedTwice(int A[], int n)
{
	sort(A,A+n);
	int i=0;
	while(i<n-1)
	{
		if(A[i]==A[i+1])
			i=i+2;
		else
			return A[i];
	}
	if(i==n-1)
		return A[n-1];
	return -1;

}
void intersectionOfTwoSortedArray(int A[],int B[],int nA,int nB)
{
	int i=0;
	int j=0;
	while(i<nA || j<nB)
	{
		if(A[i]>B[j])
			j++;
		else if(A[i]<B[j])
			i++;
		else
		{
			cout<<A[i]<<".  ";
			i++;
			j++;
		}

	}
	
}

void commonElementInThreeSortedArray(int A[],int B[],int C[],int nA,int nB,int nC)
{
	int i=0;
	int j=0;
	int k=0;
	while(i<nA && j<nB && k<nC)
	{
		if(A[i]<B[j] && C[k]<B[j])
		{
			i++;
			k++;
		}
		else if(B[j]<A[i] && C[k]<A[i])
		{
			j++;
			k++;
		}
		else if(B[j]<C[k] && A[i]<C[k])
		{
			i++;
			j++;
		}
		else if(B[j]==C[k] && A[i]==C[k])
		{
			cout<<A[i]<<".  ";
			i++;
			j++;
			k++;
		}

		else if(B[j]==C[k] && A[i]<C[k])
			i++;

		else if(B[j]==A[i] && B[j]>C[k])
			k++;
		else
			j++;
	}
	
}
void firstRepeatingElement(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i]==A[j])
			{
				cout<<A[i]<<endl;
				return;
			}
		}
	}
}	
bool searchNumberInArray(int A[],int n ,int num)
{
	for(int i=0;i<n;i++)
	{
		if(A[i]==num)
		{
			return true;
		}
	}
	return false;
}
void firstNonRepeatingElement(int A[],int n)
{
	int B[n];
	int l=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i]==A[j])
			{
				B[l]=A[i];
				l++;
				//cout<<j<<endl;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		//cout<<A[i]<<endl;
		if(!searchNumberInArray(B, l , A[i]))
		{
			cout<<A[i]<<endl;
			return;
		}
	}
}

void findHighestandSecondHighest(int A[],int n)
{
	int highest=A[0];
	int secondhighest=0;
	for(int i=0;i<n;i++)
	{
		if(highest<A[i])
		{
			secondhighest=highest;
			highest=A[i];
		}
		else if(highest>A[i] && secondhighest<A[i])
			secondhighest=A[i];
	}
	cout<<highest<<".  "<<secondhighest<<endl;
}

void alternatePositiveNegative(int A[],int n)
{
	int B[n],C[n];
	int j=0;
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]<0)
		{
			B[j]=A[i];
			j++;
		}
		else
		{
			C[k]=A[i];
			k++;
		}
	}

	int i=0;
	int l=0;
	int m=0;
	while(l<j && m<k)
	{
		if(i%2==0 )
		{
			A[i]=B[l];
			i++;;
			l++;
		}
		else if(i%2==1 )
		{
			A[i]=C[m];
			i++;
			m++;
		}
	}
	
	while(l<j)
	{
		A[i]=B[l];
		l++;
		i++;
	}
	while(m<k)
	{
		A[i]=C[m];
		m++;
		i++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<"  ";
	}
}
void subArraySumZero(int A[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=A[i];
		if(sum!=0)
		{
			for(int j=i+1;j<n;j++)
			{
				sum=sum+A[j];
				if(sum==0)
				{
					cout<<i<<". "<<j<<endl;
				}

			}
		}
		else if (sum==0)
		{
			cout<<i<<endl;
		}
			
	}
}
int removeDuplicatesFromSortedArray(int A[],int n)
{
	int i=0;
	int length=n;
	while(i<n)
	{
		if(A[i]==A[i+1])
		{
			for(int j=i+1;j<n;j++)
			{
				A[j]=A[j+1];
			}
			//A[n--]=0;
			n--;
		}
		else
			i++;
	}
	return n;
}
void removeElementFromArray(int A[],int n,int data)
{
	int i=0;
	while(i<n)
	{
		if(A[i]==data)
		{
			for(int j=i;j<n;j++)
			{
				A[j]=A[j+1];
			}
			n--;
		}
		else 
			i++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<".   ";
	}
}
void merge(vector<int> A,vector<int> B)
{
	int i=0;
	int j=0;
	int index=0;
	int index2=0;
	int k=0;
	int m=A.size();
	int n=B.size();
	while(i<(m+n) && j<n)
	{
		cout<<m+n<<"........."<<j<<endl;
		if(A[i]>=B[j])
		{
			index=A[i];
			A[i]=B[j];
			k=i+1;
			if(i<m+j)
			{
				while(k<m+j)
				{
				//cout<<k-1<<endl;
				
					index2=A[k];
					A[k]=index;
					index=index2;
					k++;
				}
				A.push_back(index);
			}
			else
				A.push_back(index);	//cout<<A[m+n-2]<<".  ";
			i++;
			j++;
		}
		else 
		{
			i++;
		}

	}
	//cout<<A.size()<<".     "<<endl;
	for(int i=0; i<m+n; i++)
	{
		cout<<A[i]<<".  ";
	}
}

void reverseArrayInPlace(int A[],int n)
{
	
	for(int i=0;i<n/2;i++)
	{
		int var=A[i];
		A[i]=A[n-i-1];
		A[n-1-i]=var;
	}
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<". ";
	}	

}

int maxSubArraySum(int A[],int size)
{
	int max_ending_here=0;
	int max_so_far=0;
	for(int i=0;i<size;i++)
	{
		max_ending_here=max_ending_here+A[i];
		if(max_ending_here<0)
			max_ending_here=0;
		if(max_ending_here >max_so_far)
			max_so_far=max_ending_here;
	}
	return max_so_far;
}

int largestProductOfSubArray(int A[],int size)
{
	int max_ending_here=0;
	int max_so_far=0;
	for(int i=0;i<size;i++)
	{
		max_ending_here=max_ending_here*A[i];
		
		if(max_ending_here >max_so_far)
			max_so_far=max_ending_here;
	}
	return max_so_far;
}
int main()
{
	int A[]={1, 2,4, 5, 6, 7};
	int B[]={3,5,6,7};
	int C[]={1,2,3,2,1,5,4,4};
	int D[]={1,2,3,4,5};
	int E[]={2,4,5};
	int F[]={3,4,5};
	int G[]={1,-1,2,3,4,5,-2,-3};
	//subArraySumZero(G,8);
	vector<int> H;
	H.push_back(1);
	H.push_back(1);
	H.push_back(3);
	H.push_back(3);
	H.push_back(3);
	H.push_back(4);
	H.push_back(4);
	H.push_back(4);
	H.push_back(5);
	//reverseArrayInPlace(C,8);
	//removeElementFromArray(H,9,4);
	vector<int>I;
	I.push_back(2);
	I.push_back(3);
	I.push_back(3);
	I.push_back(4);
	//cout<<largestProductOfSubArray(G,8);
	//cout<<maxSubArraySum(G,8);
	merge(H,I);
	//cout<<removeDuplicatesFromSortedArray(H,9);
	//alternatePositiveNegative(G,8);
	//findHighestandSecondHighest(C,8);
	//firstNonRepeatingElement(C,8);
	//firstRepeatingElement(C,8);
	//commonElementInThreeSortedArray(D,E,F,5,3,3);
	//intersectionOfTwoSortedArray(A,B,6,4);
	//cout<<elementRepetedTwice(C,7);
	//cout<<duplicateNumber(B,6);
	//pairSumEqualToNumber(A,6,5);
	//removeMultipleDuplicates(A,8);
	//cout<<arrayContainNumber(A,5,5)<<endl;
	//cout<<largest<<endl<<smallest<<endl;
	//cout<<missingNumber(A,5);
	return 0;
}