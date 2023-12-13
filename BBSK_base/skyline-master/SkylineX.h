#ifndef K2TREE_SKYLINE_X_H
#define K2TREE_SKYLINE_X_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "KtreeUtils.h"
#include "HeapSkyline.h"
#include "Rectangulo.h"
#include "Punto.h"
#include "Matriz.h"

using namespace std;

class SkylineX{
public:
    SkylineX();
    ~SkylineX();
    vector<Punto * > calculeSkyline(MREP * rep);
private:
    void readjustRectangle(Punto * p, Rectangulo * r);
	
};

#endif