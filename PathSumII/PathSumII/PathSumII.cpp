// PathSumII.cpp : 定义控制台应用程序的入口点。
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
//经典的递归回溯
vector<vector<int>>result;
void calPathSum(TreeNode *root,int sum,int total,vector<int> resultElement){
	if(root!=NULL&&root->left==NULL&&root->right==NULL){
		total+=root->val;
		if(total==sum){
			resultElement.push_back(root->val);
			result.push_back(resultElement);
		}
	}else{
		if(root!=NULL){
			resultElement.push_back(root->val);
			calPathSum(root->left,sum,total+root->val,resultElement);
			calPathSum(root->right,sum,total+root->val,resultElement);
		}
	}

}
vector<vector<int>> pathSum(TreeNode *root, int sum){
	vector<int> resultElement;
	int total=0;
	calPathSum(root,sum,total,resultElement);
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode temp1(1),*test1=&temp1,temp2(2),*test2=&temp2,temp3(3),*test3=&temp3,temp4(7),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test1->left=test2;
	test1->right=test3;
	test2->left=test4;
	test2->right=test5;
	test3->left=test6;
	pathSum(test1,10);
	return 0;
}

