// Candy.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

int candy(vector<int> &ratings) {
	int least=ratings.size();
	int *eachNum=new int[ratings.size()];
	for(int i=0;i<ratings.size();i++){
		eachNum[i]=1;
	}
	//��ǰ���,�����ھӴ�����1
	for(int i=1;i<ratings.size();i++){
		if(ratings[i]>ratings[i-1]&&eachNum[i]<=eachNum[i-1]){
			least=least+eachNum[i-1]+1-eachNum[i];
			eachNum[i]=eachNum[i-1]+1;
		}
	}
	//�Ӻ���ǰ�������ھӴ�����1
	for(int i=ratings.size()-2;i>=0;i--){
		if(ratings[i]>ratings[i+1]&&eachNum[i]<=eachNum[i+1]){
			least=least+eachNum[i+1]+1-eachNum[i];
			eachNum[i]=eachNum[i+1]+1;
		}
	}
	delete eachNum;
	return least;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ratings;
	ratings.push_back(1);
	ratings.push_back(3);
	ratings.push_back(5);
	//ratings.push_back(3);
	//ratings.push_back(2);
	//ratings.push_back(2);
	//ratings.push_back(1);
	cout<<candy(ratings);
	return 0;
}

