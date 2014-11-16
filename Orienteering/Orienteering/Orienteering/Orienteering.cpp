// Orienteering.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<map>
#include<vector>
#include<iostream>
using namespace std;
//����˼·��BFS���� ʹ��Node��checkPoint����¼ÿһ��@��Ϣ û����һ���ͻ��� 
//�޸�BFS (ԭ���Ǹ��ݵ�����������֣������Ǹ��ݵ���������checkPoint����Ϣ��������������������@���ӵڶ����ٴη��ر�����һ����ʱ��
//��ΪcheckPoint��λ��֮���ı䣬���Ի�������ʵ�һ��@��)
struct Coordinate
{
	int x;
	int y;
	bool operator <(const Coordinate& other) const
	{
		if (x < other.x)        //���Ͱ���������
		{
			return true;
		}
		else if (x == other.x)  //���������ͬ������������������
		{
			return y < other.y;
		}

		return false;
	}
	Coordinate(int xx,int yy)
	{
		x=xx;
		y=yy;
	}
};
struct Node
{
	bool isPassed;
	char pointType;
	int  passedPointLength;
	int  checkPoint;
	int  passedCheckPointLength;
	Node(bool isTraversal,char type)
	{
		isPassed=isTraversal;
		pointType=type;
		checkPoint=0;
		passedCheckPointLength=0;
		passedPointLength=0;
	}
};
typedef pair <Coordinate, Node> NodePair;
map<Coordinate,Node> m_mapNodes;
Coordinate m_Start(0,0);
int m_MixPathLenth=INT_MAX;
int m_CheckPoint=1;
int m_TotalCheckPoint=0;
void Travers(map<Coordinate,Node> mapNodes,Coordinate inputCoordinate);
void InitSpecialNode(char inputChar,Coordinate inputCoordinate,Node &node)
{
	if(inputChar=='S')
	{
		m_Start=inputCoordinate;
	}
	if(inputChar=='@')
	{
		node.checkPoint=m_CheckPoint;
		m_CheckPoint=(m_CheckPoint<<1);
		m_TotalCheckPoint=(m_TotalCheckPoint<<1)+1;
	}
}
void Input()
{
	int width,height,column=0,row=0;
	cin>>width>>height;
	char inputChar;
	while(row<height)
	{
		column=0;
		while(column<width)
		{
			cin>>inputChar;
			Coordinate inputCoordinate(column,row);
			Node inputNode(false,inputChar);
			InitSpecialNode(inputChar,inputCoordinate,inputNode);
			m_mapNodes.insert(NodePair(inputCoordinate,inputNode));
			column++;
		}
		row++;
	}
}
void FourDirectionTravers( map<Coordinate,Node> &mapNodes, Coordinate coordinate,Coordinate parentCoordinate) 
{
	map<Coordinate,Node>::iterator itMapNodes;
	itMapNodes=mapNodes.find(coordinate);
	if(itMapNodes==mapNodes.end()||itMapNodes->second.pointType=='#')
		return;
	if(itMapNodes->second.isPassed==true&&(mapNodes.at(parentCoordinate).passedCheckPointLength==itMapNodes->second.passedCheckPointLength))
		return;

	itMapNodes->second.passedPointLength=mapNodes.at(parentCoordinate).passedPointLength;
	itMapNodes->second.passedCheckPointLength=mapNodes.at(parentCoordinate).passedCheckPointLength;
	map<Coordinate,Node> maDirectionNodes=mapNodes;
	Travers(maDirectionNodes,coordinate);
}

void Travers(map<Coordinate,Node> mapNodes,Coordinate inputCoordinate)
{
	map<Coordinate,Node>::iterator itMapNodes;
	itMapNodes=mapNodes.find(inputCoordinate);
	itMapNodes->second.isPassed=true;
	itMapNodes->second.passedPointLength++;
	if(itMapNodes->second.pointType=='@')
	{
		itMapNodes->second.passedCheckPointLength=itMapNodes->second.passedCheckPointLength|itMapNodes->second.checkPoint;
	}
	if(itMapNodes->second.pointType=='G'&&(itMapNodes->second.passedCheckPointLength==m_TotalCheckPoint))
	{
		if(itMapNodes->second.passedPointLength>=m_MixPathLenth)
			return;
		m_MixPathLenth=itMapNodes->second.passedPointLength;
	}else
	{
		Coordinate upCoordinate(inputCoordinate.x,inputCoordinate.y-1)
			      ,downCoordinate(inputCoordinate.x,inputCoordinate.y+1)
				  ,leftCoordinate(inputCoordinate.x-1,inputCoordinate.y)
				  ,rightCoordinate(inputCoordinate.x+1,inputCoordinate.y);

		FourDirectionTravers(mapNodes, upCoordinate,inputCoordinate);
	    FourDirectionTravers(mapNodes, rightCoordinate,inputCoordinate);
		FourDirectionTravers(mapNodes, downCoordinate,inputCoordinate);
		FourDirectionTravers(mapNodes, leftCoordinate,inputCoordinate);

	}
}
void Process()
{
	Input();
	Travers(m_mapNodes,m_Start);
}
int _tmain(int argc, _TCHAR* argv[])
{
	Process();
	cout<<"path length:"<<m_MixPathLenth-1<<endl;
	return 0;
}

