// Triangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//动态规划 sum[i,j]=min{sum[i-1,j-1]+,sum[i-1][j]}+triangle[i][j],注意处理两端情况
int minimumTotal(vector<vector<int> > &triangle) {
	//int sum=0;
	int count=triangle.size();
	int **sum=new int*[count];
	for(int i=0;i<count;i++){
		sum[i]=new int[count];
	}
	sum[0][0]=triangle[0][0];
	for(int i=1;i<count;i++){
		sum[i]=new int[triangle[i].size()];
		for(int j=0;j<triangle[i].size();j++){
			if(j-1>=0&&j!=triangle[i].size()-1){
				sum[i][j]=min(sum[i-1][j-1],sum[i-1][j])+triangle[i][j];
			}else if(j-1<0){
				sum[i][j]=sum[i-1][j]+triangle[i][j];
			}else{
				sum[i][j]=sum[i-1][j-1]+triangle[i][j];
			}

		}
	}
	sort(sum[count-1],sum[count-1]+count);
	return sum[count-1][0];
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> temp;
	vector<vector<int>>triangle;
	temp.push_back(2);
	triangle.push_back(temp);
	temp.clear();

	temp.push_back(3);
	temp.push_back(4);
	triangle.push_back(temp);
	temp.clear();
	temp.push_back(6);
	temp.push_back(5);
	temp.push_back(7);
	triangle.push_back(temp);
	temp.clear();
	temp.push_back(4);
	temp.push_back(1);
	temp.push_back(8);
	temp.push_back(3);
	triangle.push_back(temp);
	temp.clear();
	cout<<minimumTotal(triangle)<<endl;
	return 0;
}

