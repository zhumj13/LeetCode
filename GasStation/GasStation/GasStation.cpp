// GasStation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
//1�Ƿ������һȦ��ֻҪ��gas���ܺ��ǲ���>cost���ܺ�
//2��������һȦ��������㣬��remain��¼��ǰgas-cost,���remain<0,��ô�ղŷ��ʵ����е㶼������Ϊ���
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

