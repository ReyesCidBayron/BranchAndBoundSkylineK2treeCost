#include <iostream>
#include <time.h>

#include "kTree.h"
#include "CompactCount.h"
#include "RangeCount.h"

#define VUELTAS 10

void doTimeTest(char *  id, MREP * ktree){
	cout << fixed << ktree->numberOfEdges;
	cout << "\t" << ktree->numberOfNodes;
		
	CompactCount * cc = new CompactCount();
	RangeCount * rc = new RangeCount();
	clock_t tiempoInicial, tiempoFinal;
	double promedioRange = 0;
	double promedioCompact = 0; 
	uint range, compact;
	
	srand(time(NULL));
	
	uint x_1 = (uint) (rand() % ktree->numberOfNodes);
	uint y_1 = (uint) (rand() % ktree->numberOfNodes);
	
	uint x_2 = (uint) ((x_1 + 1) + rand() % (ktree->numberOfNodes + 1 - (x_1 + 1)));
	uint y_2 = (uint) ((y_1 + 1) + rand() % (ktree->numberOfNodes + 1 - (y_1 + 1)));
	
	Rectangulo * r = new Rectangulo(new Punto(x_1, y_1), new Punto(x_2, y_2));
	
	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		range = rc->count(ktree, r);
	}
	tiempoFinal = clock();
	promedioRange = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioRange = (double) ((promedioRange * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioRange;
	cout << "\t" << range;

	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		compact = cc->count(ktree, r);
	}
	tiempoFinal = clock();
	promedioCompact = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioCompact = (double) ((promedioCompact * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioCompact;
	cout << "\t" << compact;
	
	cout << "\n";
}

// ./mainCountTestTime <PATH>
int main(int argc, char * argv[]){
	if(argc < 2){
		cout << "./mainCountTestTime <PATH> \n";
		exit(1);
	}
	
	
	MREP * ktree = loadRepresentation(argv[1]);
		
	doTimeTest(argv[1], ktree);
	
}