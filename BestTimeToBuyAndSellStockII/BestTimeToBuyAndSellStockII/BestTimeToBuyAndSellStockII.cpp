// BestTimeToBuyAndSellStockII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//可以多次买进，卖出，那么每相对于前一天有增长，则都可以算作利润当中，1,2,5,6
//第一天买进，第四天卖出，和第一天买进，第二天卖出，第二天买进，第三天卖出。。。。。利润是一样的。
int maxProfit(vector<int> &prices) {
	if(prices.size()<=1) return 0;
	int maxProfit=0;
	int key=prices[0];
	for(int i=1;i<prices.size();i++){
		if(prices[i]-key>0){
			maxProfit+=prices[i]-key;
		}
		key=prices[i];
	}
	return maxProfit;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	num.push_back(8);
	num.push_back(2);
	num.push_back(2);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(8);
	num.push_back(9);
	cout<<maxProfit(num)<<endl;
	return 0;
}

