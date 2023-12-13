#ifndef PUNTO_H
#define PUNTO_H

#define MANEHATTAN 0
#define EUCLIDEAN 1
#define EQUIS 2

#include <iostream>

using namespace std;

class Punto{
public:
	Punto(int x, int y);
	~Punto();
	int getX();
	int getY();
	uint getDom();
	void setX(int x);
	void setY(int y);
	void setDom(uint dom);
    int getDistance(ushort option);
    void print();
	bool isDominatedBy(Punto * p);
	
private:
	int x;
	int y;
	uint dom; //Cantidad de puntos dominados
	int getManehattanDistance();
	int getEuclideanDistance();
	int getXDistance();
};

#endif