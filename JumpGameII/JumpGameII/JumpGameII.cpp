// JumpGameII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

//每个元素都由它前面的所有点的情况决定，前面有点能够被从第一个点到达，且该点能到当前点，故两层循环
int jump(int A[], int n) {
	bool *sum=new bool[n]();
	int *count=new int[n];
	for(int i=0;i<n;i++){
		count[i]=INT_MAX;
	}
	sum[0]=1;
	count[0]=0;  
	for(int i=1;i<n;i++){
		if (A[i]<A[i-1]&&i<n-1)// this optimization is important  
			continue;
		for(int j=i-1;j>=0;j--){
			if(j+A[j]>=i&&sum[j]==1){
				sum[i]=1;
				count[i]=min(count[i],count[j]+1);
			}
		}
	}
	return count[n-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={1,3,2,1,4};
	cout<<jump(A,3)<<endl;
	return 0;
}

