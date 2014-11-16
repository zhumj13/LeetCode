// BestTimeToBuyAndSellStock.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//股票的利润发生在后面的股票-前面的，若此时差为负，说明此刻的股票相对是最低的那么等到后来最高的时候，就可能卖出最高价
int maxProfit(vector<int> &prices) {
	if(prices.size()<=1) return 0;
	int maxProfit=0;
	int key=prices[0];
	for(int i=1;i<prices.size();i++){
		if(prices[i]-key>0){
			maxProfit=max(maxProfit,prices[i]-key);
		}else{
			key=prices[i];
		}
	}
	return maxProfit;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	//num.push_back(8);
	//num.push_back(2);
	//num.push_back(2);
	//num.push_back(4);
	//num.push_back(5);
	//num.push_back(6);
	//num.push_back(8);
	//num.push_back(9);
	cout<<maxProfit(num)<<endl;
	return 0;
}

