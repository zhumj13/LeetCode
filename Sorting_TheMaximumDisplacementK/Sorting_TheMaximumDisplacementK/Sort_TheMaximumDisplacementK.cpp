// Sorting_TheMaximumDisplacementK.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
/*由大到小排序一个数组，排序前后每个元素移动的位移不会超过K，求复杂度最小的排序方法。
分析：一般基于比较的方法是nlg(n),但没有利用到位移最多为k的属性。我们知道排序后第一个元素一定是前k个元素中最大的，
同理第二个元素一定是前k+1个元素中最大的。。。。所以我们构建一个大顶堆，每次取root一定是当前最大的。
这样复杂度就可以达到O(nlgk)
*/
//k个元素的堆 保持堆的性质
void maxHeapIfy(int A[],int k,int i){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<k&&A[l]>A[i]){
		largest=l;
	}
	if(r<k&&A[r]>A[i]){
		largest=r;
	}
	if(largest!=i){
		swap(A[largest],A[i]);
		maxHeapIfy(A,k,largest);
	}
}
//k个元素的堆 构建最大堆
void buildMaxHeap(int A[],int k){
	for(int i=k/2-1;i>=0;i--){
		maxHeapIfy(A,k,i);
	}
}
//排序
void sort_TheMaximumDisplacementK(int data[],int k,int n){
	int *temp=new int[k];
	for(int i=0;i<k;i++){
		temp[i]=data[i];
	}
	int i=0;
	int j=k;
	do{
		buildMaxHeap(temp,k);
		data[i++]=temp[0];
		temp[0]=data[j++];
		maxHeapIfy(temp,k,0);
	}while(j<n);
	//调用堆排序
	int len=k;
	for(int m=k-1;m>=1;m--){
		data[i++]=temp[0];
		swap(temp[0],temp[m]);
		maxHeapIfy(temp,--len,0);
	}
	data[i++]=temp[0];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int data[]={6,4,1,5,3,2};
	sort_TheMaximumDisplacementK(data,4,6);
	return 0;
}

