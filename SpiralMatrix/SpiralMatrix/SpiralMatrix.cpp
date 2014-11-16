// SpiralMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
//做四次遍历从左到右，从上到下，从右到左，从下到上
vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> result;
	if(matrix.size()==0)return result;
	int left=0,right=matrix[0].size()-1,up=0,down=matrix.size()-1;
	while(true){
		for(int i=left;i<=right;i++){
			result.push_back(matrix[up][i]);
		}
		if(++up>down) break;
		for(int i=up;i<=down;i++){
			result.push_back(matrix[i][right]);
		}
		if(--right<left) break;
		for(int i=right;i>=left;i--){
			result.push_back(matrix[down][i]);
		}
		if(--down<up) break;
		for(int i=down;i>=up;i--){
			result.push_back(matrix[i][left]);
		}
		if(++left>right) break;
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	vector<vector<int> > matrix;
		spiralOrder(matrix);
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	matrix.push_back(num);
	num.clear();
	num.push_back(8);
	num.push_back(9);
	num.push_back(4);
	matrix.push_back(num);
	num.clear();
	num.push_back(7);
	num.push_back(6);
	num.push_back(5);
	matrix.push_back(num);
	num.clear();

	return 0;
}

