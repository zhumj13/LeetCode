// CombinationSumII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	vector<vector<int>>result;
	vector<int>resultEle;
	int sum=0;
	for(int i=0;i<num.size();i++){
		resultEle.clear();
		sum=0;
		for(int j=i;j<num.size();j++){
			sum+=num[j];
			if(sum>target){
				break;
			}
			resultEle.push_back(num[j]);
			if(sum==target){
				result.push_back(resultEle);
			}
		}
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>>result;
	vector<int>resultEle;
	
	vector<int> num;
	num.push_back(10);
	num.push_back(1);
	num.push_back(2);
	num.push_back(7);
	num.push_back(6);
	num.push_back(1);
	num.push_back(5);
	combinationSum2(num,8);
	return 0;
}

