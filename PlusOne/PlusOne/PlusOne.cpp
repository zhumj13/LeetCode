// PlusOne.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
//��������vectorʵ�ִ������ӷ�
vector<int> plusOne(vector<int> &digits) {
	int add=1,key;
	for(int i=digits.size()-1;i>=0;i--){
		key=digits[i];
		digits[i]=(key+add)%10;
		add=(key+add)/10;
	}
	if(add!=0){
		digits.insert(digits.begin(),add);
	}
	return digits;
}
int _tmain(int argc, _TCHAR* argv[])
{
		vector<int> num;
	num.push_back(9);
	num.push_back(9);
	num.push_back(9);
	plusOne(num);
	return 0;
}

