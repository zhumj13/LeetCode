// Maximum_Product_Subarray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Algorithm"
#include "iostream"
using namespace std;
//��̬�滮���Ե�ǰ��Ϊ��β�������ȡ����������
//1 ��ǰһ����Ϊ��β�����product * ��ǰ��
//2 ��ǰһ����Ϊ��β����Сproduct * ��ǰ��(��Ϊ���ָ���ʱ������һ�ξͻ�����С������)
//3 ��ǰ��
//
class Solution {
private:
	int m_MaxPrevious;
	int m_MinPrevious;
	int m_Max;
public:
	int maxProduct(int A[], int n) {
		if(n==0)
			return 0;
		if(n==1)
			return A[0];
		m_MaxPrevious=m_MinPrevious=m_Max=A[0];
		for(int i=1;i<n;i++)
		{
			int temp=m_MaxPrevious;
			m_MaxPrevious=max(max(m_MaxPrevious*A[i],A[i]),m_MinPrevious*A[i]);
			m_MinPrevious=min(min(temp*A[i],A[i]),m_MinPrevious*A[i]);
			m_Max=m_Max>m_MaxPrevious?m_Max:m_MaxPrevious;
		}
		return m_Max;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	int A[]={2,3,-1,-6,-7,1,5};
	cout<<solution.maxProduct(A,7)<<endl;
	return 0;
}

