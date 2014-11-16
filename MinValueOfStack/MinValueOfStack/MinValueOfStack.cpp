// MinValueOfStack.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
����һ��ջ�������O(1)��ʱ�����ҵ���Сֵ������ʹ�ø����ռ䡣
*/
#include "stdafx.h"
#include<iostream>
using namespace std;
struct StackNode{
	int val;
	StackNode *top;
	StackNode *next;
	StackNode(int x):val(x),top(NULL),next(NULL){};
};
StackNode *minTop;
StackNode *top;
//��ջ topΪ��ǰջ��
void stackPush(int val){
	if(top==NULL){
		StackNode *newNode=new StackNode(val);
		top=newNode;
		//���´����Сֵ��ջ
		minTop=newNode;
	}else{
		//ͷ�巨
		StackNode *newNode=new StackNode(val);
		newNode->next=top;
		top=newNode;
		//���´����Сֵ��ջ
		if(minTop==NULL){
			StackNode *newMinNode=new StackNode(val);
			minTop=newMinNode;
		}else{
			if(val<=minTop->val){
				StackNode *newMinNode=new StackNode(val);
				newMinNode->next=minTop;
				minTop=newMinNode;
			}
		}
	}
}
//��ջ topΪ��ǰ��ջ��
int stackPop(){
	if(top==NULL){
		return -1;
	}else{
		int val=top->val;
		top=top->next;
		//���´����Сֵ��ջ
		if(!minTop==NULL){
			if(val==minTop->val){
				minTop=minTop->next;
			}
		}
		return val;
	}
}
//��ǰջ�е���Сֵ��topΪҪ���ջ��ջ����minTopΪ�����ռ䣨���������Сֵ����ջ��
int minValueOfStack(){
	if(minTop!=NULL){
		return minTop->val;
	}else{
		return -1;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	stackPush(5);
	cout<<minValueOfStack()<<endl;
	stackPush(3);
	cout<<minValueOfStack()<<endl;
	stackPush(1);
	cout<<minValueOfStack()<<endl;
	stackPush(2);
	cout<<minValueOfStack()<<endl;
	stackPush(1);
	cout<<minValueOfStack()<<endl;
	stackPush(1);
	cout<<minValueOfStack()<<endl;
	stackPop();
	cout<<"1 "<<minValueOfStack()<<endl;
	stackPop();
	cout<<"2 "<<minValueOfStack()<<endl;
	stackPop();
	cout<<"3 "<<minValueOfStack()<<endl;
	stackPop();
	cout<<"4 "<<minValueOfStack()<<endl;
	stackPop();
	cout<<"5 "<<minValueOfStack()<<endl;
	stackPop();
	cout<<"6 "<<minValueOfStack()<<endl;
	return 0;
}

