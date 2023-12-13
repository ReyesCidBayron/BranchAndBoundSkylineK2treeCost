#include "NaiveSkyline.hpp"

vector<pair<int, int>> * NaiveSkyline::skyline(vector<pair<int, int>> & points){
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	bool isSkyline;
	for(int i = 0; i < points.size(); i++){
		isSkyline = true;
		for(int j = 0; j < points.size(); j++){
			if((i != j) && (points[j].first <= points[i].first) && (points[j].second <= points[i].second)
			   	&& ((points[j].first < points[i].first) || (points[j].second < points[i].second))){
				isSkyline = false;
				break;
			}
		}
		if(isSkyline){
			skyline->push_back(points[i]);
		}
	}
	return skyline;
}