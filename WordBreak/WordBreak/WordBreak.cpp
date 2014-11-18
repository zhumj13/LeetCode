// WordBreak.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if(s.length()==0){
			return true;
		}
		for(int i=1;i<=s.length();i++){
			//string tt =s.substr(0,i);
			if(dict.count(s.substr(0,i))>0){
				string sCopy = s.substr(i,s.length()-i);
				if(wordBreak(sCopy,dict)){
					return true;
				}
			}
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	dict.insert("le");
	dict.insert("lee");
	dict.insert("de");
	string s= "leetcode";
	bool ss=solution.wordBreak(s,dict);
	return 0;
}

