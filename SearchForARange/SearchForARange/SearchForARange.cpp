// SearchForARange.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
//Ҫ��logn�����򣬶��ֲ���
//1���ҵ������ӽ�target����
//2���ҵ��ұ���ӽ�target����
//3���ϲ�
vector<int> searchRange(int A[], int n, int target) {
	int l,r,middle,leftmost,rightmost;
	l=0;
	r=n-1;
	while(l<=r){
		middle=(l+r)/2;
		if(A[middle]>=target){
			r=middle-1;
		}else{
			l=middle+1;
		}
	}
	leftmost=l;

}
int _tmain(int argc, _TCHAR* argv[])
{
	int  A[]={5};
	searchRange(A,1,5);
	return 0;
}

