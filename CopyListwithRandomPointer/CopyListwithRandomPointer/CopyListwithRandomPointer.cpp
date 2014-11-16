// CopyListwithRandomPointer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <map>
using namespace std;
/**
* Definition for singly-linked list with a random pointer.
*/
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
//1使用尾插法进行链表的复制
//2使用map保存两个新旧节点之间的映射
RandomListNode *copyRandomList(RandomListNode *head) {
	if(head==NULL) return head;
	RandomListNode dummy(-1),*copyList=&dummy,*tempHead=head;
	map<RandomListNode*,RandomListNode*>oldNew;
	while(tempHead!=NULL){
		RandomListNode *temp = new RandomListNode(tempHead->label);
		temp->next=NULL;
		oldNew[tempHead]=temp;
		copyList->next=temp;
		copyList=copyList->next;
		tempHead=tempHead->next;
	}
	copyList=&dummy;
	copyList=copyList->next;
	tempHead=head;
	while(tempHead!=NULL){
		if(tempHead->random!=NULL){
			copyList->random=oldNew[tempHead->random];	
		}
		copyList=copyList->next;
		tempHead=tempHead->next;
	}
	return dummy.next;
}

int _tmain(int argc, _TCHAR* argv[])
{

	RandomListNode temp1(1),*test1=&temp1,temp2(2),*test2=&temp2,temp3(3),*test3=&temp3,temp4(4),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test6->next=test5;
	test6->random=test4;
	test5->next=test4;
	test5->random=test1;
	test4->next=test3;
	test3->next=test2;
	test2->next=test1;

	test4->random=test5;
	test3->random=test1;
	test2->random=test4;
	copyRandomList(test6);
	return 0;
}

