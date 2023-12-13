#ifndef BBSK_H
#define BBSK_H

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include "kTree.h"

#define K 2

using namespace std;

class BBSKE{
	public:
		BBSKE(){}
		~BBSKE(){}
		vector<pair<int, int>> * skylineExtendedManhattan(MREP * rep, float alpha, float beta);
		vector<pair<int, int>> * skylineExtendedEuclidean(MREP * rep, float alpha, float beta);
	private:
};

#endif