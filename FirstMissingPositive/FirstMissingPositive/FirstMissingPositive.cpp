// FirstMissingPositive.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;
//题意：给一个数组，从1到n，求出第一个没有在数组中出现的数。
/*
题目的最后一行，要求O(n)实际上暗示了用hash，但是又说要contant space，就没法再开新空间来建hash。
正好这个题目中处理的是1到n的数据，提供了一个将输入的数组同时用作hash表的可能性。
1、扫描整个数组，把所有的非正数设为n+2
2、扫描整个数组，把所有的数A[i]对应的位置A[i]-1的数设为负数，则样扫描时就要注意扫描所有数的abs
3、扫描整个数组，如若位置对应的数>=0则返回i+1
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

