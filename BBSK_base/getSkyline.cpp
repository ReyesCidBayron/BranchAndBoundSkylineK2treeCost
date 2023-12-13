#include <iostream>
#include <fstream>

#include "libs/NaiveSkyline.hpp"
#include "libs/BBSK.hpp"
#include "libs/SkylineX.hpp"

using namespace std;

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
	
	vector<pair<int, int>> Sn = *(ns.skyline(points));
	cout << "SKYLINE Ingenuo: " << endl;
	for(int i = 0; i < Sn.size(); i++){
		cout << Sn[i].first << " " << Sn[i].second << endl;
	}
	cout << endl;
	
	vector<pair<int, int>> Sm = *(bbsk.skylineManhattan(kt));
	cout << "SKYLINE Distancia Manhattan: " << endl;
	for(int i = 0; i < Sm.size(); i++){
		cout << Sm[i].first << " " << Sm[i].second << endl;
	}
	cout << endl;
	
	vector<pair<int, int>> Se = *(bbsk.skylineEuclidean(kt));
	cout << "SKYLINE Distancia Euclidean: " << endl;
	for(int i = 0; i < Se.size(); i++){
		cout << Se[i].first << " " << Se[i].second << endl;
	}
	cout << endl;
	
	vector<pair<int, int>> Sx = *(skx.skylineX(kt));
	cout << "SKYLINE X: " << endl;
	for(int i = 0; i < Sx.size(); i++){
		cout << Sx[i].first << " " << Sx[i].second << endl;
	}
	cout << endl;
	
}