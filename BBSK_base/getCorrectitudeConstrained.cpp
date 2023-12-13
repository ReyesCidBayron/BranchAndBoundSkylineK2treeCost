#include <iostream>
#include <fstream>
#include <string>

#include "libs/ConstrainedBBSK.hpp"
#include "libs/ConstrainedX.hpp"
#include "libs/NaiveConstrained.hpp"

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
	NaiveConstrained nc;
	ConstrainedBBSK cbbsk;
	ConstrainedX cx;
	
	int x1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y1 = atoi(argv[4]);
	int y2 = atoi(argv[5]);
	
	vector<pair<int, int>> S1 = *(nc.constrained(points, x1, x2, y1, y2));
	vector<pair<int, int>> S2 = *(cbbsk.constrainedManhattan(kt, x1, x2, y1, y2));
	vector<pair<int, int>> S3 = *(cbbsk.constrainedEuclidean(kt, x1, x2, y1, y2));
	vector<pair<int, int>> S4 = *(cx.constrainedX(kt, x1, x2, y1, y2));
	/*
	cout << "NaiveConstrained: " << endl;
	for(int i = 0; i < S1.size(); i++){
		printf("(%d, %d)\n", S1[i].first, S1[i].second);
	}
	
	cout << "ConstrainedBBSKM: " << endl;
	for(int i = 0; i < S2.size(); i++){
		printf("(%d, %d)\n", S2[i].first, S2[i].second);
	}
	
	cout << "ConstrainedBBSKE: " << endl;
	for(int i = 0; i < S3.size(); i++){
		printf("(%d, %d)\n", S3[i].first, S3[i].second);
	}
	
	cout << "ConstrainedX: " << endl;
	for(int i = 0; i < S4.size(); i++){
		printf("(%d, %d)\n", S4[i].first, S4[i].second);
	}
	*/
	cout << argv[1] << " " << compareArray(S1, S2) << " " << compareArray(S1, S3) 
		<< " " << compareArray(S1, S4) << " " << endl;
}