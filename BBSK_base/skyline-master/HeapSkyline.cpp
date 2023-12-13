#include "HeapSkyline.h"


bool cmpM(Matriz * a, Matriz * b){
	return a->getDistance(MANEHATTAN) > b->getDistance(MANEHATTAN);
}

bool cmpE(Matriz * a, Matriz * b){
	return a->getDistance(EUCLIDEAN) > b->getDistance(EUCLIDEAN);
}

bool cmpX(Matriz * a, Matriz * b){
	if(a->getMinimo()->getX() > b->getMinimo()->getX()){
		return true;
	}else{
		if(a->getMinimo()->getX() < b->getMinimo()->getX()){
			return false;
		}else{
			return a->getMinimo()->getY() > b->getMinimo()->getY();
		}
	}
}

HeapSkyline::HeapSkyline(ushort option){
	if(option >= 3){
		cout << "Opcion invalida " << endl;
		exit(1);
	}
	this->option = option;
	make();
	
}

HeapSkyline::~HeapSkyline(){
    
}

void HeapSkyline::insert(Matriz * m){
	heap.push_back(m);
	push();
	
}

Matriz* HeapSkyline::get(){
	Matriz *m = heap.front();
	while(!esMenor(m)){
		make();
		m = heap.front();
	}
	heap.erase(heap.begin());
	pop();
	return m;
}

bool HeapSkyline::esMenor(Matriz * m){
	for(Matriz * n : heap){
		if(option == EQUIS){
			if(n->getMinimo()->getX() < m->getMinimo()->getX()){
				return false;
			}else{
				if(n->getMinimo()->getX() == m->getMinimo()->getX()){
					if(n->getMinimo()->getY() < m->getMinimo()->getY()){
						return false;
					}
				}
			}
		}else{
			if(n->getDistance(option) < m->getDistance(option)){
				return false;
			}
		}
	}
	return true;
}

void HeapSkyline::print(){
    for(Matriz * m: heap){
	    cout << "I=" <<m->getI() << ";Dist=" << m->getDistance(option) << " - ";
	}
	cout << "\n";
}

int HeapSkyline::size(){
    return heap.size();
}

void HeapSkyline::push(){
	switch(option){
		case MANEHATTAN:
			push_heap(heap.begin(), heap.end(), cmpM);
			break;
		case EUCLIDEAN:
			push_heap(heap.begin(), heap.end(), cmpE);
			break;
		case EQUIS:
			push_heap(heap.begin(), heap.end(), cmpX);
			break;
	}
	
}

void HeapSkyline::pop(){
	switch(option){
		case MANEHATTAN:
			pop_heap(heap.begin(), heap.end(), cmpM);
			break;
		case EUCLIDEAN:
			pop_heap(heap.begin(), heap.end(), cmpE);
			break;
		case EQUIS:
			pop_heap(heap.begin(), heap.end(), cmpX);
			break;
	}
}

void HeapSkyline::make(){
	switch(option){
		case MANEHATTAN:
			make_heap(heap.begin(), heap.end(), cmpM);
			break;
		case EUCLIDEAN:
			make_heap(heap.begin(), heap.end(), cmpE);
			break;
		case EQUIS:
			make_heap(heap.begin(), heap.end(), cmpX);
			break;
	}
}