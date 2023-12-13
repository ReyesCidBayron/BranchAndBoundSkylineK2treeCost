#ifndef ENUMERTINGCOMPACT_H
#define ENUMERTINGCOMPACT_H

#include <vector>
#include <utility>
#include <cmath>
#include <queue>

#include "kTree.h"
#include "Count.hpp"
#define K 2

using namespace std;

class EnumeratingCompact{
	public:
		EnumeratingCompact(){}
		~EnumeratingCompact(){}
		vector<pair<pair<int, int>, int>> * enumeratingSkyline(MREP * rep);
	private:
		int enumeratingCount(MREP * rep, Count & cc, int x, int y, int * N);
};



#endif