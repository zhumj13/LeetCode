// LargeIntegerSubtraction.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
void putZero(vector<int >&operand,int addSize){
	for(int i=1;i<=addSize;i++){
		operand.insert(operand.begin(),0);
	}
}
vector<int >LargeIntegerSubtraction(vector<int >operand1,vector<int >operand2){
		//����λ���Ƴ�һ����λ��
	int size1=operand1.size();
	int size2=operand2.size();
	int maxSize;
	if(size1<size2){
		putZero(operand1,size2-size1);
		maxSize=size2;
	}else{
	    putZero(operand2,size1-size2);
		maxSize=size1;
	}
	//�Ӹ�λ����Ϊ��
	vector<int >result;
	for(int i=0;i<maxSize;i++){
		result.push_back(operand1[i]-operand2[i]);
	}
	//�Ӹ�λ����λ����
	int flag=0,temp;//��λ
	int i=0;
	for(i=maxSize-1;i>0;i--){
		if(result[i]<0){
			result[i]=result[i]+10;
			result[i-1]=result[i-1]-1;
		}

	}
	//reverse(result.begin(),result.end());
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
    vector<int >operand1(5,1);
	vector<int >operand2(4,9);
	LargeIntegerSubtraction(operand1,operand2);
	return 0;
}

