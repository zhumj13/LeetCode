// UniquePathsII.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//类似动态规划 sum[i][j]=sum[i-1][j]+sum[i][j-1]
//每一个格子由它的左边格子和上边格子决定，故第一行和第一列可分别被其左边的格子和上边的格子初始化
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int rows=obstacleGrid.size();
	int cols=obstacleGrid[0].size();
	int **sum=new int*[rows];
	for(int i=0;i<rows;i++){
		sum[i]=new int[cols]();
	}
	//sum[0][0]=obstacleGrid[0][0];
	if(obstacleGrid[0][0]!=1) sum[0][0]=1;
	for(int i=1;i<rows;i++){
		if(obstacleGrid[i][0]!=1)
			sum[i][0]=sum[i-1][0]+obstacleGrid[i][0];
	}
	for(int j=1;j<cols;j++){
		if(obstacleGrid[0][j]!=1)
			sum[0][j]=sum[0][j-1]+obstacleGrid[0][j];
	}
	for(int i=1;i<rows;i++){
		for(int j=1;j<cols;j++){
			if(obstacleGrid[i][j]!=1)
				sum[i][j]=sum[i-1][j]+sum[i][j-1];
		}
	}
	return sum[rows-1][cols-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	vector<vector<int> > obstacleGrid;

	num.push_back(0);
	num.push_back(1);
	//num.push_back(0);
	obstacleGrid.push_back(num);
	//num.clear();
	//num.push_back(0);
	//num.push_back(1);
	//num.push_back(0);
	//obstacleGrid.push_back(num);
	//num.clear();
	//num.push_back(0);
	//num.push_back(0);
	//num.push_back(0);
	//obstacleGrid.push_back(num);
	//num.clear();
	uniquePathsWithObstacles(obstacleGrid);
	return 0;
}


