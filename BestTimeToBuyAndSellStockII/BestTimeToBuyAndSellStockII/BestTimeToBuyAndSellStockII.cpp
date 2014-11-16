// BestTimeToBuyAndSellStockII.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//���Զ���������������ôÿ�����ǰһ�����������򶼿������������У�1,2,5,6
//��һ��������������������͵�һ��������ڶ����������ڶ����������������������������������һ���ġ�
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

