#ifndef ENUMERATING_RANGE_H
#define ENUMERATING_RANGE_H

#include <iostream>
#include <vector>

#include "kTree.h"
#include "Punto.h"
#include "SkylineBBSk.h"
#include "CompactCount.h"

using namespace std;


class EnumeratingRange{
public:
    EnumeratingRange();
    ~EnumeratingRange();
    vector<Punto*> enumeratingSkyline(MREP * rep);
    vector<Punto*> enumeratingCompactSkyline(MREP * rep);
private:
    
};

#endif