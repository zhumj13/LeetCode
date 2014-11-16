// MaxPoints_on_a_Line.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<map>
#include<iostream>
using namespace std;
struct Point{
	int x,y;
};
//最先想到的做法就是每次固定一个点，然后计算它同其他所有点的斜率，并且对出现过的斜率进行累加计数。
//做的时候，需要注意几点：
//        1、直线不存在的时候，也就是斜率不存在  
//        2、有重复的点出现。
//算法的时间复杂度为O(n^2).

int maxPoints(vector<Point> &points) {
	int verticalNum,repeat,maxNum=0;
	for(int i=0;i<points.size();i++){
		verticalNum=1;
		repeat=1;
		double slope;
		map<double,int> line;
		for(int j=i+1;j<points.size();j++){
			//去重点
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
		//只有重复点的情况 line的循环不会执行
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

