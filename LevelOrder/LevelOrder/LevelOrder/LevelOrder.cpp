// LevelOrder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<vector<int>> allLevels;
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		if(root!=NULL)
		{
			vector<TreeNode*> levelNode;
			levelNode.push_back(root);

			travers(levelNode);
		}
		return allLevels;
	}
	void travers(vector<TreeNode*> levelNode)
	{
		vector<int> levelVals;
		vector<TreeNode*> nextLevelNodes;
		for(vector<TreeNode*>::iterator itNode=levelNode.begin();itNode!=levelNode.end();itNode++)
		{
			TreeNode* now = *itNode;
			levelVals.push_back(now->val);
			if(now->left!=NULL)
			{
				nextLevelNodes.push_back(now->left);
			}
			if(now->right!=NULL)
			{
				nextLevelNodes.push_back(now->right);
			}			
		}
		allLevels.push_back(levelVals);
		if(nextLevelNodes.size()>0)
		{
			travers(nextLevelNodes);
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

