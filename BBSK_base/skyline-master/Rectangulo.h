#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <iostream>

#include "Punto.h"
#include "Matriz.h"


using namespace std;

class Rectangulo{
public:
	Rectangulo(Punto * minimo, Punto * maximo);
	~Rectangulo();
	Punto* getMinimo();
	Punto* getMaximo();
	void setMinimo(Punto * minimo);
	void setMaximo(Punto * maximo);
    int getDistance(ushort option);
    void print();
	bool isPointInside(Punto * p);
	bool isMatrixInside(Matriz * m);
	bool intersectMatrix(Matriz * m);
private:
	Punto * minimo;
	Punto * maximo;
};

#endif