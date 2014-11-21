// SameTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
//思路： 对于当前访问的两个节点p,q 有4种情况 1 都是NULL 2和3 其中一个为空（两种情况） 4 两个都不为空
//      第4种情况 在两者数值一样的前提下 比较二者的左孩子和右孩子（可以递归的进行上述4中判断了）
using namespace std;;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
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
			TreeNode *pLeft=p->left,*qLeft=q->left;
			if(!isSameTree(pLeft,qLeft))
			{
				return false;
			}
			TreeNode *pRight=p->right,*qRight=q->right;
			if(!isSameTree(pRight,qRight))
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
	//TreeNode *a=new TreeNode(1);
	TreeNode *b=new TreeNode(1);
	TreeNode *c=new TreeNode(1);
	TreeNode *d=new TreeNode(2);
	TreeNode *e=new TreeNode(3);
	TreeNode *f=new TreeNode(2);
	TreeNode *g=new TreeNode(3);
	TreeNode *h=new TreeNode(4);
	TreeNode *i=new TreeNode(5);
	TreeNode *j=new TreeNode(6);
	TreeNode *k=new TreeNode(7);
	TreeNode *l=new TreeNode(4);
	TreeNode *m=new TreeNode(5);
	TreeNode *n=new TreeNode(6);
	TreeNode *o=new TreeNode(7);
	//a->left=b;
	//a->right=c;
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
	g->left=n;
	g->right=o;
	Solution solution;
	cout<<solution.isSameTree(b,c)<<endl;
	return 0;
}

