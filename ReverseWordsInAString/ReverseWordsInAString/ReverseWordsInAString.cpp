// ReverseWordsInAString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//考虑前后括号的情况，烦球死
void reverseWords(string &s) {
	string sEle="";
	vector<string>result;
	string str;
	//将前后讨厌的括号去掉
	int left=0,right=s.length()-1;
	//边界条件
	while(left<=s.length()-1&&s[left]==' '){
		left++;
	}
	while(right>=0&&s[right]==' '){
		right--;
	}
	if(left<=right){
		for(int i=left;i<=right;i++){
			if(s[i]==' '){
				if(sEle!=""){
					result.push_back(sEle);
					sEle="";
				}
			}else{
				sEle+=s[i];
			}
		}
		result.push_back(sEle);
		for(int i=result.size()-1;i>=1;i--){
			str+=result[i];
			str+=" ";
		}
		str+=result[0];
		//s=str;
	}
	s=str;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string s="   a   b ";
	reverseWords(s);
	return 0;
}

