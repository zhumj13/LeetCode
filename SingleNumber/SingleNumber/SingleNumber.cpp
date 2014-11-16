// SingleNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include<iostream>
using namespace std;
int singleNumber(int A[], int n) {
	map<int,int>single;
	for(int i=0;i<n;i++){
		if(single.find(A[i])!=single.end()){
			single[A[i]]++;
		}else{
		    single[A[i]]=1;
		}
	}
	map<int,int>::iterator iter=single.begin();
	for(;iter!=single.end();iter++){
		if(iter->second!=3){
			return iter->first;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={1,1,1,3,3,3,4};
	cout<<singleNumber(A,7)<<endl;
	return 0;
}

