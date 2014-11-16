// SortList.cpp : 定义控制台应用程序的入口点。
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
//取得链表的长度
int getLength(ListNode *head){
	int length=0;
	while(head){
		length++;
		head=head->next;
	}
	return length;
}
//将链表分为两半
void partition(ListNode*&first,ListNode*&second,ListNode*head,int length){
	int i=0;
	ListNode *middle=head;
	first=head;
	while(i<length-1){
		i++;
		middle=middle->next;
	}
	if(middle!=NULL){
		second=middle->next;
		middle->next=NULL;
	}else{
		second=NULL;
	}

}
//将链表合并
ListNode * merge(ListNode*p,ListNode*q){
	ListNode dull(-1);
	ListNode *mergeList=&dull;
	while(p!=NULL&&q!=NULL){
		if(p->val<=q->val){
			mergeList->next=p;
			p=p->next;
			mergeList=mergeList->next;
		}else{
			mergeList->next=q;
			q=q->next;
			mergeList=mergeList->next;
		}
	}
	if(p!=NULL){
		mergeList->next=p;
		p=p->next;
	}
	if(q!=NULL){
		mergeList->next=q;
		q=q->next;
	}	
	return dull.next;
}
ListNode *sortListBranch(ListNode *head,int length){
	if(length<=1) return head;
	ListNode *first=NULL,*second=NULL,*result=NULL;
	//first=head;
	partition(first,second,head,length/2);
	first=sortListBranch(first,length/2);
	second=sortListBranch(second,length-length/2);
	result=merge(first,second);
	return result;
}
ListNode *sortList(ListNode *head) {
	int length=getLength(head);
	ListNode *result=sortListBranch(head,length);
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode temp1(-1),*test1=&temp1,temp2(-2),*test2=&temp2,temp3(-3),*test3=&temp3,temp4(-4),*test4=&temp4
		,temp5(9),*test5=&temp5,*test6=NULL;
	test5->next=test1;
	test1->next=test4;
	test4->next=test2;
	test2->next=test3;
	sortList(test6);
	return 0;
}

