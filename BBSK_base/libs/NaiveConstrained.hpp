#ifndef NAIVECONSTRAINEDSKYLINE_H
#define NAIVECONSTRAINEDSKYLINE_H

#include <vector>
#include <utility>

using namespace std;

class NaiveConstrained{
	public:
		NaiveConstrained(){}
		~NaiveConstrained(){}
		vector<pair<int, int>> * constrained(vector<pair<int, int>> & points, int x1, int x2, int y1, int y2);
	private:
		
};

#endif