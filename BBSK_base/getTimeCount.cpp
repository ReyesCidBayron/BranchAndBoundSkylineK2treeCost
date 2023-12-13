#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <chrono>

#define N 10

#include "libs/NaiveCount.hpp"
#include "libs/Count.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 7){
		printf("%s <PATH> <X_1> <X_2> <Y_1> <Y_2> <OPTION>\n", argv[0]);
		return -1;
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	int x1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y1 = atoi(argv[4]);
	int y2 = atoi(argv[5]);
	int option = atoi(argv[6]);
	
	NaiveCount ncount;
	Count count;
	auto start = chrono::high_resolution_clock::now();
	auto finish = chrono::high_resolution_clock::now();
	long naiveTime = 0;
	long rangeCountTime, compactCountTime;
	
	/* NaiveCount */
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
			ncount.count(points, x1, x2, y1, y2);
		}
		finish = chrono::high_resolution_clock::now();
		naiveTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
		naiveTime /= N;
	}
	
	/* Range Count */
	start = chrono::high_resolution_clock::now();
	for(int i = 0; i < N; i++){
		count.rangeCount(kt, x1, x2, y1, y2);
	}
	finish = chrono::high_resolution_clock::now();
	rangeCountTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	rangeCountTime /= N;
	
	/* Compact Count */
	start = chrono::high_resolution_clock::now();
	for(int i = 0; i < N; i++){
		count.compactCount(kt, x1, x2, y1, y2);
	}
	finish = chrono::high_resolution_clock::now();
	compactCountTime = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	compactCountTime /= N;
	
	cout << argv[1] << " " << naiveTime << " " << rangeCountTime << " " << compactCountTime 
		<< endl;
	
}