// WordBreak.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<string>
#include<unordered_set>
//采用递归方法，但是添加了备忘录，记录所有没有匹配过得字母，这样可以少很多的递归
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

