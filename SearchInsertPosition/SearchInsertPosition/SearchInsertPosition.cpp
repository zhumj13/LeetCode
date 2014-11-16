// SearchInsertPosition.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int searchInsert(int A[], int n, int target) {
	if(target<=A[0]) return 0;
	for(int i=0;i<n;i++){
		if(target>A[i]&&target<=A[i+1]&&i+1<n){
			return i+1;
		}
	}
	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={1,3,5,6};
	cout<<searchInsert(A,4,5)<<endl;
	cout<<searchInsert(A,4,2)<<endl;
	cout<<searchInsert(A,4,7)<<endl;
	cout<<searchInsert(A,4,0)<<endl;
	return 0;
}

