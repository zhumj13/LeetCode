// ValidateBinarySearchTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
//思路：递归调用，每次递归的时候需要将取值范围传递进下一层
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
        {
            return true;
        }
        else
        {
            return isValidNode(root->left, root->val, INT_MIN) && isValidNode(root->right, INT_MAX, root->val);
        }
    }
    
    bool isValidNode(TreeNode * p, int max, int min)
    {
        if(p == NULL)
        {
            return true;
        }
        else if(p->val < max && p->val > min)
        {
            return isValidNode(p->left, p->val, min) && isValidNode(p->right, max, p->val);
        }
        else
        {
            return false;
        }
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

