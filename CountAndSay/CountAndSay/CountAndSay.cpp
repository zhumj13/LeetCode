// CountAndSay.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
string countAndSay(int n) {
	if(n<=0) return NULL;
	vector<string>result;
	string temp;
	result.push_back("1");
	int count=0;
	for(int i=1;i<n;i++){
		count=1;
		string resultEle;
		for(int j=0;j<result[i-1].length();){
			if(result[i-1][j]==result[i-1][j+1]&&j+1<result[i-1].length()){
				count++;
			}else{
				stringstream ss;
				string str;
				ss<<count;
				ss>>str;
				resultEle=resultEle+str+result[i-1][j];
				count=1;
			}
			j++;
		}
		result.push_back(resultEle);
	}
	return result[n-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	countAndSay(6);
	return 0;
}

