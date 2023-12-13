#include "EnumeratingRange.hpp"

vector<pair<pair<int, int>, int>> * EnumeratingRange::enumeratingSkyline(MREP * rep){
	BBSK bbsk;
	Count count;
    vector<pair<int, int>> skyline = *(bbsk.skylineManhattan(rep));
	vector<pair<pair<int, int>, int>> * result = new vector<pair<pair<int, int>, int>>();
	
	int dominados = 0;
	for(int i = 0; i < skyline.size(); i++){
		dominados = count.rangeCount(rep, skyline[i].first, rep->numberOfNodes-1, 
									 skyline[i].second, rep->numberOfNodes-1) - 1;
		result->push_back(make_pair(skyline[i], dominados));
	}
	
	return result;
}
vector<pair<pair<int, int>, int>> * EnumeratingRange::enumeratingSkylineCompact(MREP * rep){
	BBSK bbsk;
	Count count;
    vector<pair<int, int>> skyline = *(bbsk.skylineManhattan(rep));
	vector<pair<pair<int, int>, int>> * result = new vector<pair<pair<int, int>, int>>();
	
	int dominados = 0;
	for(int i = 0; i < skyline.size(); i++){
		dominados = count.compactCount(rep, skyline[i].first, rep->numberOfNodes-1, 
									 skyline[i].second, rep->numberOfNodes-1) - 1;
		result->push_back(make_pair(skyline[i], dominados));
	}
	
	return result;
}