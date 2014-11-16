#pragma once
class LRUCache
{
public:
	LRUCache(void);
	~LRUCache(void);
	LRUCache(int capacity);   
	int get(int key);
	void set(int key, int value);
};

