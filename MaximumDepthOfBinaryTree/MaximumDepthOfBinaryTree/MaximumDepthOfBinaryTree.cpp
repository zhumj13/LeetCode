// MaximumDepthOfBinaryTree.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
/**
* Definition for binary tree
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxDep=INT_MIN;
void calMaxDepth(TreeNode *root,int depth){
	if(root!=NULL){
		depth++;
		if(root->left!=NULL){
			calMaxDepth(root->left,depth);
		}
		if(root->right!=NULL){
			calMaxDepth(root->right,depth);
		}
		if(root->left==NULL&&root->right==NULL){
			maxDep=max(maxDep,depth);
		}
	}
}
int maxDepth(TreeNode *root) {
	if(root==NULL){
		maxDep=0; 
	}else{
		int depth=0;
		calMaxDepth(root,depth);
	}
	return maxDep;
}
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode temp1(1),*test1=&temp1,temp2(2),*test2=&temp2,temp3(3),*test3=&temp3,temp4(4),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test1->left=test2;
	test1->right=test3;
	test2->left=test4;
	test2->right=test5;
	//test3->left=test6;
	cout<<maxDepth(test1)<<endl;

	return 0;
}
