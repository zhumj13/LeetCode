// PopulatingNextRightPointersInEachNode2.cpp : 定义控制台应用程序的入口点。
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
			TreeLinkNode *right=parent->right;
			if(left!=NULL)
			{
				if(right!=NULL)
				{
					left->next=right;
				}else if(parent->next!=NULL)
				{
					TreeLinkNode *uncle= parent->next;
					while(uncle!=NULL&&!GetNextFromUncle(uncle, left))
					{
						uncle=uncle->next;
						if(uncle!=NULL)
							GetNextFromUncle(uncle,left);
					}
				}
				nodeQueue.push(left);
			}

			if(right!=NULL)
			{
				if(parent->next!=NULL)
				{
					TreeLinkNode *uncle= parent->next;
					while(uncle!=NULL&&!GetNextFromUncle(uncle, right))
					{
						uncle=uncle->next;
						if(uncle!=NULL)
							GetNextFromUncle(uncle,right);
					}
				}
				nodeQueue.push(right);
			}

		}
	}

	bool GetNextFromUncle( TreeLinkNode * uncle, TreeLinkNode * now ) 
	{
		TreeLinkNode *uncleLeft=uncle->left;
		TreeLinkNode *uncleRight=uncle->right;
		if(uncleLeft!=NULL)
		{
			now->next=uncleLeft;
			return true;
		}else if(uncleRight!=NULL)
		{
			now->next=uncleRight;
			return true;
		}
		return false;
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
	a->left=b;
	a->right=c;
	b->left=d;
	b->right=e;
	c->right=f;
	d->left=g;
	Solution solution;
	solution.connect(a);
	return 0;
}

