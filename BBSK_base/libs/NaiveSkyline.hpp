#ifndef NAIVESKYLINE_H
#define NAIVESKYLINE_H

#include <vector>
#include <utility>

using namespace std;

class NaiveSkyline{
	public:
		NaiveSkyline(){}
		~NaiveSkyline(){}
		vector<pair<int, int>> * skyline(vector<pair<int, int>> & points);
	private:
		
};

#endif