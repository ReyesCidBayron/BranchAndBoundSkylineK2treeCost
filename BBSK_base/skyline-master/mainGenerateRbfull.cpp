#include <iostream>
#include <string>

#include "Transformador.h"
#include "adylist.h"

#define SIMPLE 0
#define REAL 1

// ./mainGenerateRbfull <PATH> <type>
int main(int argc, char * argv[]){
	if(argc < 3){
		cout << "./mainGenerateRbfull <PATH> <type>\n";
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
	
	ALREP * listaAdyacencia = t->fromListPointToAdList(dataset);
	saveAdyacencyList(listaAdyacencia, argv[1]);
	
	
}