#ifndef COMPACT_COUNT_H
#define COMPACT_COUNT_H

#include <iostream>
#include <math.h>
#include <vector>

#include "KtreeUtils.h"
#include "Punto.h"
#include "Matriz.h"
#include "Rectangulo.h"

using namespace std;

class CompactCount{
public:
	CompactCount();
	~CompactCount();
	uint count(MREP * rep, Rectangulo * r);
	uint getN(MREP * rep, int i);
	
private:
	uint adjustFirstChild(MREP * rep, uint i);
	uint adjustLastChild(MREP * rep, uint i);
};


#endif