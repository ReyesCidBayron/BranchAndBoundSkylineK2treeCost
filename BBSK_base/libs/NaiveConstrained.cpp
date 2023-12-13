#include "NaiveConstrained.hpp"

vector<pair<int, int>> * NaiveConstrained::constrained(vector<pair<int, int>> & points, int x1, int x2, int y1, int y2){
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	bool isSkyline;
	bool xRange, yRange;
	for(int i = 0; i < points.size(); i++){
		xRange = x1 <= points[i].first && points[i].first <= x2;
		yRange = y1 <= points[i].second && points[i].second <= y2;
		if(xRange && yRange){
			isSkyline = true;
			for(int j = 0; j < points.size(); j++){
				xRange = x1 <= points[j].first && points[j].first <= x2;
				yRange = y1 <= points[j].second && points[j].second <= y2;
				if(xRange && yRange){
					if((i != j) && (points[j].first <= points[i].first) && (points[j].second <= points[i].second)
						&& ((points[j].first < points[i].first) || (points[j].second < points[i].second))){
						isSkyline = false;
						break;
					}
				}
			}
			if(isSkyline){
				skyline->push_back(points[i]);
			}
		}
	}
	return skyline;
}