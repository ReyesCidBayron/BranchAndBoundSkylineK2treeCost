#include <iostream>
#include <fstream>

#include "libs/NaiveConstrained.hpp"
#include "libs/ConstrainedBBSK.hpp"
#include "libs/ConstrainedX.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 6){
		printf("%s <PATH> <X_1> <X_2> <Y_1> <Y_2>\n", argv[0]);
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
	NaiveConstrained ns;
	ConstrainedBBSK bbsk;
	ConstrainedX skx;
	int x1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y1 = atoi(argv[4]);
	int y2 = atoi(argv[5]);
	
	vector<pair<int, int>> Sn = *(ns.constrained(points, x1, x2, y1, y2));
	cout << "CONSTRAINED SKYLINE Ingenuo: " << endl;
	for(int i = 0; i < Sn.size(); i++){
		cout << Sn[i].first << " " << Sn[i].second << endl;
	}
	cout << endl;
	
	vector<pair<int, int>> Sm = *(bbsk.constrainedManhattan(kt, x1, x2, y1, y2));
	cout << "CONSTRAINED SKYLINE Distancia Manhattan: " << endl;
	for(int i = 0; i < Sm.size(); i++){
		cout << Sm[i].first << " " << Sm[i].second << endl;
	}
	cout << endl;
	
	vector<pair<int, int>> Se = *(bbsk.constrainedEuclidean(kt, x1, x2, y1, y2));
	cout << "CONSTRAINED SKYLINE Distancia Euclidean: " << endl;
	for(int i = 0; i < Se.size(); i++){
		cout << Se[i].first << " " << Se[i].second << endl;
	}
	cout << endl;
	
	vector<pair<int, int>> Sx = *(skx.constrainedX(kt, x1, x2, y1, y2));
	cout << "CONSTRAINED X: " << endl;
	for(int i = 0; i < Sx.size(); i++){
		cout << Sx[i].first << " " << Sx[i].second << endl;
	}
	cout << endl;
	
}