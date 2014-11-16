// BestTimeToBuyAndSellStockIII.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//ÿ��һ�ξͼ�¼һ�µ�ĿǰΪֹ��������flag��¼�����������һֱ�������������ֹ�ٷ���һ��maxProfit
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


