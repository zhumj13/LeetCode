// LengthOfLastWord.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(const char *s) {
	if(strlen(s)==0) return 0;
	int count=0,sum=count;
	for(int i=0;i<strlen(s);i++){
		if(s[i]==' '){
			if(count!=0)
				sum=count;
			count=0;
		}else{
			count++;
		}
	}
	if(count!=0)
		return count;
	else
		return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string a="safaf ";
	const char *s=a.c_str();
	cout<<lengthOfLastWord(s);
	return 0;
}

