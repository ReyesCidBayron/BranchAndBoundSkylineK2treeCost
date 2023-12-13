#ifndef NAIVECOUNT_H
#define NAIVECOUNT_H

#include <vector>
#include <utility>

using namespace std;

class NaiveCount{
	public:
		NaiveCount(){}
		~NaiveCount(){}
		int count(vector<pair<int, int>> & points, int x1, int x2, int y1, int y2);
	private:
		
};

#endif