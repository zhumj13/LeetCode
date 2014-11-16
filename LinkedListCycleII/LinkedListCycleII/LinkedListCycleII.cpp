// LinkedListCycleII.cpp : 定义控制台应用程序的入口点。
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
//追击问题，扣圈则必有环
/**
* Definition for singly-linked list.
*/
/*
假设在红色凸起的地方相遇了。
F走的路程应该是S的两倍
S = x + y
F = x + y + z + y = x + 2y + z
2*S = F
2x+2y = x + 2y + z
得到x = z
也就是从head到环开始的路程 ＝ 从相遇到环开始的路程
那么。。。只要S和F相遇了，我们拿一个从头开始走，一个从相遇的地方开始走
两个都走一步，那么再次相遇必定是环的开始节点！
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
			//只有当fast->next存在时，才可以使用fast->next->next，故加个判断
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
