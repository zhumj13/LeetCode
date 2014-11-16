// JumpGame.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//每个元素都由它前面的所有点的情况决定，前面有点能够被从第一个点到达，且该点能到当前点，故两层循环
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

