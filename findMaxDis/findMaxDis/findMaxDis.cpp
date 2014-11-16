// findMaxDis.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
����һ������������������֮���Disֻ����ǰ��������������������������е����Dis
������ʹ�ö�̬�滮�ķ�ʽ����ÿ��Ԫ��Ϊ���������ֵDis[i]=max{A[j]|0=<j<=i-1}-A[i],���ǽ�max{A[j]|0=<j<=i-1}
��ֵ��¼���������Ϳ��Բ����ڱ������ˣ��������㷨�ĸ��Ӷ�ΪO(n)
*/
#include "stdafx.h"
#include<iostream>
using namespace std;
int findMaxDis(int A[],int n){
	//�������ľ���
	int maxDis=INT_MIN;
	int maxFore=A[0];
	int *dis=new int[n]();
	for(int i=1;i<n;i++){
		dis[i]=maxFore-A[i];
		maxFore=max(maxFore,A[i]);
		maxDis=max(maxDis,dis[i]);
	}
	return maxDis;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={12,3,343,6,1};
	cout<<findMaxDis(A,5)<<endl;
	return 0;
}

