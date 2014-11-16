// LinkedListCycle.cpp : 定义控制台应用程序的入口点。
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
//追击问题，扣圈则必有环
bool hasCycle(ListNode *head) {
	if(head==NULL||head->next==NULL){
		return false;
	}
	ListNode *fast=head->next,*slow=head;
	while(fast){
		if(fast==slow){
			return true;
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
	return false;
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
	cout<<hasCycle(test5)<<endl;
	return 0;
}

