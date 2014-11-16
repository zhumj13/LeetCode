// SetMatrixZeroes.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
/*��������ֱ���뵽�ľ��Ǳ����þ���ÿ����0�Ͱ������ڵ��к���ȫ����0�������Ǵ�ģ�
��Ϊ�����������µ�0�������С���һ���Ƚ������ൽ�ķ����ǣ���������
ÿ����һ��0Ԫ�ؾͰ������ڵ��к��б������������ٱ���matrix��
��ĳԪ�ص��л������±걻��ǣ�����Ϊ0�����ַ���ʵ�ַ��㣬������ռ临�Ӷ�ΪO(m+n)��*/
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

