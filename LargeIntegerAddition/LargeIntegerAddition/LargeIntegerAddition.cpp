// LargeIntegerAddition.cpp : �������̨Ӧ�ó������ڵ㡣
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
vector<int >largeIntegerAddition(vector<int >operand1,vector<int >operand2){
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
		result.push_back(operand1[i]+operand2[i]);
	}
	//�ӵ�λ����λ����
	int flag=0,temp;//��λ
	for(int i=maxSize-1;i>=0;i--){
		
		flag=(result[i]+flag)/10;
		result[i]=temp;
	}
	if(flag!=0){
		result.insert(result.begin(),flag);
	}
	//reverse(result.begin(),result.end());
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int >operand1(5,9);
	vector<int >operand2(4,9);
	largeIntegerAddition(operand1,operand2);
	return 0;
}

