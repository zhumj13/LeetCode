// ValidPalindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <regex>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) 
	{
		if(s.length()==0||s.length()==1)
			return true;
		int i=0;
		int j=s.length()-1;
		while(i<=j)
		{
			while(i<s.length()-1&&!(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')||('0'<=s[i]&&s[i]<='9')))
			{
				i++;
			}
			while(j>=1&&!((('a'<=s[j]&&s[j]<='z')||('A'<=s[j]&&s[j]<='Z')||('0'<=s[j]&&s[j]<='9'))))
			{
				j--;
			}
			if(i>j)
			{
				return true;
			}
			if(j>=0&&i<s.length())
			{
				if(('0'<=s[i]&&s[i]<='9')&&('0'<=s[j]&&s[j]<='9')&&s[i]==s[j]){
					i++;
					j--;
					continue;
				}else if(toupper(s[i])==toupper(s[j])){
					i++;
					j--;
					continue;
				}
			}
			return false;			
		}
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout<<s.isPalindrome("A man, a plan, a canal: Panama")<<endl;
	cout<<s.isPalindrome("a!a")<<endl;
	system("pause");
	//char a[]= {'a'};
	//string s;
	//s.assign(a);
	//std::regex pattern("[a-zA-Z]");
	//std::regex_match(s,pattern);
	return 0;
}
