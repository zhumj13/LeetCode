// CopyListwithRandomPointer.cpp : �������̨Ӧ�ó������ڵ㡣
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
//1ʹ��β�巨��������ĸ���
//2ʹ��map���������¾ɽڵ�֮���ӳ��
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

