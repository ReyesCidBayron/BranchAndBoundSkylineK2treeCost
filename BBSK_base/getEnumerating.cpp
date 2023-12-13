#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>

#include "libs/NaiveEnumerating.hpp"
#include "libs/EnumeratingRange.hpp"
#include "libs/EnumeratingCompact.hpp"

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
	
	NaiveEnumerating en;
	EnumeratingRange er;
	EnumeratingCompact ec;
	vector<pair<pair<int, int>, int>> naive = *(en.enumeratingSkyline(points));
	vector<pair<pair<int, int>, int>> range = *(er.enumeratingSkyline(kt));
	vector<pair<pair<int, int>, int>> compa = *(er.enumeratingSkylineCompact(kt));
	vector<pair<pair<int, int>, int>> cc = *(ec.enumeratingSkyline(kt));
	
	cout << "Enumerating Skyline Naive: " << endl;
	for(int i = 0; i < naive.size(); i++){
		printf("(%d,%d), %d\n", naive[i].first.first, naive[i].first.second, naive[i].second);
	}
	
	cout << "Enumerating Range: " << endl;
	for(int i = 0; i < range.size(); i++){
		printf("(%d,%d), %d\n", range[i].first.first, range[i].first.second, range[i].second);
	}
	
	cout << "Enumerating Range Compact: " << endl;
	for(int i = 0; i < compa.size(); i++){
		printf("(%d,%d), %d\n", compa[i].first.first, compa[i].first.second, compa[i].second);
	}
	
	cout << "Enumerating Compact Count: " << endl;
	for(int i = 0; i < cc.size(); i++){
		printf("(%d,%d), %d\n", cc[i].first.first, cc[i].first.second, cc[i].second);
	}
	
}