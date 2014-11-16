// ReorderList.cpp : 定义控制台应用程序的入口点。
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
//获取链表的长度
int getLength(ListNode *head){
	int length=0;
	while(head){
		length++;
		head=head->next;
	}
	return length;
}
//将链表分为两半
void divideList(ListNode *head,int length,ListNode *&first,ListNode *&second){
	ListNode *middleList=head;
	first=head;
	for(int i=0;i<length-1;i++){
		middleList=middleList->next;
	}
	second=middleList->next;
	middleList->next=NULL;
}
//将链表倒置
void reverseList(ListNode *&second){
	//p当前指针，pre当前指针的前驱，当前指针的下一指针
	ListNode *p,*pre,*r;
	p=second;
	pre=NULL;
	while(p){
		r=p->next;
		p->next=pre;
		pre=p;
		p=r;
	}
	second=pre;
}
//将两个链表合并
ListNode *mergeList(ListNode *first,ListNode *second){
	ListNode temp(-1),*result=&temp;
	while(first&&second){
		result->next=first;
		first=first->next;
		result=result->next;
		result->next=second;
		second=second->next;
		result=result->next;
	}
	if(first){
		result->next=first;
	}
	return temp.next;
}
//recorderList分部
ListNode *recordList(ListNode *head,int length){
	if(length<=1) return head;
	ListNode *first,*second;
	divideList(head,(length+1)/2,first,second);
	reverseList(second);
	return mergeList(first,second);
}
void reorderList(ListNode *head) {
	 int length=getLength(head);
	 head=recordList(head,length);
}
int _tmain(int argc, _TCHAR* argv[])
{
    ListNode temp1(-1),*test1=&temp1,temp2(-2),*test2=&temp2,temp3(-3),*test3=&temp3,temp4(-4),*test4=&temp4
		,temp5(9),*test5=&temp5,temp6(1),*test6=&temp6;
	test6->next=test5;
	test5->next=test1;
	test1->next=test4;
	test4->next=test2;
	test2->next=test3;
	reorderList(test6);
	return 0;
}

