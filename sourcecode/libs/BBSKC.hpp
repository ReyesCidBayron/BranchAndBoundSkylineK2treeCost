#ifndef BBSK_H
#define BBSK_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include "kTree.h"

#define K 2

using namespace std;

class BBSKC{
	public:
		BBSKC(){}
		~BBSKC(){}
		vector<pair<int, int>> * skylineCostManhattan(MREP * rep, float alpha, float beta);
		vector<pair<int, int>> * skylineCostEuclidean(MREP * rep, float alpha, float beta);
	private:
};

#endif