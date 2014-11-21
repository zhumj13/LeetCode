// SameTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
//˼·�� ���ڵ�ǰ���ʵ������ڵ�p,q ��4����� 1 ����NULL 2��3 ����һ��Ϊ�գ���������� 4 ��������Ϊ��
//      ��4����� ��������ֵһ����ǰ���� �Ƚ϶��ߵ����Ӻ��Һ��ӣ����Եݹ�Ľ�������4���ж��ˣ�
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

