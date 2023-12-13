#ifndef RANGE_COUNT_H
#define RANGE_COUNT_H

#include <iostream>
#include <math.h>
#include <vector>

#include "kTree.h"
#include "Punto.h"
#include "Matriz.h"
#include "Rectangulo.h"

using namespace std;

class RangeCount{
public:
	RangeCount();
	~RangeCount();
	uint count(MREP * rep, Rectangulo * r);
	
	
private:
	
};


#endif