// findMaxDis.cpp : 定义控制台应用程序的入口点。
//
/*
定义一个无序数组中两个数之间的Dis只能是前面的数减后面的数，求这个数组中的最大Dis
分析：使用动态规划的方式求以每个元素为减数的最大值Dis[i]=max{A[j]|0=<j<=i-1}-A[i],我们将max{A[j]|0=<j<=i-1}
的值记录下来这样就可以不用在遍历求了，故整个算法的复杂度为O(n)
*/
#include "stdafx.h"
#include<iostream>
using namespace std;
int findMaxDis(int A[],int n){
	//定义最大的距离
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

