// SymmetricTree.cpp : 定义控制台应用程序的入口点。
//
//思路： 对称树是isSameTree（相同树）的变形，只要在访问root 的左子树的时候按照先右后左的顺序 依次类似的
//      递归访问即可。
#include "stdafx.h"
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if(root!=NULL)
		{
			TreeNode *pLeftTree=root->left,*pRightTree=root->right;
			return isSameTree(pLeftTree,pRightTree);
		}
		return true;
	}
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if(p==NULL&&q==NULL)
		{
			return true;
		}
		if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))
		{
			return false;
		}
		TreeNode *pParent=p,*qParent=q;
		if(p->val==q->val)
		{
			TreeNode *pRight=p->right,*qLeft=q->left;
			if(!isSameTree(pRight,qLeft))
			{
				return false;
			}
			TreeNode *pLeft=p->left,*qRight=q->right;
			if(!isSameTree(pLeft,qRight))
			{
				return false;
			}
			return true;
		}
		return false;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode *a=new TreeNode(1);
	TreeNode *b=new TreeNode(2);
	TreeNode *c=new TreeNode(2);
	TreeNode *d=new TreeNode(3);
	TreeNode *e=new TreeNode(4);
	TreeNode *f=new TreeNode(4);
	TreeNode *g=new TreeNode(3);
	TreeNode *h=new TreeNode(5);
	TreeNode *i=new TreeNode(6);
	TreeNode *j=new TreeNode(7);
	TreeNode *k=new TreeNode(8);
	TreeNode *l=new TreeNode(8);
	TreeNode *m=new TreeNode(7);
	TreeNode *n=new TreeNode(6);
	TreeNode *o=new TreeNode(5);
	a->left=b;
	a->right=c;
	b->left=d;
	b->right=e;
	c->left=f;
	c->right=g;
	d->left=h;
	d->right=i;
	e->left=j;
	e->right=k;
	f->left=l;
	f->right=m;
	//g->left=n;
	g->right=o;
	Solution solution;
	cout<<solution.isSymmetric(a);
	return 0;
}

