#ifndef ENUMERATING_COMPACT_H
#define ENUMERATING_COMPACT_H

#include <iostream>
#include <math.h>
#include <vector>

#include "KtreeUtils.h"
#include "Punto.h"
#include "Matriz.h"
#include "Rectangulo.h"
#include "HeapSkyline.h"
#include "CompactCount.h"


using namespace std;

class EnumeratingCompact{
public:
	EnumeratingCompact();
	~EnumeratingCompact();
	vector<Punto*> enumeratingSkyline(MREP * rep);
	
private:
	uint * N;
	CompactCount * cc;
	uint enumeratingCount(MREP * rep, Rectangulo * r);
	bool isDominatedByS(Matriz * m, vector<Punto*> S);
    bool isDominatedByS(Punto * q, vector<Punto*> S);
};

#endif