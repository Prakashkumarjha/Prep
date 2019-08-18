#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> stockPrice;

int FindingMaimumProfitOnBuyandSellOfOneStock()
{
	int totalNumberOfdaysOfStockGiven=stockPrice.size();
	int profitAtTheParticularBuyingAndSellingDay=0;
	int maximumProfitOnBuyingAndSellingOneStock=0;
	for(int stockBuyingDay=0; stockBuyingDay<totalNumberOfdaysOfStockGiven-1;stockBuyingDay++)
	{
		for(int stockSellingDay=stockBuyingDay+1;stockSellingDay<totalNumberOfdaysOfStockGiven;stockSellingDay++)
		{
			profitAtTheParticularBuyingAndSellingDay =  stockPrice[stockSellingDay] - stockPrice[stockBuyingDay];
			if(profitAtTheParticularBuyingAndSellingDay > maximumProfitOnBuyingAndSellingOneStock)
				maximumProfitOnBuyingAndSellingOneStock = profitAtTheParticularBuyingAndSellingDay;
			profitAtTheParticularBuyingAndSellingDay=0;	
		}
	}
	return maximumProfitOnBuyingAndSellingOneStock;
}

int main()
{
	int numberOfDaysOfStockGiven,stockPriceInputOfEachDays;
	cin>>numberOfDaysOfStockGiven;
	
	for(int i=0;i<numberOfDaysOfStockGiven;i++)
	{
		cin>>stockPriceInputOfEachDays;
		stockPrice.push_back(stockPriceInputOfEachDays);
	}

	int maximumProfitOnBuyAndSellOfOneStock= FindingMaimumProfitOnBuyandSellOfOneStock();

	cout<< maximumProfitOnBuyAndSellOfOneStock<<endl;

}
