// ReverseWordsInAString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//����ǰ�����ŵ������������
void reverseWords(string &s) {
	string sEle="";
	vector<string>result;
	string str;
	//��ǰ�����������ȥ��
	int left=0,right=s.length()-1;
	//�߽�����
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

