// MaximumContinuousSubarray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
//��������O(n2)

int maximumContinuousSubarray(int A[],int n){
	int sum=INT_MIN,sumElement;
	for(int i=0;i<n;i++){
		sumElement=0;
		for(int j=i+1;j<n;j++){
			sumElement+=A[j];
			sum=max(sumElement,sum);
		}
	}
	return sum;
}

//��̬�滮������O(n) ��b[j]��ʾ��j������a[j] ��β�������е����͡���b[j] = max(a[j] + b[j-1] , a[j]) �������ǵ�����Ĵ𰸣����Ǵ�1- n��b���������ֵ��
int maximumContinuousSubarray(int A[],int n){
	int sum=A[0];
	int *b=new int[n];
	b[0]=A[0];
	for(int i=1;i<n;i++){
		b[i]=max(A[i]+b[i-1],A[i]);
		sum=max(b[i],sum);
	}
	return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	cout<<maximumContinuousSubarray(A,16);
	return 0;
}

