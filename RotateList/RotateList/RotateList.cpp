// RotateList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//遍历链表求长度
void travel(ListNode *head,int &length){
	if(head==NULL) length=0;
	ListNode *p=head;
	while(p!=NULL){
		length++;
		p=p->next;
	}
}
ListNode *rotateRight(ListNode *head, int k) {
	if(head==NULL)  return NULL;
	if(k==0) return head;
	int length=0;
	travel(head,length);
	if(k%length==0) return head;
	//找到断开节点的前驱节点
	ListNode *breakPre=head,*dummy;
	int breakcount=1;
	while(breakPre!=NULL&&breakcount<length-k%length){
		breakPre=breakPre->next;
		breakcount++;
	}
	ListNode *breakNext=breakPre->next;
	dummy=breakPre->next;
	breakPre->next=NULL;
	while(breakNext->next!=NULL&&breakNext!=NULL){
		breakNext=breakNext->next;
	}
	breakNext->next=head;
	return dummy;
}
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode temp1(1),*test1=&temp1,temp2(2),*test2=&temp2,temp3(3),*test3=&temp3,temp4(4),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test1->next=test2;
	test2->next=NULL;
	test3->next=test4;
	test4->next=test5;
	test5->next=test6;
	rotateRight(test1,3);
	return 0;
}

