// SearchForARange.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
//要求logn且有序，二分查找
//1、找到左边最接近target的数
//2、找到右边最接近target的数
//3、合并
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

