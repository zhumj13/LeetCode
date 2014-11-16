// TrappingRainWater.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
/*˼·���㷨�ܼ򵥣�����˼���ǣ���ĳ��ֵA[i]��˵����trapped������waterȡ������i֮ǰ��ߵ�ֵleftMostHeight[i]����i�ұߵ���ߵ�ֵrightMostHeight[i]��
�������������������min(left,right) > A[i]����ô��i���λ������trapped��water����min(left,right) �C A[i]����������뷨�ͺð��ˣ�
��һ������Ҽ�������leftMostHeight���ڶ�����ҵ������rightMostHeight���ڵڶ����ͬʱ�Ϳ��Լ����iλ�õĽ���ˣ�
���Ҳ�����Ҫ���ռ������rightMostHeight���顣*/
int trap(int A[], int n) {
	int *leftMost=new int[n](),*rightMost=new int[n](),sum=0;
	leftMost[0]=A[0];
	for(int i=1;i<n;i++){
		leftMost[i]=max(leftMost[i-1],A[i]);
	}
	rightMost[n-1]=A[n-1];
	for(int i=n-2;i>=0;i--){
		rightMost[i]=max(rightMost[i+1],A[i]);
	}
	for(int i=0;i<n;i++){
		if(min(leftMost[i],rightMost[i])>A[i]){
			sum+=min(leftMost[i],rightMost[i])-A[i];
		}
	}
	return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={0,2,0};
	cout<<trap(A,3)<<endl;
	return 0;
}

