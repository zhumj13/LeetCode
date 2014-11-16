// PalindromePartitioning.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//判断是不是回文子串
/*bool isPalindrome(string s){
	int start=0,end=s.length()-1;
	while(start<=end){
		if(!s[start++]==s[end--]){
			return false;
		}
	}
	return true;
}
vector<vector<string>> partition(string s) {
	string pre;
	vector<vector<string>> result;
	vector<string>result_Ele;
	if(s.length()==0){
		return result;
	}
	for(int i=1;i<s.length();i++){
		pre=s.substr(0,i);
		//字符串的前一半是回文时候再继续讨论
		if(isPalindrome(pre)){
			vector<vector<string>> s_end=partition(s.substr(i,s.length()-i));
			for(int j=0;j<s_end.size();j++){
				s_end[j].insert(s_end[j].begin(),pre);
				result.push_back(s_end[j]);
			}

		}else{
			continue;
		}
	}
	if(isPalindrome(s)){
		result_Ele.push_back(s);
		result.push_back(result_Ele);
	}
	return result;
}*/

  bool is_huiwen(const string &s)
    {
        int l=s.length();
        int i;
        for(i=0; i<l/2; i++)
            if(s[i] != s[l-1-i])
                return false;
        return true;
    }
    
    vector<vector<string> > partition(string s) 
    {
        
        int l=s.length();
        vector<vector<string> >vv;
        vector<string> v;
        if(l==0)
        {
            return vv;
        }
        int i;
        for(i=1; i<l; i++)
        {
            string ts=s.substr(0,i);
            if(! is_huiwen(ts) )
                continue;
            string ts_end=s.substr(i,s.length() - i);
            vector<vector<string> > vvt;
            vvt=partition(ts_end);
            int j;
            for(j=0; j<vvt.size(); j++)
            {
                
                vvt[j].insert(vvt[j].begin(), ts);
                vv.push_back(vvt[j]);
            }
        }
        if(is_huiwen(s) )
        {
            v.push_back(s);
            vv.push_back(v);
        }
        return vv;
    }

int _tmain(int argc, _TCHAR* argv[])
{
	string a="aab";
	vector<vector<string>> result;
	result=partition(a);

	return 0;
}

