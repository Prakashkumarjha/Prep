#include<iostream>
#include<vector>
using namespace std;

int sum = 100000;
vector<int> final;
void calculateMinSum(vector<int> v, vector<int> atmPresent) {
	int p1=0;
	int p2=0;
	int p3=v.size()-1;

	while(atmPresent[p1] == 0) {
		p1++;
	}

	int tempSum = 0;
	for(int i=0;i<p1;i++) {
		tempSum += (v[p1]-v[i]);
	}

	while(atmPresent[p3] == 0){
		p3--;
	}

	for(int i=v.size()-1;i>p3;i--) {
		tempSum += (v[i]-v[p3]);
	}

	p2 = p1;

	while(p2<p3) {
		p2 = p1+1;
		while(atmPresent[p2] == 0) {
			p2++;
		}
		for(int i=p1+1;i<p2;i++) {
			if(v[p2]-v[i] > v[i]-v[p1]) {
				tempSum += v[i]-v[p1];
			} else {
				tempSum += v[p2]-v[i];
			}
		}
		p1=p2;
	}

	if(sum>tempSum) {
		final = atmPresent;
		sum = tempSum;
	}
}

void atmInstallation(vector<int> v, int index, vector<int> atmPresent, int k) {
	if(index == v.size()) {
		int count1s = 0;
		for(int i=0;i<atmPresent.size();i++) {
			
			if(atmPresent[i] == 1) {
				
				count1s++;
			}
		}
		if(count1s == k) {
			calculateMinSum(v, atmPresent);
		}
		return;
	}
	atmPresent[index]=0;
	atmInstallation(v, index+1, atmPresent, k);
	atmPresent[index] = 1;
	atmInstallation(v, index+1, atmPresent, k);
}

int main()
{
	int t;
	int n;
	vector <int> v;
	vector <int>atmPresent;
	int p;
	cin>>t>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>p;
		v.push_back(p);
		atmPresent.push_back(0);
	}
	atmInstallation(v,0,atmPresent,t);
	cout<<sum<<endl;
	
	return 0;
}