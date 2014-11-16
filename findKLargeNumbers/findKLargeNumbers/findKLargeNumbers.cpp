// findKLargeNumbers.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//����1�����ÿ��������˼�� 
/*
���Ӷȷ�����
T(n)=T(n/2)+O(1) 
T(n)=O(lgn)
*/
int partition(int A[],int p,int q){
	int key=A[q];
	int j=p,i=p-1;
	for(j;j<q;j++){
		if(A[j]>=key){
			swap(A[++i],A[j]);
		}
	}
	swap(A[++i],A[q]);
	return i;
}
//���δ���
int findKLargeNumbers_1(int A[],int n,int k){
	if(k>n){
		return -1;
	}
	int p=0,q=n-1;
	while(1){
		int index=partition(A,p,q);
		if(index==k-1){
			return A[index];
		}else if(index<k-1){
			p=index+1;
		}else{
			q=index-1;
		}
	}

}
//����2�����ö������˼��
/*�㷨������
��������ȡ��N��Ԫ���е�ǰK��Ԫ��������һ����K��Ԫ����ɵ�С���󣩶��ѣ�
�����Ѷ�Ԫ�ر��ǵ�ǰ�Ѷ�ȡԪ���еĵ�K��С���ߣ�Ȼ��
���ζ�ȡʣ�µ�N-K��Ԫ�أ����������е�ÿ��Ԫ��x����x���ڣ�С�ڣ���ǰ�ĶѶ�Ԫ�أ�
�򽫶Ѷ�Ԫ���滻Ϊx�����ԶѶ������µ����ѣ��������ڶ�ȡ������Ԫ�غ�
���е�K��Ԫ�ؼ�Ϊ��N�����е�ǰK�����С��Ԫ�أ�ͬʱ�Ѷ�Ԫ��Ϊ��N�����еĵ�K��С��Ԫ�ء�
*/
/*
���Ӷȣ�n-k��lgk +O(k��
O(k�� ���� ����n-k��lgk ���ֶѵ�����
*/
//���ֶѵ�����
void minHeapIfy(int A[],int n,int i){
	int l=2*i+1;
	int r=2*i+2;
	int little;
	if(l<n&&A[l]<A[i]){
		little=l;
	}else{
		little=i;
	}
	if(r<n&&A[r]<A[little]){
		little=r;
	}
	if(little!=i){
		swap(A[i],A[little]);
		minHeapIfy(A,n,little);
	}
}
//������С��
void buildMinHeapIfy(int A[],int n){
	for(int i=n/2-1;i>=0;i--){
		minHeapIfy(A,n,i);
	}
}
//�ҵ���k�����
int findKLargeNumbers_2(int A[],int n,int k){
	int *B=new int(k);
	for(int i=0;i<k;i++){
		B[i]=A[i];
	}
	buildMinHeapIfy(B,k);
	for(int i=k;i<n;i++){
		if(A[i]>B[0]){
			B[0]=A[i];
			minHeapIfy(B,k,0);
		}
	}
	return B[0];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={1,3,3,5,2,5,6,2};
	//cout<<findKLargeNumbers_1(A,8,3)<<endl;
	cout<<findKLargeNumbers_2(A,8,3)<<endl;
	return 0;
}

