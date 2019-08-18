#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> stockPrice;
vector<int> stockSpanArray;

void StockSpan()
{
	
	int totalNumberOfDaysOfStockGiven=stockPrice.size();
	stack<int>s;
	s.push(0);
	stockSpanArray.push_back(1);
	for(int i=1;i<totalNumberOfDaysOfStockGiven;i++)
	{
		while(!s.empty() && stockPrice[s.top()]<=stockPrice[i])
			s.pop();
		s.empty()?stockSpanArray.push_back(i+1):stockSpanArray.push_back(i-s.top());
		s.push(i);
	}
}

void PrintStockSpanArray()
{
	int totalNumberOfDaysOfStockGiven=stockSpanArray.size();
	for(int i=0;i<totalNumberOfDaysOfStockGiven;i++)
		cout<<stockSpanArray[i]<<"  ";
	cout<<endl;
}

int main()
{
	int totalNumberOfDaysOfStockGiven,stockPriceOfOneDay;
	cin>>totalNumberOfDaysOfStockGiven;
	for(int i=0;i<totalNumberOfDaysOfStockGiven;i++)
	{
		cin>>stockPriceOfOneDay;
		stockPrice.push_back(stockPriceOfOneDay);
	}
	StockSpan();
	PrintStockSpanArray();
	return 0;
}