#ifndef CONSTRAINEDX_H
#define CONSTRAINEDX_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#include "kTree.h"
#define K 2

using namespace std;

class ConstrainedX{
	public:
		ConstrainedX(){}
		~ConstrainedX(){}
		vector<pair<int, int>> * constrainedX(MREP * rep, int x1, int x2, int y1, int y2);
	private:
		
};

#endif