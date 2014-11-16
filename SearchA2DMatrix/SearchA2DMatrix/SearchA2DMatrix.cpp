// SearchA2DMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			if(matrix[i][j]==target){
				return true;
			}
		}
	}
	return false;
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	vector<int> num;
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);
	num.push_back(4);
	vector<int> num1;
	num1.push_back(5);
	num1.push_back(6);
	num1.push_back(8);
	num1.push_back(9);
	vector<vector<int> >num2;
	num2.push_back(num);
	num2.push_back(num1);
	cout<<searchMatrix(num2,12)<<endl;
	return 0;
}

