// BestTimeToBuyAndSellStockIII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int maxProfit(vector<int> &prices) {
	if(prices.size()<=1) return 0;
	int maxProfit=0;
	int key=prices[0];
	int flag;
    vector<int>profit;
	//每跌一次就记录一下到目前为止最多的利润，flag记录用来处理到最后一直增长的情况，防止少放入一次maxProfit
	for(int i=1;i<prices.size();i++){
		if(prices[i]-key>0){
			maxProfit=max(maxProfit,prices[i]-key);
			flag=1;
		}else{
			profit.push_back(maxProfit);
			key=prices[i];
			maxProfit=0;
			flag=0;
		}
	}
	if(flag==1){
		profit.push_back(maxProfit);
	}
	sort(profit.begin(),profit.end());
	if(profit.size()>=2){
		maxProfit=profit[profit.size()-1]+profit[profit.size()-2];
	}else if(profit.size()==1){
		maxProfit=profit[profit.size()-1];
	}

	return maxProfit;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	num.push_back(3);
	num.push_back(2);
	num.push_back(6);
	num.push_back(5);
	num.push_back(0);
	num.push_back(3);
	cout<<maxProfit(num)<<endl;
	return 0;
}


