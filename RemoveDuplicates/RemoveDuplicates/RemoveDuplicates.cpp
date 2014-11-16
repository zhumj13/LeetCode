// RemoveDuplicates.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int removeDuplicates(int A[], int n) {
	if(n==0) return 0;
	int count=0,key,j=1;
	for(int i=1;i<n;){
		if(A[i]==A[i-1]){
			key=A[i];
			A[j++]=A[i++];			
			while(key==A[i]){
				i++;
			}
		}else{
			A[j++]=A[i++];
		}
	}
	return j;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={1,1,1,2,2,2,3,4};
	removeDuplicates(A,8);
	return 0;
}

