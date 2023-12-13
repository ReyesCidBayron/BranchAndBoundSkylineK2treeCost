#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <chrono>

#define N 100

#include "libs/NaiveSkyline.hpp"
#include "libs/BBSK.hpp"
#include "libs/SkylineX.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 3){
		printf("%s <PATH> <OPTION>\n", argv[0]);
		return -1;
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	
	NaiveSkyline ns;
	BBSK bbsk;
	SkylineX skx;
	auto start = chrono::high_resolution_clock::now();
	auto finish = chrono::high_resolution_clock::now();
	long naiveTime = 0;
	long BBSKMTime, BBSKETime, SkylineXTime;
	int option = atoi(argv[2]);
	
	/* NaiveSkyline */
	if(option == 0){
		/* Carga de puntos */
	
		string completo(argv[1]);
		completo+= ".txt";
		ifstream fe(completo.c_str());
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
		start = chrono::high_resolution_clock::now();
		for(int i = 0; i < N; i++){
			ns.skyline(points);
		}
		finish = chrono::high_resolution_clock::now();
		naiveTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
		naiveTime /= N;
	}
	
	/* BBSK Manhattan*/
	start = chrono::high_resolution_clock::now();
	for(int i = 0; i < N; i++){
		bbsk.skylineManhattan(kt);
	}
	finish = chrono::high_resolution_clock::now();
	BBSKMTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	BBSKMTime /= N;
	
	/* BBSK Euclidean */
	start = chrono::high_resolution_clock::now();
	for(int i = 0; i < N; i++){
		bbsk.skylineEuclidean(kt);
	}
	finish = chrono::high_resolution_clock::now();
	BBSKETime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	BBSKETime /= N;
	
	/* Skyline X */
	start = chrono::high_resolution_clock::now();
	for(int i = 0; i < N; i++){
		skx.skylineX(kt);
	}
	finish = chrono::high_resolution_clock::now();
	SkylineXTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	SkylineXTime /= N;
	
	cout << argv[1] << " " << naiveTime << " " << BBSKMTime << " " << BBSKETime << " " 
		<< SkylineXTime << endl;
	
}