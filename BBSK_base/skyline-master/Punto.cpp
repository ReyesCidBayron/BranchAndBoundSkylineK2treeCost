#include "Punto.h"

Punto::Punto(int x, int y){
	this->x = x;
	this->y = y;
	dom = 0;
}

Punto::~Punto(){
	
}

int Punto::getX(){
	return x;
}

int Punto::getY(){
	return y;
}

uint Punto::getDom(){
	return dom;
}

void Punto::setX(int x){
	this->x = x;
}

void Punto::setY(int y){
	this->y = y;
}

void Punto::setDom(uint dom){
	this->dom = dom;
}

int Punto::getDistance(ushort option){
    if(option == MANEHATTAN){
		return getManehattanDistance();
	}
	if(option == EUCLIDEAN){
		return getEuclideanDistance();
	}
	if(option == EQUIS){
		return getXDistance();
	}
	cout << "Invalid distance option " << endl;
	exit(1);
}

void Punto::print(){
    cout << "Punto: (" << x << "," << y << ") Dom: " << dom << " ";
}

int Punto::getManehattanDistance(){
	return (x + y);
}

int Punto::getEuclideanDistance(){
	return (x*x + y*y);
}

int Punto::getXDistance(){
	return x;
}

bool Punto::isDominatedBy(Punto * p){
	return (p->getX() <= this->getX() && p->getY() <= this->getY()) 
        && (p->getX() < this->getX() || p->getY() < this->getY());
}