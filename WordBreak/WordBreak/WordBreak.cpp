// WordBreak.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<string>
#include<unordered_set>
//���õݹ鷽������������˱���¼����¼����û��ƥ�������ĸ�����������ٺܶ�ĵݹ�
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> dict)
	{
			unordered_set<string> unmatch;
			return wordBreak(s,dict,unmatch);
	}
	bool wordBreak(string s, unordered_set<string> &dict,unordered_set<string>&unmatch) {
		if(unmatch.count(s)>0)
			return false;
		if(s.length()==0){
			return true;
		}
		for(int i=1;i<=s.length();i++){
			if(dict.count(s.substr(0,i))>0){
				string sCopy = s.substr(i,s.length()-i);
				if(wordBreak(sCopy,dict,unmatch)){
					return true;
				}
			}
		}
		unmatch.insert(s);
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	unordered_set<string> dict;
	//dict.insert("leet");
	//dict.insert("code");
	//dict.insert("le");
	//dict.insert("lee");
	//dict.insert("de");
	//string s= "leetcode";

	dict.insert("a");
	dict.insert("b");
	dict.insert("abc");
	dict.insert("cd");
	string s= "abcd";

	unordered_set<string> unmatch;
	bool ss=solution.wordBreak(s,dict);
	return 0;
}

