// GreaterThanHalfOfTheArrayLength.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

/*
��������һ�����ֳ��ֵĴ������������鳤�ȵ�һ�룬�ҳ������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
������ÿ����2����ͬ��������ɾ����ʣ�µľ����Ǹ����ִ�������һ������֡�
*/
int greaterThanHalfOfTheArrayLength(int A[],int n){
	int count=0;
	int key;
	for(int i=0;i<n-1;){
		if(A[i]==A[i+1]){
			count++;
			key=A[i];
			i+=2;
		}else{
			count--;
			
		}
	}
	return 0;
}
int findSingle1(int a[] ,int len)//һ��ɨ�跨
{
	int tmp = a[0];
	int count = 1;
	for(int i=1;i<len;i++)
	{
		if(a[i] == tmp)
			count++;
		else{
			count--;
		}
		if(count == 0)
		{	
			tmp = a[i];
			count++;
			continue;
		}

	}
	return tmp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={2,1,2,2,2,1,1,1,3,1,1,4};
	cout<<findSingle1(a,11)<<endl;
	return 0;
}

