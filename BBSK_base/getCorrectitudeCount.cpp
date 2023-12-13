#include <iostream>
#include <fstream>
#include <string>

#include "libs/NaiveCount.hpp"
#include "libs/Count.hpp"

using namespace std;

bool compareNumber(int v1, int v2){
	return v1 == v2;
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
	NaiveCount ncount;
	Count count;
	int x1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y1 = atoi(argv[4]);
	int y2 = atoi(argv[5]);
	
	int c1 = ncount.count(points, x1, x2, y1, y2);
	int c2 = count.rangeCount(kt, x1, x2, y1, y2);
	int c3 = count.compactCount(kt, x1, x2, y1, y2);
		
	cout << argv[1] << " " << compareNumber(c1, c2) << " " << compareNumber(c1, c3) << endl;
	
}