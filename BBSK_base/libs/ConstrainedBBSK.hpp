#ifndef CONSTRAINEDBBSK_H
#define CONSTRAINEDBBSK_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#include "kTree.h"
#define K 2

using namespace std;

class ConstrainedBBSK{
	public:
		ConstrainedBBSK(){}
		~ConstrainedBBSK(){}
		vector<pair<int, int>> * constrainedManhattan(MREP * rep, int x1, int x2, int y1, int y2);
		vector<pair<int, int>> * constrainedEuclidean(MREP * rep, int x1, int x2, int y1, int y2);
	private:
};

#endif