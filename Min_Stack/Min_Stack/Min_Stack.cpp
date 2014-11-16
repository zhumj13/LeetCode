// Min_Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stack"
#include "iostream"
using namespace std;
class MinStack {

private:
	stack<int> m_Stack;
	stack<int> m_MinStack;
public:

	void push(int x) {
		m_Stack.push(x);
		if(!(m_MinStack.empty())&&m_MinStack.top()<m_Stack.top())
		{
			return;
		}
		m_MinStack.push(m_Stack.top());
	}

	void pop() {
		if(m_Stack.size()>0)
		{
			if(m_Stack.top()==m_MinStack.top()){
				m_MinStack.pop();
			}
			m_Stack.pop();
		}
	}

	int top() {
		if(m_Stack.size()>0)
		{
			return m_Stack.top();
		}
	}

	int getMin() {
		if(m_Stack.size()>0)
		{
			return m_MinStack.top();
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	MinStack test;
	//test.push(1);
	//test.push(2);
	//test.push(0);
	//test.push(3);
	//test.push(1);
	//test.push(2);
	//test.push(3);
	//test.push(0);
	//test.push(1);
	//cout<<"top="<<test.top();
	//cout<<"top="<<test.getMin()<<endl;
	//test.pop();
	//cout<<"top="<<test.top();
	//cout<<"top="<<test.getMin()<<endl;
	//test.pop();
	//cout<<"top="<<test.top();
	//cout<<"top="<<test.getMin()<<endl;
	//test.pop();
	//cout<<"top="<<test.top();
	//cout<<"top="<<test.getMin()<<endl;
	test.push(512);
	test.push(-1024);
	test.push(-1024);
	test.push(512);
	test.pop();
	test.getMin();
	test.pop();
	test.getMin();
	test.pop();
	test.getMin();
	return 0;
}

