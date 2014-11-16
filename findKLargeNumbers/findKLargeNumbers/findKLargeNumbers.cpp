// findKLargeNumbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//方法1：利用快速排序的思想 
/*
复杂度分析：
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
//分治处理
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
//方法2：利用堆排序的思想
/*算法描述：
我们首先取这N个元素中的前K个元素来建立一个由K个元素组成的小（大）顶堆，
这样堆顶元素便是当前已读取元素中的第K大（小）者；然后，
依次读取剩下的N-K个元素，而对于其中的每个元素x，若x大于（小于）当前的堆顶元素，
则将堆顶元素替换为x，并自堆顶至向下调整堆；这样，在读取完所有元素后，
堆中的K个元素即为这N个数中的前K个最大（小）元素，同时堆顶元素为这N个数中的第K大（小）元素。
*/
/*
复杂度（n-k）lgk +O(k）
O(k） 建堆 ，（n-k）lgk 保持堆的性质
*/
//保持堆的性质
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
//构建最小堆
void buildMinHeapIfy(int A[],int n){
	for(int i=n/2-1;i>=0;i--){
		minHeapIfy(A,n,i);
	}
}
//找到第k大的数
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

