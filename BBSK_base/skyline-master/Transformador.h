#ifndef TRANSFORMADOR_H
#define TRANSFORMADOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
#include <algorithm>

#include "Punto.h"
#include "kTree.h"
#include "adylist.h"


using namespace std;

class Transformador{
public:
	Transformador();
	~Transformador();
	
	Punto ** readListPoint(char * path);
	Punto ** readFromRealDataset(char * path);
	ALREP * fromListPointToAdList(Punto ** dataset);
	MREP * fromAdListToKtree(ALREP * listaAdyacencia);
	void printAdList(ALREP * listaAdyacencia);
private:
	Punto ** order(Punto ** dataset, uint nodos);
	uint calcularNodes(Punto ** dataset);
	ulong calcularEdges(Punto ** dataset);
	//bool menor(Punto * a, Punto * b);
	int * enlargeAdList(int * lista, ulong tamano);
	Punto ** enlargeListPoints(Punto ** lista, ulong tamano);
};

#endif