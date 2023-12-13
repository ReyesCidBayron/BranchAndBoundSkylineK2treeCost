#include <iostream>
#include <string>

#include "kTree.h"
#include "Transformador.h"

// ./mainCargarKtree <PATH> 
int main(int argc, char * argv[]){
	if(argc < 2){
		cout << "./mainCargarKtree <PATH>\n";
		exit(1);
	}
		
	Transformador * t = new Transformador();
	ALREP * listaAdyacencia = loadAdyacencyList(argv[1]);
	MREP * ktree = t->fromAdListToKtree(listaAdyacencia);
	saveRepresentation(ktree, argv[1]);
	
	
}