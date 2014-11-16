// InsertionSortList.cpp : 定义控制台应用程序的入口点。
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
//只交换对应的值，不改变链表相对的位置关系
ListNode *insertionSortList(ListNode *head) {
	if(head==NULL||head->next==NULL) return head;
	ListNode *i=head->next;
	while(i){
		ListNode *j=head;
		while(j->val<i->val){
			j=j->next;
		}
		if(j==i){
			i=i->next;
		}else{
			int val=j->val;
			j->val=i->val;
			while(j!=i){
				swap(val,j->next->val);
				j=j->next;
			}
			i=i->next;
		}
	}
	return head;
}



int _tmain(int argc, _TCHAR* argv[])
{

	ListNode temp1(3),*test1=&temp1,temp2(4),*test2=&temp2,temp3(2),*test3=&temp3,temp4(5),*test4=&temp4
		,temp5(1),*test5=&temp5,temp6(1),*test6=&temp6,*test7=NULL;
	test6->next=test5;
	test5->next=test1;
	test1->next=test4;
	test4->next=test2;
	test2->next=test3;
	insertionSortList(test7);
	return 0;
}

