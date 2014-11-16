// SortColors.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
void sortColors(int A[],int n) {
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	for(int i = 0; i < n; i++){
		if(A[i] == 0){
			count0++;
		}
		if(A[i] == 1){
			count1++;
		}
		if(A[i] == 2){
			count2++;
		}
	}
	for(int i = 0; i < count0; i++){
		A[i] = 0;
	}
	for(int i = count0; i < count0+count1; i++){
		A[i] = 1;
	}
	for(int i = count0+count1; i < count0+count1+count2; i++){
		A[i] = 2;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={0,0,1,0,1,1};
	sortColors(A,6);
	return 0;
}

