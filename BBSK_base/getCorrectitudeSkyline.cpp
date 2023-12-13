#include <iostream>
#include <fstream>
#include <string>

#include "libs/BBSK.hpp"
#include "libs/SkylineX.hpp"
#include "libs/NaiveSkyline.hpp"

using namespace std;

bool compareArray(vector<pair<int, int>> & v1, vector<pair<int, int>> & v2){
	if(v1.size() != v2.size()){
		return false;
	}
	for(int i = 0; i < v1.size(); i++){
		bool encontrado = false;
		for(int j = 0; j < v2.size(); j++){
			if(v1[i].first == v2[j].first && v1[i].second == v2[j].second){
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
	NaiveSkyline ns;
	BBSK bbsk;
	SkylineX skx;
	
	vector<pair<int, int>> S1 = *(ns.skyline(points));
	vector<pair<int, int>> S2 = *(bbsk.skylineManhattan(kt));
	vector<pair<int, int>> S3 = *(bbsk.skylineEuclidean(kt));
	vector<pair<int, int>> S4 = *(skx.skylineX(kt));
	
	cout << argv[1] << " " << compareArray(S1, S2) << " " << compareArray(S1, S3) 
		<< " " << compareArray(S1, S4) << " " << endl;
}