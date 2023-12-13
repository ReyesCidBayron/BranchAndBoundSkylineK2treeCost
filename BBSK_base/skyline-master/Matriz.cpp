#include "Matriz.h"

Matriz::Matriz(Punto * minimo, uint n, int i){
	this->minimo = minimo;
	this->n = n;
    this->i = i;
}

Matriz::~Matriz(){
    
}

Punto* Matriz::getMinimo(){
	return minimo;
}

void Matriz::setMinimo(Punto * minimo){
	this->minimo = minimo;
}

uint Matriz::getN(){
	return n;
}

void Matriz::setN(uint n){
	this->n = n;
}

int Matriz::getI(){
    return i;
}

void Matriz::setI(int i){
    this->i = i;
}

int Matriz::getDistance(ushort option){
    return minimo->getDistance(option);
}

void Matriz::print(){
	cout << "Matriz: ";
    cout << "I= " << this->i;
	cout << " N= " << this->n;
	cout << " P= ";
	this->minimo->print();
	cout << "("<< this->minimo->getX() + this->n - 1 << "," << this->minimo->getY() + this->n - 1 << ")";
	cout << "\n";
}

bool Matriz::isPointInside(Punto * p){
	return this->getMinimo()->getX() <= p->getX() &&  p->getX() <= this->getMinimo()->getX() + this->getN()
		&& this->getMinimo()->getY() <= p->getY() &&  p->getY() <= this->getMinimo()->getY() + this->getN();
}
