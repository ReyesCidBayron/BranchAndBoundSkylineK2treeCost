#ifndef NAIVEENUMERATING_H
#define NAIVEENUMERATING_H

#include <vector>
#include <utility>
#include <climits>

#include "NaiveSkyline.hpp"
#include "NaiveCount.hpp"

using namespace std;

class NaiveEnumerating{
	public:
		NaiveEnumerating(){}
		~NaiveEnumerating(){}
		vector<pair<pair<int, int>, int>> * enumeratingSkyline(vector<pair<int, int>> & points);
	private:
		
};



#endif