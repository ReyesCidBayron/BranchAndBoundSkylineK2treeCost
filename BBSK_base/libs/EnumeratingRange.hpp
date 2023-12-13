#ifndef ENUMERATINGRANGE_H
#define ENUMERATINGRANGE_H

#include <vector>
#include <utility>

#include "kTree.h"
#include "BBSK.hpp"
#include "Count.hpp"

using namespace std;

class EnumeratingRange{
	public:
		EnumeratingRange(){}
		~EnumeratingRange(){}
		vector<pair<pair<int, int>, int>> * enumeratingSkyline(MREP * rep);
		vector<pair<pair<int, int>, int>> * enumeratingSkylineCompact(MREP * rep);
	private:
		
};

#endif