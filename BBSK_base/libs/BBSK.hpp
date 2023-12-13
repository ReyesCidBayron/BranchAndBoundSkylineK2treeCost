#ifndef BBSK_H
#define BBSK_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#include "kTree.h"
#define K 2

using namespace std;

class BBSK{
	public:
		BBSK(){}
		~BBSK(){}
		vector<pair<int, int>> * skylineManhattan(MREP * rep);
		vector<pair<int, int>> * skylineEuclidean(MREP * rep);
	private:
};

#endif