#include "CompactCount.h"

CompactCount::CompactCount(){
	
}

CompactCount::~CompactCount(){
	
}

uint CompactCount::count(MREP * rep, Rectangulo * r){
	uint total = 0;
	vector<Matriz*> cola;
	cola.push_back(new Matriz(new Punto(0,0), rep->numberOfNodes, -1));
	while(cola.size() != 0){
		Matriz * n = cola.front();
		uint firstChild = getFirstChild(rep, n->getI());
		for(uint i = 0; i < pow(K, 2); i++){
			if(!subMatrixIsEmpty(rep, firstChild + i)){
				Matriz * n_i = getChildMatrix(rep, n, i);
				if(r->isMatrixInside(n_i)){
					if(!isALeaf(rep, firstChild + i)){
						total += this->getN(rep, n_i->getI());
					}else{
						total++;
					}				
				}else{
					if(r->intersectMatrix(n_i)){
						cola.push_back(n_i);
					}
				}
			}
		}
		cola.erase(cola.begin());
	}
	return total;
}


uint CompactCount::getN(MREP * rep, int i){
	if(i != -1 && isBitSet(rep->btl, i) == 0){
		return 0;
	}
	if(isALeaf(rep, i)){
		return isBitSet(rep->btl, i) ? 1 : 0;
	}
	int inicio = i;
	int fin = i;
	while(!isALeaf(rep, inicio) && !isALeaf(rep, fin)){
		inicio = getFirstChild(rep, inicio);
		fin = getLastChild(rep, fin);
		if(!isALeaf(rep, inicio)){
			//Ajustar inicio no vacio
			inicio = adjustFirstChild(rep, inicio);
		}
		if(!isALeaf(rep, fin)){
			//Ajustar fin no vacio
			fin = adjustLastChild(rep, fin);
		}

	}
	inicio--;

	
	return rank1(rep->btl, fin) - rank1(rep->btl, inicio);
}

uint CompactCount::adjustFirstChild(MREP * rep, uint i){
	if(isBitSet(rep->btl, i) == 0)
    	return select1(rep->btl, rank1(rep->btl, i) + 1);
	else
		return i;
}

uint CompactCount::adjustLastChild(MREP * rep, uint i){
	if(isBitSet(rep->btl, i) == 0)
    	return select1(rep->btl, rank1(rep->btl, i));
	else
		return i;
}