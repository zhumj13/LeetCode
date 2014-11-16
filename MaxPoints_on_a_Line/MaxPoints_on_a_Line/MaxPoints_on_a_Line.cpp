// MaxPoints_on_a_Line.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<map>
#include<iostream>
using namespace std;
struct Point{
	int x,y;
};
//�����뵽����������ÿ�ι̶�һ���㣬Ȼ�������ͬ�������е��б�ʣ����ҶԳ��ֹ���б�ʽ����ۼӼ�����
//����ʱ����Ҫע�⼸�㣺
//        1��ֱ�߲����ڵ�ʱ��Ҳ����б�ʲ�����  
//        2�����ظ��ĵ���֡�
//�㷨��ʱ�临�Ӷ�ΪO(n^2).

int maxPoints(vector<Point> &points) {
	int verticalNum,repeat,maxNum=0;
	for(int i=0;i<points.size();i++){
		verticalNum=1;
		repeat=1;
		double slope;
		map<double,int> line;
		for(int j=i+1;j<points.size();j++){
			//ȥ�ص�
			if(!(points[j].x==points[i].x&&points[j].y==points[i].y)){
				if(points[i].x==points[j].x){
					verticalNum++;		
				}else{
					slope=1.0*(points[j].y-points[i].y)/(points[j].x-points[i].x);
					if(line.find(slope)!=line.end()){
						line[slope]++;
					}else{
						line[slope]=1;
					}			
				}
			}else{
				repeat++;
			}
		}
		map<double,int>:: iterator iter=line.begin();
		for(;iter!=line.end();iter++){
			if(iter->second+repeat>verticalNum){
				verticalNum=iter->second+repeat;
			}
		}
		//ֻ���ظ������� line��ѭ������ִ��
		if(repeat>verticalNum){
			verticalNum=repeat;
		}
		if(verticalNum>maxNum){
			maxNum=verticalNum;
		}
	}
	return maxNum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<Point> points;
	Point temp;
	temp.x=1;
	temp.y=1;
	points.push_back(temp);
	temp.x=1;
	temp.y=2;
	points.push_back(temp);
	//temp.x=1;
	//temp.y=1;
	//points.push_back(temp);
	//temp.x=1;
	//temp.y=1;
	//points.push_back(temp);
	//temp.x=4;
	//temp.y=4;
	//points.push_back(temp);
	cout<<maxPoints(points)<<endl;
	return 0;
}

