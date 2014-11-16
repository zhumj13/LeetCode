// MinimumPathSum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��̬�滮 sum(i,j)=min{sum(i-1,j),sum(i,j-1)}+grid(i,j)
//ÿһ��������������߸��Ӻ��ϱ߸��Ӿ������ʵ�һ�к͵�һ�пɷֱ�����ߵĸ��Ӻ��ϱߵĸ��ӳ�ʼ��
int minPathSum(vector<vector<int> > &grid) {
	int rows=grid.size();
	int cols=grid[0].size();
	int **sum=new int*[rows];
	for(int i=0;i<rows;i++){
		sum[i]=new int[cols]();
	}
	sum[0][0]=grid[0][0];
	for(int i=1;i<rows;i++){
		sum[i][0]=sum[i-1][0]+grid[i][0];
	}
	for(int j=1;j<cols;j++){
		sum[0][j]=sum[0][j-1]+grid[0][j];
	}
	for(int i=1;i<rows;i++){
		for(int j=1;j<cols;j++){
			sum[i][j]=min(sum[i-1][j],sum[i][j-1])+grid[i][j];
		}
	}
	return sum[rows-1][cols-1];
}
int _tmain(int argc, _TCHAR* argv[])
{
		vector<int> num;
		vector<vector<int> > grid;

	num.push_back(1);
	num.push_back(2);
	num.push_back(1);
	grid.push_back(num);
	num.clear();
	num.push_back(2);
	num.push_back(1);
	num.push_back(2);
	grid.push_back(num);
	num.clear();
		num.push_back(2);
	num.push_back(2);
	num.push_back(1);
	grid.push_back(num);
	num.clear();
	minPathSum(grid);
	return 0;
}

