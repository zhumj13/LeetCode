// RotateImage.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
#include<vector>
using namespace std;
/*00 01 02 
  10 11 12
  20 21 22 
  ת����õ���
  20 10 00
  21 11 01
  22 12 02
  ��a[i][j]=a[n-1-j][i]*/
void rotate(vector<vector<int> > &matrix) {
	//nΪ����ʱ�����м��������ֻʣһ��Ԫ�أ�ż��ʱ��n/2����ת��
	int n=matrix.size();
	for(int i=0;i<n/2;i++){
		for(int j=i;j<n-i-1;j++){
			int temp=matrix[i][j];
			matrix[i][j]=matrix[n-1-j][i];
			matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
			matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
			matrix[j][n-1-i]=temp;
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
		vector<int> num;
		vector<vector<int> >matrix;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	matrix.push_back(num);
	num.clear();
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	matrix.push_back(num);
	num.clear();
	num.push_back(7);
	num.push_back(8);
	num.push_back(9);
	matrix.push_back(num);
	rotate(matrix);
	return 0;
}

