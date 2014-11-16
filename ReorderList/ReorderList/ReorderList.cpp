// ReorderList.cpp : �������̨Ӧ�ó������ڵ㡣
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
//��ȡ����ĳ���
int getLength(ListNode *head){
	int length=0;
	while(head){
		length++;
		head=head->next;
	}
	return length;
}
//�������Ϊ����
void divideList(ListNode *head,int length,ListNode *&first,ListNode *&second){
	ListNode *middleList=head;
	first=head;
	for(int i=0;i<length-1;i++){
		middleList=middleList->next;
	}
	second=middleList->next;
	middleList->next=NULL;
}
//��������
void reverseList(ListNode *&second){
	//p��ǰָ�룬pre��ǰָ���ǰ������ǰָ�����һָ��
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
//����������ϲ�
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
//recorderList�ֲ�
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

