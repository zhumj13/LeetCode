// PathSum.cpp : 定义控制台应用程序的入口点。
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
bool calPathSum(TreeNode *root,int sum,int total){
	if(root!=NULL&&root->left==NULL&&root->right==NULL){
		total+=root->val;
		if(total==sum){
			return true;
		}else{
			return false;
		}
	}else{
		if(root!=NULL&&(calPathSum(root->left,sum,total+root->val)||calPathSum(root->right,sum,total+root->val))){
			return true;
		}else{
			return false;
		}
	}

}
bool hasPathSum(TreeNode *root, int sum) {
	int total=0;
	return calPathSum(root,sum,total);
}
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode temp1(1),*test1=&temp1,temp2(2),*test2=&temp2,temp3(3),*test3=&temp3,temp4(4),*test4=&temp4
		,temp5(5),*test5=&temp5,temp6(6),*test6=&temp6;
	test1->left=test2;
	test1->right=test3;
	test2->left=test4;
	test2->right=test5;
	test3->left=test6;
	cout<<hasPathSum(test1,11)<<endl;
	return 0;
}


