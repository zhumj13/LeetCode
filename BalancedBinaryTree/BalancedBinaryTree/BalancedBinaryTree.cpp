// BalancedBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int calheight(TreeNode *root,int height){
	if(root!=NULL)
		height++;
	return height;
	if(root->left!=NULL){
		calheight(root->left,height);
	}
	if(root->right!=NULL){
		calheight(root->right,height);
	}

}
bool calBalanced(TreeNode *root,int height){

}
bool isBalanced(TreeNode *root) {
	if(root==NULL) return true;
	int height=0;

}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

