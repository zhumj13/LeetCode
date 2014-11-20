// PopulatingNextRightPointersInEachNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
struct TreeLinkNode
{
	int val;
	TreeLinkNode *left,*right,*next;
	TreeLinkNode(int x):val(x),left(NULL),right(NULL),next(NULL){}
};
class Solution {
public:
	void connect(TreeLinkNode *root) 
	{
		if(root==NULL)
			return;

		queue<TreeLinkNode*> nodeQueue;
		TreeLinkNode *parent = new TreeLinkNode(0);
		nodeQueue.push(root);
		while(!nodeQueue.empty())
		{
			parent = nodeQueue.front();
			nodeQueue.pop();

			if(parent==NULL)
				return;

			TreeLinkNode *left=parent->left;
			if(left==NULL)
				return;
			if(right==NULL)
				return;
			left->next=parent->right;
			nodeQueue.push(left);

			TreeLinkNode *right=parent->right;
			if(parent->next!=NULL)
				right->next=parent->next->left;
			nodeQueue.push(right);

		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	TreeLinkNode *a=new TreeLinkNode(1);
	TreeLinkNode *b=new TreeLinkNode(2);
	TreeLinkNode *c=new TreeLinkNode(3);
	TreeLinkNode *d=new TreeLinkNode(4);
	TreeLinkNode *e=new TreeLinkNode(5);
	TreeLinkNode *f=new TreeLinkNode(6);
	TreeLinkNode *g=new TreeLinkNode(7);
	TreeLinkNode *h=new TreeLinkNode(8);
	TreeLinkNode *i=new TreeLinkNode(9);
	TreeLinkNode *j=new TreeLinkNode(10);
	TreeLinkNode *k=new TreeLinkNode(11);
	TreeLinkNode *l=new TreeLinkNode(12);
	TreeLinkNode *m=new TreeLinkNode(13);
	TreeLinkNode *n=new TreeLinkNode(14);
	TreeLinkNode *o=new TreeLinkNode(15);
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
	g->left=n;
	g->right=o;
	Solution solution;
	solution.connect(a);
	return 0;
}

