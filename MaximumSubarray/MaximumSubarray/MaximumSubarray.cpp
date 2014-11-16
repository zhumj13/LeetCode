// MaximumSubarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//s[i] = max{s[i-1]+a[i], a[i]}   i>0 && i<N;
//s[0]=a[0] 因为至少有一个元素
int maxSubArray(int A[], int n) {
	int *sum=new int[n]();
	sum[0]=A[0];
	int maxSum=sum[0];
	for(int i=1;i<n;i++){
		sum[i]=max(sum[i-1]+A[i],A[i]);
		if(sum[i]>maxSum)
			maxSum=sum[i];
	}
	return maxSum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={-2,1,-3,4,-1,2,1,-5,4};
	cout<<maxSubArray(A,9);
	return 0;
}

