// LinkedListCycleII.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//׷�����⣬��Ȧ����л�
/**
* Definition for singly-linked list.
*/
/*
�����ں�ɫ͹��ĵط������ˡ�
F�ߵ�·��Ӧ����S������
S = x + y
F = x + y + z + y = x + 2y + z
2*S = F
2x+2y = x + 2y + z
�õ�x = z
Ҳ���Ǵ�head������ʼ��·�� �� ������������ʼ��·��
��ô������ֻҪS��F�����ˣ�������һ����ͷ��ʼ�ߣ�һ���������ĵط���ʼ��
��������һ������ô�ٴ������ض��ǻ��Ŀ�ʼ�ڵ㣡
*/
ListNode *hasCycle(ListNode *head) {
	if(head==NULL||head->next==NULL){
		return false;
	}
	ListNode *fast=head->next,*slow=head;
	while(fast){
		if(fast==slow){
			return fast;
		}else{
			//ֻ�е�fast->next����ʱ���ſ���ʹ��fast->next->next���ʼӸ��ж�
			if(fast->next!=NULL){
				if(fast->next->next!=NULL){
					fast=fast->next->next;
				}
				else{
					fast=fast->next;
				}
			}else{
				fast=fast->next;
			}
			slow=slow->next;
		}
	}
	return NULL;
}
ListNode *detectCycle(ListNode *head) {
	ListNode *meetPosition=hasCycle(head);
	ListNode *start=head;
	if(meetPosition!=NULL){
		while(meetPosition!=start){
			meetPosition=meetPosition->next;
			start=start->next;
		}
		return meetPosition;
	}else{
		return NULL;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode temp1(1),*test1=&temp1,temp2(2),*test2=&temp2,temp3(3),*test3=&temp3,temp4(4),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test6->next=test5;
	test5->next=test1;
	test1->next=test4;
	test4->next=test2;
	test2->next=test3;
	test3->next=	test1;
	detectCycle(test6);
	return 0;
}
