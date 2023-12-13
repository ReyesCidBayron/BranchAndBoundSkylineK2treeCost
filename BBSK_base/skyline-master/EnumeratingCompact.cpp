#include "EnumeratingCompact.h"

#define K 2

EnumeratingCompact::EnumeratingCompact(){
	
}

EnumeratingCompact::~EnumeratingCompact(){
	
}

vector<Punto*> EnumeratingCompact::enumeratingSkyline(MREP * rep){
	cc = new CompactCount();
	HeapSkyline * heap= new HeapSkyline(MANEHATTAN);
	vector<Punto*> S;
	N = new uint[rank1(rep->btl, rep->bt_len) + 1];
    heap->insert(new Matriz(new Punto(0,0), rep->numberOfNodes, -1));
    while(heap->size() != 0){
        Matriz * n = heap->get();
        if(!isDominatedByS(n, S)){
            uint firstChild = getFirstChild(rep, n->getI());
            for(uint i = 0; i < pow(K, 2); i++){
				Matriz * n_i = getChildMatrix(rep, n, i);
                if(!subMatrixIsEmpty(rep, firstChild + i) && !isDominatedByS(n_i, S)){
                    if(!pruned(rep, firstChild, i)){
						if(!isALeaf(rep, firstChild + i)){
							heap->insert(n_i);
						}else{
							Punto * point = getChildPoint(rep, n, i);
							point->setDom(enumeratingCount(rep, new Rectangulo(point, 
											new Punto(rep->numberOfNodes, rep->numberOfNodes))) - 1);
							S.push_back(point);
						}
					}else{
						if(N[rank1(rep->btl, n_i->getI())] == 0){
							N[rank1(rep->btl, n_i->getI())] = cc->getN(rep, n_i->getI());
						}
					}				
                }
            }
        }
    }

    return S;
}

uint EnumeratingCompact::enumeratingCount( MREP * rep, Rectangulo * r){
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
						if(N[rank1(rep->btl, n_i->getI())] == 0){
							N[rank1(rep->btl, n_i->getI())] = cc->getN(rep, n_i->getI());
						}
						total += N[rank1(rep->btl, n_i->getI())];
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



bool EnumeratingCompact::isDominatedByS(Matriz * m, vector<Punto*> S){
    for(Punto * p : S){
        if(m->getMinimo()->isDominatedBy(p)){
            return true;
        }
    }
    return false;
}

bool EnumeratingCompact::isDominatedByS(Punto * q, vector<Punto*> S){
    for(Punto * p : S){
        if(q->isDominatedBy(p)){
            return true;
        }
    }
    return false;
}
