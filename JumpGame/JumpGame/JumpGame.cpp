// JumpGame.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//ÿ��Ԫ�ض�����ǰ������е�����������ǰ���е��ܹ����ӵ�һ���㵽��Ҹõ��ܵ���ǰ�㣬������ѭ��
bool canJump(int A[], int n) {
	bool *sum=new bool[n]();
	sum[0]=1;
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(j+A[j]>=i&&sum[j]==1){
				sum[i]=1;
				break;
			}
		}
	}
	return sum[n-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={0,3,1,1,4};
	cout<<canJump(A,5);
	return 0;
}

