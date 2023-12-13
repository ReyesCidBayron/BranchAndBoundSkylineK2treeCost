#ifndef SKYLINE_INGENUO_H
#define SKYLINE_INGENUO_H

#include <iostream>
#include <string>
#include <vector>

#include "Punto.h"

using namespace std;

class SkylineIngenuo{
public:
	SkylineIngenuo();
	~SkylineIngenuo();
	vector<Punto*> calculeSkyline(Punto ** dataset);
private:
	
	
};

#endif