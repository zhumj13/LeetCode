// MergeSortedArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//void merge(int A[], int m, int B[], int n) {
//	int *a=new int[m+1];
//	int *b=new int[n+1];
//	int i=0,j=0;
//	for(i=0;i<m;i++){
//		a[i]=A[i];
//	}
//	for(j=0;j<n;j++){
//		b[j]=B[j];
//	}
//	a[i]=INT_MAX;
//	b[i]=INT_MAX;
//	int *p=new int[m+n];
//	i=0;
//	j=0;
//	for(int k=0;k<m+n;k++){
//		if(a[i]<=b[j]){
//			p[k]=a[i];
//			i++;
//		}else{
//			p[k]=b[j];
//			j++;
//		}
//	}
//	A=new int[m+n];
//	swap(A,p);
//
//}
void merge(int A[], int m, int B[], int n) {  
    int i,j,k;  
    for(i=m-1,j=n-1,k=m+n-1;k>=0;--k)  
    {  
        if(i>=0&&(j<0||A[i]>B[j]))  
        {  
            A[k]=A[i--];  
        }  
        else A[k]=B[j--];  
    }  
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={1,3,3,4,8},B[]={-1,4,7,8};
	merge(A,2,B,3);
	return 0;
}

