// MergeTwoSortedLists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode *dummy=new ListNode(-1),*mergeList=dummy;
	ListNode *p=l1,*q=l2;
	while(p!=NULL&&q!=NULL){
		if(p->val<=q->val){
			ListNode *temp=new ListNode(p->val);
			mergeList->next=temp;
			mergeList=mergeList->next;
			p=p->next;
		}else{
			ListNode *temp=new ListNode(q->val);
			mergeList->next=temp;
			mergeList=mergeList->next;
			q=q->next;
		}
	}
	while(p!=NULL){
			ListNode *temp=new ListNode(p->val);
			mergeList->next=temp;
			mergeList=mergeList->next;
			p=p->next;
	}
	while(q!=NULL){
		    ListNode *temp=new ListNode(q->val);
			mergeList->next=temp;
			mergeList=mergeList->next;
			q=q->next;
	}
	return dummy->next;
}
int _tmain(int argc, _TCHAR* argv[])
{
    ListNode temp1(1),*test1=&temp1,temp2(2),*test2=&temp2,temp3(3),*test3=&temp3,temp4(4),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test1->next=test3;
	test2->next=test4;
	test3->next=test5;
	test4->next=test6;
	mergeTwoLists(test1,test2);
	return 0;
}

