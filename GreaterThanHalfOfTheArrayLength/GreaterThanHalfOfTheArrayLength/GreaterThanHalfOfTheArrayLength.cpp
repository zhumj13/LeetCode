// GreaterThanHalfOfTheArrayLength.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

/*
数组中有一个数字出现的次数超过了数组长度的一半，找出这个数时间复杂度为O(n)，空间复杂度为O(1)
分析：每遇到2个不同的数，就删除，剩下的就是那个出现次数超过一半的数字。
*/
int greaterThanHalfOfTheArrayLength(int A[],int n){
	int count=0;
	int key;
	for(int i=0;i<n-1;){
		if(A[i]==A[i+1]){
			count++;
			key=A[i];
			i+=2;
		}else{
			count--;
			
		}
	}
	return 0;
}
int findSingle1(int a[] ,int len)//一遍扫描法
{
	int tmp = a[0];
	int count = 1;
	for(int i=1;i<len;i++)
	{
		if(a[i] == tmp)
			count++;
		else{
			count--;
		}
		if(count == 0)
		{	
			tmp = a[i];
			count++;
			continue;
		}

	}
	return tmp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={2,1,2,2,2,1,1,1,3,1,1,4};
	cout<<findSingle1(a,11)<<endl;
	return 0;
}

