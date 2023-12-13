#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <chrono>

#define Ni 100

#include "libs/NaiveEnumerating.hpp"
#include "libs/EnumeratingRange.hpp"
#include "libs/EnumeratingCompact.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 3){
		printf("%s <PATH> <OPTION>\n", argv[0]);
		return -1;
	}
	MREP * kt = loadRepresentation(argv[1]);
	NaiveEnumerating en;
	EnumeratingRange er;
	EnumeratingCompact ec;
	auto start = chrono::high_resolution_clock::now();
	auto finish = chrono::high_resolution_clock::now();
	long naiveTime = 0;
	long rangeTime, rangeCompactTime, compactTime;
	int option = atoi(argv[2]);
	
	/* Naive Enumerating */
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
		for(int i = 0; i < Ni; i++){
			en.enumeratingSkyline(points);
		}
		finish = chrono::high_resolution_clock::now();
		naiveTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
		naiveTime /= Ni;
	}
	
	/* Enumerating Range */
	start = chrono::high_resolution_clock::now();
	for(int i = 0; i < Ni; i++){
		er.enumeratingSkyline(kt);
	}
	finish = chrono::high_resolution_clock::now();
	rangeTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	rangeTime /= Ni;
	
	/* Enumerating range compact */
	start = chrono::high_resolution_clock::now();
	for(int i = 0; i < Ni; i++){
		er.enumeratingSkylineCompact(kt);
	}
	finish = chrono::high_resolution_clock::now();
	rangeCompactTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	rangeCompactTime /= Ni;
	
	/* Enumerating Compact */
	start = chrono::high_resolution_clock::now();
	for(int i = 0; i < Ni; i++){
		ec.enumeratingSkyline(kt);
	}
	finish = chrono::high_resolution_clock::now();
	compactTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	compactTime /= Ni;
	
	cout << argv[1] << " " << naiveTime << " " << rangeTime << " " << rangeCompactTime << " " 
		<< compactTime << endl;
	
}