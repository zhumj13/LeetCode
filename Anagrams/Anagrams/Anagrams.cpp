// Anagrams.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> anagrams(vector<string> &strs) {
	vector<string> result;
	if(strs.size()==0) return result;
	int start=0,end=0;
	bool flag;
	for(int i=0;i<strs.size();i++){
		//cout<<strs[i].length();
		if(strs[i]!=""&&strs[i].length()!=1){
			start=0;
			end=strs[i].length()-1;
			flag=true;
			while(start<=end){
				if(strs[i][start]==strs[i][end]){
					start++;
					end--;
				}else{
					flag=false;
					break;
				}
			}
			if(flag){
				result.push_back(strs[i]);
			}	
		}
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> strs;
	strs.push_back("a");
	//strs.push_back("aaa");
	//strs.push_back("aaaa");
	anagrams(strs);
	return 0;
}

