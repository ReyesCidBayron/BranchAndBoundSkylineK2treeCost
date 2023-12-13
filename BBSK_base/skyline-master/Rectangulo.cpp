#include "Rectangulo.h"

Rectangulo::Rectangulo(Punto * minimo, Punto * maximo){
	this->minimo = minimo;
	this->maximo = maximo;
}

Rectangulo::~Rectangulo(){
    
}

Punto* Rectangulo::getMinimo(){
	return minimo;
}

void Rectangulo::setMinimo(Punto * minimo){
	this->minimo = minimo;
}

Punto* Rectangulo::getMaximo(){
	return maximo;
}

void Rectangulo::setMaximo(Punto * maximo){
	this->maximo = maximo;
}

int Rectangulo::getDistance(ushort option){
    return minimo->getDistance(option);
}

void Rectangulo::print(){
	cout << "Rectangulo: ";
    minimo->print();
    cout << " ";
    maximo->print();
    cout << "\n";
}

bool Rectangulo::isPointInside(Punto * p){
	return this->getMinimo()->getX() <= p->getX() && p->getX() <= this->getMaximo()->getX()
		&& this->getMinimo()->getY() <= p->getY() && p->getY() <= this->getMaximo()->getY();
}



bool Rectangulo::isMatrixInside(Matriz * m){
	return isPointInside(m->getMinimo()) && 
		isPointInside(new Punto(m->getMinimo()->getX() + m->getN() - 1, m->getMinimo()->getY() + m->getN() - 1));
}

bool Rectangulo::intersectMatrix(Matriz * m){
	
	return !(this->getMaximo()->getX() < m->getMinimo()->getX() || 
			 m->getMinimo()->getX() + m->getN() - 1 < this->getMinimo()->getX()) 
		&& !(this->getMaximo()->getY() < m->getMinimo()->getY() || 
			 m->getMinimo()->getY() + m->getN() - 1 < this->getMinimo()->getY());
	
}
