#include "SkylineX.h"

SkylineX::SkylineX(){
    
}

SkylineX::~SkylineX(){

}

vector<Punto*> SkylineX::calculeSkyline(MREP * rep){
	HeapSkyline * heap = new HeapSkyline(EQUIS);
    Rectangulo * r = new Rectangulo(new Punto(0, 0), new Punto(rep->numberOfNodes, rep->numberOfNodes));
	vector<Matriz*> Q;
	vector<Punto*> S;
    heap->insert(new Matriz(new Punto(0,0), rep->numberOfNodes, -1));
	while(heap->size() != 0){
        Matriz * n = heap->get();
		if(r->intersectMatrix(n)){
			if(isALeaf(rep, n->getI())){
				S.push_back(n->getMinimo());
				readjustRectangle(n->getMinimo(), r);
			}else{
				uint firstChild = getFirstChild(rep, n->getI());
				for(uint i = 0; i < pow(K, 2); i++){
					if(!subMatrixIsEmpty(rep, firstChild + i) && !pruned(rep, firstChild, i)){
						Matriz * n_i = getChildMatrix(rep, n, i);
						if(r->intersectMatrix(n_i)){
							heap->insert(n_i);
						}
					}
				}
			}
			
		}
	}
	
    return S;
}

void  SkylineX::readjustRectangle(Punto * p, Rectangulo * r){
	r->getMinimo()->setX(p->getX() + 1);
	r->getMaximo()->setY(p->getY() - 1);
}

