#ifndef BBSK_H
#define BBSK_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include "kTree.h"

#define K 2

using namespace std;

class BBSKE_DEV{
	public:
		BBSKE_DEV(){}
		~BBSKE_DEV(){}
		vector<pair<int, int>> * skylineExtendedEuclidean(MREP * rep, float alpha, float beta);
	private:
};

#endif