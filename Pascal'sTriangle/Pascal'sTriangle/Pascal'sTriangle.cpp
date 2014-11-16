// Pascal'sTriangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<int> rowNum;
	vector<vector<int>> result;
	if(numRows==0) return result;
	int **p=new int*[numRows];
	for(int i=0;i<numRows;i++){
		p[i]=new int[i+1];
		for(int j=0;j<i+1;j++){
			p[i][j]=1;
		}
	}
	rowNum.push_back(1);
	result.push_back(rowNum);
	//1行
	if(numRows==1){
		return result;
	}
	//2行
	rowNum.push_back(1);
	result.push_back(rowNum);
	if(numRows==2){
		return result;
	}
	//>2行
	for(int i=2;i<numRows;i++){
		vector<int>temp;
		temp.clear();
		temp.push_back(1);
		for(int j=1;j<i;j++){
			p[i][j]=p[i-1][j-1]+p[i-1][j];
			temp.push_back(p[i][j]);
		}
		temp.push_back(1);
		result.push_back(temp);
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	generate(0);
	return 0;
}

