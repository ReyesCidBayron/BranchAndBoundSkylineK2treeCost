#include <iostream>
#include <fstream>
#include <string>

#include "libs/NaiveEnumerating.hpp"
#include "libs/EnumeratingRange.hpp"
#include "libs/EnumeratingCompact.hpp"

using namespace std;

bool compareArray(vector<pair<pair<int, int>, int>> & v1, vector<pair<pair<int, int>, int>> & v2){
	if(v1.size() != v2.size()){
		return false;
	}
	for(int i = 0; i < v1.size(); i++){
		bool encontrado = false;
		for(int j = 0; j < v2.size(); j++){
			if(v1[i].first.first == v2[j].first.first && v1[i].first.second == v2[j].first.second &&
			   v1[i].second == v2[j].second){
				encontrado = true;
				break;
			}
		}
		if(!encontrado){
			return false;
		}
	}
	return true;
}

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("%s <PATH>\n", argv[0]);
		return -1;
	}
	
	/* Carga de puntos */
	
	string completo(argv[1]);
	completo+= ".txt";
	ifstream fe(completo.c_str());
	if(!fe.is_open()){
		printf("Error al abrir el archivo %s.txt\n", argv[1]);
		return -1;
	}
	vector<pair<int,int>> points;
	int x, y;
	pair<int,int> p;
	while (!fe.eof()) {
		fe >> x;
		fe >> y;
		p = make_pair(x, y);
		points.push_back(p);
	}
	fe.close();
	
	MREP * kt = loadRepresentation(argv[1]);
	
	NaiveEnumerating en;
	EnumeratingRange er;
	EnumeratingCompact ec;
	vector<pair<pair<int, int>, int>> S1 = *(en.enumeratingSkyline(points));
	vector<pair<pair<int, int>, int>> S2 = *(er.enumeratingSkyline(kt));
	vector<pair<pair<int, int>, int>> S3 = *(er.enumeratingSkylineCompact(kt));
	vector<pair<pair<int, int>, int>> S4 = *(ec.enumeratingSkyline(kt));
	
	cout << argv[1] << " " << compareArray(S1, S2) << " " << compareArray(S1, S3) 
		<< " " << compareArray(S1, S4) << " " << endl;
}