// ReverseLinkedListII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseBetween(ListNode *head, int m, int n) {
	ListNode dummy(-1),*result=&dummy;
	result->next=head;
	result=result->next;
	for(int i=1;i<m;i++){
		result=result->next;
	} 
	ListNode *cur=result,*r;
	if(result->next!=NULL){
		result=result->next;
	}
	ListNode *pre=result;
	if(result->next!=NULL){
		result=result->next;
	}
	for(int i=m;i<n;i++){
		r=result->next;
		result->next=pre;
		pre=result;
		result=r;
	}
	cur->next->next=pre->next;
	cur->next=pre;
	return dummy.next;
}
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode temp1(1),*test1=&temp1,temp2(2),*test2=&temp2,temp3(3),*test3=&temp3,temp4(4),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test1->next=test2;
	test2->next=test3;
	test3->next=test4;
	test4->next=test5;
	test5->next=test6;
	reverseBetween(test1,1,3);
	return 0;
}

