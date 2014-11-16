#include "stdafx.h"
#include "LRUCache.h"
#include<map>
#include <iostream>
using namespace std;
LRUCache::LRUCache(void)
{
}
int size;
map<int,int>mapCache;
LRUCache::LRUCache(int capacity){
	size=capacity;
}
void invalidate(){

}
int get(int key) {
	int value;
	if(mapCache.find(key)!=mapCache.end()){
		value=mapCache[key];
	}else{
		value=-1;
	}

}
    
void set(int key, int value) {
        
}
LRUCache::~LRUCache(void)
{
}
