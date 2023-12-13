#ifndef HEAP_SKYLINE_BBS_H
#define HEAP_SKYLINE_BBS_H

#include <iostream>
#include <vector> 
#include <algorithm>

#include "Matriz.h"


using namespace std;

class HeapSkyline{
public:
	HeapSkyline(ushort option);
	~HeapSkyline();
    void insert(Matriz *r);
	Matriz* get();
	void print();
	int size();
private:
	ushort option;
    vector<Matriz*> heap;
	bool esMenor(Matriz * m);
	void push();
	void pop();
	void make();
};

#endif