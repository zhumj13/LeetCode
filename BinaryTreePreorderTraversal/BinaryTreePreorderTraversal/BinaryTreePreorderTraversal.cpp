// BinaryTreePreorderTraversal.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
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
void preorder(TreeNode *root,vector<int>&resultList){
	//�ݹ�
	if(root){
		resultList.push_back(root->val);
		preorder(root->left,resultList);
		preorder(root->right,resultList);
	}
}
vector<int> preorderTraversal(TreeNode *root) {
	vector<int>resultList;
	preorder(root,resultList);
	return resultList;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

