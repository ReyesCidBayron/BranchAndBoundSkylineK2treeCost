#ifndef SKYLINEX_H
#define SKYLINEX_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#include "kTree.h"
#define K 2

using namespace std;

class SkylineX{
	public:
		SkylineX(){}
		~SkylineX(){}
		vector<pair<int, int>> * skylineX(MREP * rep);
	private:
		
};

#endif