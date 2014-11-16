// SetMatrixZeroes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
/*分析：最直接想到的就是遍历该矩阵，每遇到0就把它所在的行和列全部置0，但这是错的，
因为这样会引入新的0到矩阵中。下一个比较容易相到的方法是：遍历矩阵，
每遇到一个0元素就把它所在的行和列标记起来，最后再遍历matrix，
若某元素的行或者列下标被标记，则置为0，这种方法实现方便，但是其空间复杂度为O(m+n)。*/
void setZeroes(vector<vector<int> > &matrix) {
	int rows=matrix.size();
	int cols=matrix[0].size();
	int *rowstemp=new int[rows]();
	int *colstemp=new int[cols]();
	int flag=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(matrix[i][j]==0){
				rowstemp[i]=1;
				colstemp[j]=1;
			}
		}
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(rowstemp[i]==1||colstemp[j]==1){
				matrix[i][j]=0;
			}
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num;
	num.push_back(0);
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
	setZeroes(num2);
	return 0;
}

