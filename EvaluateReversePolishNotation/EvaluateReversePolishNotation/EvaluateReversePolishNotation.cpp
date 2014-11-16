// EvaluateReversePolishNotation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int evalRPN(vector<string> &tokens) {
	vector<int>num;
	vector<char>oper;
	int intSum=0;
	int num1,num2,result;
	for(int i=0;i<tokens.size();i++){
		if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
			num2=num[num.size()-1];
			num.pop_back();
			num1=num[num.size()-1];
			num.pop_back();
			if(tokens[i]=="+"){
				num.push_back(num1+num2);
			}else 	if(tokens[i]=="-"){
				num.push_back(num1-num2);
			}else 	if(tokens[i]=="*"){
				num.push_back(num1*num2);
			}else 	if(tokens[i]=="/"){
				num.push_back(num1/num2);
			}
		}else{
			//算出整数
			intSum=stoi(tokens[i]);
			num.push_back(intSum);
		}
	}
	return num[0];
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<string>tokens;
	tokens.push_back("4");
	tokens.push_back("-13");
	//tokens.push_back("5");
//	tokens.push_back("/");
	tokens.push_back("+");
	//tokens.push_back();
	//tokens.push_back();
	cout<<evalRPN(tokens)<<endl;
	return 0;
}

