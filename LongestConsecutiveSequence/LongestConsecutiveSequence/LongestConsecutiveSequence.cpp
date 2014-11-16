// LongestConsecutiveSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include <algorithm> 
#include<iostream>
#include<unordered_set>
using namespace std;
//将所有的数加入到一个集合中，然后在查找连续的数的个数
int longestConsecutive(vector<int> &num) {
	unordered_set<int >numSet;
	for(int i=0;i<num.size();i++){
		numSet.insert(num[i]);
	}
	int maxCount=0;
	int count=1;
	for(int i=0;i<num.size();i++){
		int key=num[i];
		int left=key-1;
		int right=key+1;
		count=1;
		while(numSet.find(left)!=numSet.end()){
			count++;
			numSet.erase(left);
			left--;
		}
		while(numSet.find(right)!=numSet.end()){
			count++;
			numSet.erase(right);
			right++;
		}
		maxCount=max(maxCount,count);
	}
	return maxCount;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	num.push_back(1);
	num.push_back(3);
	//num.push_back(2);
	//num.push_back(4);
	//num.push_back(5);
	//num.push_back(6);
	//num.push_back(8);
	//num.push_back(9);
	cout<<longestConsecutive(num)<<endl;
	return 0;
}

