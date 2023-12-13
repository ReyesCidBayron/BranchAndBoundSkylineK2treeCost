#include <iostream>
#include <time.h>

#include "kTree.h"
#include "Transformador.h"
#include "SkylineIngenuo.h"
#include "SkylineBBSk.h"
#include "SkylineX.h"

#define SIMPLE 0
#define REAL 1
#define VUELTAS 10

void doTimeTest(char * id, Punto ** dataset, MREP * ktree){
	cout << fixed << ktree->numberOfEdges;
	cout << "\t" << ktree->numberOfNodes;
		
	clock_t tiempoInicial, tiempoFinal;
	double promedioIngenuo = 0;
	double promedioBBSM = 0; //Distancia manhattan
	double promedioBBSE = 0; //Distancia Euclideana
	double promedioX = 0;
	
	SkylineIngenuo * skI = new SkylineIngenuo();
	SkylineBBSk * skBBS = new SkylineBBSk();
	SkylineX * skX = new SkylineX();
	
	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		skI->calculeSkyline(dataset);
	}
	tiempoFinal = clock();
	promedioIngenuo = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioIngenuo = (double) ((promedioIngenuo * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioIngenuo;

	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		skBBS->calculeSkyline(ktree, MANEHATTAN);
	}
	tiempoFinal = clock();
	promedioBBSM = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioBBSM = (double) ((promedioBBSM * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioBBSM;
	
	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		skBBS->calculeSkyline(ktree, EUCLIDEAN);
	}
	tiempoFinal = clock();
	promedioBBSE = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioBBSE = (double) ((promedioBBSE * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioBBSE;

	tiempoInicial = clock();
	for(int i = 0; i < VUELTAS; i++){
		skX->calculeSkyline(ktree);
	}
	tiempoFinal = clock();
	promedioX = (double) ((tiempoFinal - tiempoInicial) / VUELTAS);
	promedioX = (double) ((promedioX * 1000) /  CLOCKS_PER_SEC);
	cout << "\t" << promedioX ;

	cout << "\n";
}

// ./mainTestTime <PATH> <type>
int main(int argc, char * argv[]){
	if(argc < 3){
		cout << "./mainTestTime <PATH> <type>\n";
		exit(1);
	}
	int type = atoi(argv[2]);
	if(type != SIMPLE && type != REAL){
		cout << "type == 0 OR type == 1\n";
		exit(1);
	}
	
	Transformador * t = new Transformador();
	Punto ** dataset;
	if(type == SIMPLE){
		dataset = t->readListPoint(argv[1]);
	}else{
		dataset = t->readFromRealDataset(argv[1]);
	}
	MREP * ktree = loadRepresentation(argv[1]);
		
	doTimeTest(argv[1], dataset, ktree);
	
}