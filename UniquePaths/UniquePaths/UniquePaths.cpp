// UniquePaths.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//类似动态规划 sum[i][j]=sum[i-1][j]+sum[i][j-1]
//每一个格子由它的左边格子和上边格子决定，故第一行和第一列可分别被其左边的格子和上边的格子初始化
int uniquePaths(int m, int n){
	int rows=m;
	int cols=n;
	int **sum=new int*[rows];
	for(int i=0;i<rows;i++){
		sum[i]=new int[cols]();
	}
	sum[0][0]=1;
	for(int i=1;i<rows;i++){
		sum[i][0]=sum[i-1][0];
	}
	for(int j=1;j<cols;j++){
		sum[0][j]=sum[0][j-1];
	}
	for(int i=1;i<rows;i++){
		for(int j=1;j<cols;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1];
		}
	}
	return sum[rows-1][cols-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	uniquePaths(3,3);
	return 0;
}

