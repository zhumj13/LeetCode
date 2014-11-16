// MinValueOfStack.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个栈，如何在O(1)的时间内找到最小值，可以使用辅助空间。
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
//入栈 top为当前栈顶
void stackPush(int val){
	if(top==NULL){
		StackNode *newNode=new StackNode(val);
		top=newNode;
		//更新存放最小值的栈
		minTop=newNode;
	}else{
		//头插法
		StackNode *newNode=new StackNode(val);
		newNode->next=top;
		top=newNode;
		//更新存放最小值的栈
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
//出栈 top为当前的栈顶
int stackPop(){
	if(top==NULL){
		return -1;
	}else{
		int val=top->val;
		top=top->next;
		//更新存放最小值的栈
		if(!minTop==NULL){
			if(val==minTop->val){
				minTop=minTop->next;
			}
		}
		return val;
	}
}
//求当前栈中的最小值，top为要求的栈的栈顶，minTop为辅助空间（存放所有最小值）的栈顶
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

