// SumRootToLeafNumbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
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
//递归，只有在是叶子节点的时候才会求总和total,其他的每往下走一层则都乘10
int calSum(TreeNode *root,int sum,int &total){
	if(root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL){
		sum+=root->val;
		total+=sum;
	}else{
		sum=(sum+root->val)*10;
		calSum(root->left,sum,total);
		calSum(root->right,sum,total);
	}
	return sum;
}
int sumNumbers(TreeNode *root) {
	int sum=0,total=0;
	calSum(root,sum,total);
	return total;
}
int _tmain(int argc, _TCHAR* argv[])
{
	    TreeNode root(0);  
    TreeNode *r;  
    TreeNode l1(6);  
    TreeNode l2(2);  
    TreeNode r1(4);  
    TreeNode r2(5);  
  
    r=&root;  
    root.right = &r1;  
    root.right->right = &r2;  
    root.left = &l1;  
    root.left->left = &l2;  
    cout<<sumNumbers(r)<<endl;  
	return 0;
}

