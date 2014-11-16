// TrappingRainWater.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
/*思路：算法很简单，核心思想是：对某个值A[i]来说，能trapped的最多的water取决于在i之前最高的值leftMostHeight[i]和在i右边的最高的值rightMostHeight[i]。
（均不包含自身）。如果min(left,right) > A[i]，那么在i这个位置上能trapped的water就是min(left,right) – A[i]。有了这个想法就好办了，
第一遍从左到右计算数组leftMostHeight，第二遍从右到左计算rightMostHeight，在第二遍的同时就可以计算出i位置的结果了，
而且并不需要开空间来存放rightMostHeight数组。*/
int trap(int A[], int n) {
	int *leftMost=new int[n](),*rightMost=new int[n](),sum=0;
	leftMost[0]=A[0];
	for(int i=1;i<n;i++){
		leftMost[i]=max(leftMost[i-1],A[i]);
	}
	rightMost[n-1]=A[n-1];
	for(int i=n-2;i>=0;i--){
		rightMost[i]=max(rightMost[i+1],A[i]);
	}
	for(int i=0;i<n;i++){
		if(min(leftMost[i],rightMost[i])>A[i]){
			sum+=min(leftMost[i],rightMost[i])-A[i];
		}
	}
	return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={0,2,0};
	cout<<trap(A,3)<<endl;
	return 0;
}

