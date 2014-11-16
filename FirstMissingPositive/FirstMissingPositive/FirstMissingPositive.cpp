// FirstMissingPositive.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;
//���⣺��һ�����飬��1��n�������һ��û���������г��ֵ�����
/*
��Ŀ�����һ�У�Ҫ��O(n)ʵ���ϰ�ʾ����hash��������˵Ҫcontant space����û���ٿ��¿ռ�����hash��
���������Ŀ�д������1��n�����ݣ��ṩ��һ�������������ͬʱ����hash��Ŀ����ԡ�
1��ɨ���������飬�����еķ�������Ϊn+2
2��ɨ���������飬�����е���A[i]��Ӧ��λ��A[i]-1������Ϊ����������ɨ��ʱ��Ҫע��ɨ����������abs
3��ɨ���������飬����λ�ö�Ӧ����>=0�򷵻�i+1
*/
int firstMissingPositive(int A[], int n) {
	for(int i=0;i<n;i++){
		if(A[i]<=0){
			A[i]=n+2;
		}
	}
	for(int i=0;i<n;i++){
		if(abs(A[i])-1<n&&abs(A[i])-1>=0&&A[abs(A[i])-1]>0)
			A[abs(A[i])-1]=-A[abs(A[i])-1];
	}
	int i=0;
	for(;i<n;i++){
		if(A[i]>=0){
			return i+1;
		}
	}
	return i+1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={0,1,2};
	cout<<firstMissingPositive(A,3)<<endl;
	return 0;
}

