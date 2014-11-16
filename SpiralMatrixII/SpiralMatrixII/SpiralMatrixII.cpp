// SpiralMatrixII.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
//做四次遍历从左到右，从上到下，从右到左，从下到上
vector<vector<int> > generateMatrix(int n) {
	vector<int>temp,resultElement;
	vector<vector<int>>result;
	if(n==0) return result;
	//增加容量，并初始化为1到n的平方
	temp.resize(pow(n,2));
	int count=1;
	for(int i=0;i<pow(n,2);i++){
		temp[i]=count++;
	}
	//给结果矩阵都初始化为0
	for(int i=0;i<n;i++){
		resultElement.clear();
		resultElement.resize(n);
		result.push_back(resultElement);
	}
	int left=0,right=n-1,up=0,down=n-1,j=0;
	while(true){
		for(int i=left;i<=right;i++){
			result[up][i]=temp[j++];
		}
		if(++up>down) break;
		for(int i=up;i<=down;i++){
			result[i][right]=temp[j++];
		}
		if(--right<left) break;
		for(int i=right;i>=left;i--){
			result[down][i]=temp[j++];
		}
		if(--down<up) break;
		for(int i=down;i>=up;i--){
			result[i][left]=temp[j++];
		}
		if(++left>right) break;
	}
	return result;
}

int main(){
	generateMatrix(3);
	return 0;
}
