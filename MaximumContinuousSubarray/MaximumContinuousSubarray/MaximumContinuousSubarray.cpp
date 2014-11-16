// MaximumContinuousSubarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
//暴力法，O(n2)

int maximumContinuousSubarray(int A[],int n){
	int sum=INT_MIN,sumElement;
	for(int i=0;i<n;i++){
		sumElement=0;
		for(int j=i+1;j<n;j++){
			sumElement+=A[j];
			sum=max(sumElement,sum);
		}
	}
	return sum;
}

//动态规划方法，O(n) 设b[j]表示第j处，以a[j] 结尾的子序列的最大和。则b[j] = max(a[j] + b[j-1] , a[j]) ，而我们的所求的答案，就是从1- n对b数组求最大值。
int maximumContinuousSubarray(int A[],int n){
	int sum=A[0];
	int *b=new int[n];
	b[0]=A[0];
	for(int i=1;i<n;i++){
		b[i]=max(A[i]+b[i-1],A[i]);
		sum=max(b[i],sum);
	}
	return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	cout<<maximumContinuousSubarray(A,16);
	return 0;
}

