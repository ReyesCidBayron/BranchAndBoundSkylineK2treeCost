#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

#include "Punto.h"


using namespace std;

class Matriz{
public:
	Matriz(Punto* minimo, uint n, int i);
	~Matriz();
	Punto *getMinimo();
	uint getN();
    int getI();
	void setMinimo(Punto* minimo);
	void setN(uint n);
    void setI(int i);
    int getDistance(ushort option);
    void print();
	bool isPointInside(Punto * p);
private:
	Punto *minimo;
	int n;
    int i;
};

#endif