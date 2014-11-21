// ValidateBinarySearchTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
//思路：因为二叉查找树满足条件是中序遍历是递增的关系，所以用这个思路完成。
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
	vector<int> bstArr;
public:
	bool isValidBST(TreeNode *root) {
		//return isValidBST(root,NULL,0);
		middleTravers(root);
		return isValidBST(bstArr);
	}
	void middleTravers(TreeNode *root)
	{
		if(root==NULL)
			return;
		TreeNode*left=root->left,*right=root->right;
		middleTravers(left);
		bstArr.push_back(root->val);
		middleTravers(right);
	}
	bool isValidBST(vector<int> bstArr)
	{
		if(bstArr.size()==0)
			return true;
		int temp=bstArr[0];
		for(int i=1;i<bstArr.size();i++)
		{
			if(temp<bstArr[i])
			{
				temp=bstArr[i];
				continue;
			}
			return false;
		}
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	TreeNode *a=new TreeNode(3);
	TreeNode *b=new TreeNode(1);
	TreeNode *c=new TreeNode(5);
	TreeNode *d=new TreeNode(0);
	TreeNode *e=new TreeNode(2);
	TreeNode *f=new TreeNode(4);
	TreeNode *g=new TreeNode(6);
	TreeNode *h=new TreeNode(3);
	//TreeNode *i=new TreeNode(9);
	//TreeNode *j=new TreeNode(10);
	//TreeNode *k=new TreeNode(11);
	//TreeNode *l=new TreeNode(12);
	//TreeNode *m=new TreeNode(13);
	//TreeNode *n=new TreeNode(14);
	//TreeNode *o=new TreeNode(15);
	a->left=b;
	a->right=c;
	b->left=d;
	b->right=e;
	c->left=f;
	c->right=g;
	//d->left=h;
	//d->right=i;
	//e->left=j;
	e->right=h;
	//f->left=l;
	//f->right=m;
	//g->left=n;
	//g->right=o;
	cout<<solution.isValidBST(NULL);
	return 0;
}

