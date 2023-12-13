#ifndef SKYLINE_BBSK_H
#define SKYLINE_BBSK_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "KtreeUtils.h"
#include "HeapSkyline.h"
#include "Punto.h"
#include "Matriz.h"

using namespace std;


class SkylineBBSk{
public:
    SkylineBBSk();
    ~SkylineBBSk();
    vector<Punto*> calculeSkyline(MREP * rep, ushort distanceOption);
private:
    bool isDominatedByS(Punto * q, vector<Punto*> S);
    
};

#endif