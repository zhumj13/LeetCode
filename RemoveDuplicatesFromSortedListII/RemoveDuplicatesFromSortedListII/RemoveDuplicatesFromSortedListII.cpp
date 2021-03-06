// RemoveDuplicatesFromSortedListII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *deleteDuplicates(ListNode *head) {
	ListNode *q,*pre=new ListNode(-1);
	pre->next=head;
	ListNode *p=pre;
	if(head==NULL) return NULL;
	while(head!=NULL){
		if(head->next!=NULL&&head->val==head->next->val){
			q=head->next;
			while(q!=NULL&&q->val==head->val){
				head->next=head->next->next;
				q=head->next;
			}
			p->next=p->next->next;
			head=p->next;
		}else{
			head=head->next;
			p=p->next;
		}
	}
	return pre->next;
}
int _tmain(int argc, _TCHAR* argv[])
{
	    ListNode temp1(1),*test1=&temp1,temp2(1),*test2=&temp2,temp3(1),*test3=&temp3,temp4(2),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test1->next=test2;
	test2->next=test3;
	test3->next=test4;
	test4->next=test5;
	test5->next=test6;
	deleteDuplicates(test1);
	return 0;
}

