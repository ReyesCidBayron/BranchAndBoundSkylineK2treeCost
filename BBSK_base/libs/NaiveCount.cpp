#include "NaiveCount.hpp"

int NaiveCount::count(vector<pair<int, int>> & points, int x1, int x2, int y1, int y2){
	int c = 0;
	bool xRange, yRange;
	for(int i = 0; i < points.size(); i++){
		xRange = x1 <= points[i].first && points[i].first <= x2;
		yRange = y1 <= points[i].second && points[i].second <= y2;
		if(xRange && yRange)	c++;
	}
	return c;
}