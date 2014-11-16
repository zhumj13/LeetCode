// BinaryTreePostorderTraversal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
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
void postorder(TreeNode *root,vector<int>&resultList){
	if(root){
		postorder(root->left,resultList);
		postorder(root->right,resultList);
		resultList.push_back(root->val);
	}
}
vector<int> postorderTraversal(TreeNode *root) {
	vector<int>resultList;
	postorder(root,resultList);
	return resultList;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

