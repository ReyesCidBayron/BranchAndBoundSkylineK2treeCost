#include "NaiveEnumerating.hpp"

vector<pair<pair<int, int>, int>> * NaiveEnumerating::enumeratingSkyline(vector<pair<int, int>> & points){
	NaiveSkyline ns;
	NaiveCount count;
	vector<pair<int, int>> skyline = *(ns.skyline(points));
	vector<pair<pair<int, int>, int>> * result = new vector<pair<pair<int, int>, int>>();
	
	int dominados = 0;
	for(int i = 0; i < skyline.size(); i++){
		dominados = count.count(points, skyline[i].first, INT_MAX, skyline[i].second, INT_MAX) - 1;
		result->push_back(make_pair(skyline[i], dominados));
	}
	
	return result;
}