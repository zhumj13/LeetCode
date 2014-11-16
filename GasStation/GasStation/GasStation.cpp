// GasStation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
//1是否可以跑一圈，只要看gas的总和是不是>cost的总和
//2若可以跑一圈，则求其点，用remain记录当前gas-cost,如果remain<0,那么刚才访问的所有点都不可作为起点
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int remain=0;
	int total=0;
	int index=0;
	for(int i=0;i<gas.size();i++){
		remain+=gas[i]-cost[i];
		total+=gas[i]-cost[i];
		if(remain<0){
			index=i+1;
			remain=0;
		}
	}
	return total>=0?index:-1; 
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int>gas,cost;
	gas.push_back(2);
	cost.push_back(3);
	gas.push_back(4);
	cost.push_back(4);
	cout<<canCompleteCircuit(gas,cost)<<endl;
	return 0;
}

