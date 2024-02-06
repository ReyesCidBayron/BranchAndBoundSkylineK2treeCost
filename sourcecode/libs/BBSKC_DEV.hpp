#ifndef BBSK_H
#define BBSK_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include "kTree.h"

#define K 2

using namespace std;

class BBSKC_DEV{
	public:
		BBSKC_DEV(){}
		~BBSKC_DEV(){}
		vector<pair<int, int>> * skylineCostEuclidean1(MREP * rep, float alpha, float beta);
		vector<pair<int, int>> * skylineCostEuclidean2(MREP * rep, float alpha, float beta);
	private:
};

#endif