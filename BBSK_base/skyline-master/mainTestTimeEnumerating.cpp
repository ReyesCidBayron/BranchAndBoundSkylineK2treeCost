#include <iostream>
#include <time.h>

#include "kTree.h"
#include "EnumeratingRange.h"
#include "EnumeratingCompact.h"

#define VUELTAS 10

void doTimeTest(char *  id, MREP * ktree){
	cout << fixed << ktree->numberOfEdges;
	cout << "\t" << ktree->numberOfNodes;
		
	clock_t tiempoInicial, tiempoFinal;
	double promedioRange = 0;
	double promedioCompact = 0;
	double promedioCountCompact = 0;
	vector<Punto*> range, compact, rangeCompact;
	
	EnumeratingRange * eskrange = new EnumeratingRange();
	EnumeratingCompact * eskcompact = new EnumeratingCompact();
	
	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		range = eskrange->enumeratingSkyline(ktree);
	}
	tiempoFinal = clock();
	promedioRange = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioRange = (double) ((promedioRange * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioRange;

	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		rangeCompact = eskrange->enumeratingCompactSkyline(ktree);
	}
	tiempoFinal = clock();
	promedioCountCompact = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioCountCompact = (double) ((promedioCountCompact * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioCountCompact;
	
	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		compact = eskcompact->enumeratingSkyline(ktree);
	}
	tiempoFinal = clock();
	promedioCompact = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioCompact = (double) ((promedioCompact * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioCompact;
		
	cout << "\n";
}

// ./mainEnumeratingTestTime <PATH>
int main(int argc, char * argv[]){
	if(argc < 2){
		cout << "./mainEnumeratingTestTime <PATH> \n";
		exit(1);
	}
	
	MREP * ktree = loadRepresentation(argv[1]);
		
	doTimeTest(argv[1], ktree);
	
}