// FindInTwoDimentionalArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;

int BinarySearchIndex(int **data, int low, int high, int pivot)
{
	int mid=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(pivot==data[mid][0])
		{
			return mid;
		}
		if(pivot>data[mid][0])
		{
			low = mid+1;
			continue;
		}
		else
		{
			high = mid-1;
			continue;
		}

	}
	return mid;
}
bool BinarySearchPivot(int **data, int low, int high, int pivot,int index)
{
	int mid=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(pivot==data[index][mid])
		{
			return true;
		}
		if(pivot>data[index][mid])
		{
			low = mid+1;
			continue;
		}
		else
		{
			high = mid-1;
			continue;
		}

	}
	return false;
}
int FindRightSection(int **data,int index,int pivot)
{
	if(pivot<data[index][0])
	{
		return index-1;
	}
	return index;
}
void Process()
{
	int **data,row,column,pivot;


	while(scanf("%d %d", &row, &column) != EOF)
	{

		data = new int*[row];
		for(int i=0;i<row;i++)
		{
			data[i] = new int[column];
		}
		scanf("%d", &pivot);
		int temp;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				scanf("%d", &data[i][j]);
			}
		}
		int index=BinarySearchIndex(data,0,column-1,pivot);
		int rightIndex=0;
		if(index>=1&&index<column)
		{
			rightIndex=FindRightSection(data,index,pivot);
		}

		if(BinarySearchPivot(data,0,column-1,pivot,rightIndex))
		{
			 printf("%s", "Yes");
		}else
		{
			 printf("%s", "No");
		}

	}
}
int main()
{
	Process();
	return 0;
}

