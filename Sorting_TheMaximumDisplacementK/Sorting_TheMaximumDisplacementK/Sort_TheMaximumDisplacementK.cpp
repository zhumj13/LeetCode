// Sorting_TheMaximumDisplacementK.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
/*�ɴ�С����һ�����飬����ǰ��ÿ��Ԫ���ƶ���λ�Ʋ��ᳬ��K�����Ӷ���С�����򷽷���
������һ����ڱȽϵķ�����nlg(n),��û�����õ�λ�����Ϊk�����ԡ�����֪��������һ��Ԫ��һ����ǰk��Ԫ�������ģ�
ͬ��ڶ���Ԫ��һ����ǰk+1��Ԫ�������ġ��������������ǹ���һ���󶥶ѣ�ÿ��ȡrootһ���ǵ�ǰ���ġ�
�������ӶȾͿ��ԴﵽO(nlgk)
*/
//k��Ԫ�صĶ� ���ֶѵ�����
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
//k��Ԫ�صĶ� ��������
void buildMaxHeap(int A[],int k){
	for(int i=k/2-1;i>=0;i--){
		maxHeapIfy(A,k,i);
	}
}
//����
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
	//���ö�����
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

