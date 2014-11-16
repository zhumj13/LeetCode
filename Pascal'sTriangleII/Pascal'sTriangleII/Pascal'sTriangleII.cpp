// Pascal'sTriangleII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

 vector<int> getRow(int rowIndex)  {
	vector<int> rowNum;
	int **p=new int*[rowIndex+1];
	for(int i=0;i<rowIndex+1;i++){
		p[i]=new int[i+1];
		for(int j=0;j<i+1;j++){
			p[i][j]=1;
		}
	}
	rowNum.push_back(1);
	//0行
	if(rowIndex==0){
		return rowNum;
	}
	//1行
	rowNum.push_back(1);
	if(rowIndex==1){
		return rowNum;
	}
	//>1行
	vector<int>result;
	for(int i=2;i<rowIndex+1;i++){		
		result.clear();
		result.push_back(1);
		for(int j=1;j<i;j++){
			p[i][j]=p[i-1][j-1]+p[i-1][j];
			result.push_back(p[i][j]);
		}
		result.push_back(1);
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	getRow(3);
	return 0;
}
