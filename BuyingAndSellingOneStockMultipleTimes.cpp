#include<iostream>
#include<vector>
using namespace std;
vector<int> stockprice; 

int totalProfitEarnedOnBuyingAndSellingOneStockMultipleTimes()
{
	int totalNumberOfDaysOfStockGiven=stockprice.size();
	stockprice.push_back(0);
	int totalProfitEarnedOnBuyingAndSellingStock=0,priceOfStockAtTheTimeOfBuying=0;
	bool stockPresent=false;
	for(int i=0;i<totalNumberOfDaysOfStockGiven;i++)
	{
		if(!stockPresent && stockprice[i]<stockprice[i+1])
		{
			stockPresent=true;
			priceOfStockAtTheTimeOfBuying=stockprice[i];
		}
		else if(stockPresent && stockprice[i]>stockprice[i+1])
		{
			stockPresent=false;
			
			
			totalProfitEarnedOnBuyingAndSellingStock=totalProfitEarnedOnBuyingAndSellingStock+(stockprice[i] - priceOfStockAtTheTimeOfBuying);

			priceOfStockAtTheTimeOfBuying=0;
		}
	}
	return totalProfitEarnedOnBuyingAndSellingStock;
}
int main()
{
	int totalNumberOfDaysOfStockGiven,stockPriceOfEachDay;
	cin>>totalNumberOfDaysOfStockGiven;
	for(int i=0;i<totalNumberOfDaysOfStockGiven;i++)
	{
		cin>>stockPriceOfEachDay;
		stockprice.push_back(stockPriceOfEachDay);
	}

	int totalProfitEarnedTillDate = totalProfitEarnedOnBuyingAndSellingOneStockMultipleTimes();
	cout<<totalProfitEarnedTillDate<<endl;
	return 0;
}