#include "SkylineBBSk.h"


SkylineBBSk::SkylineBBSk(){
    
}

SkylineBBSk::~SkylineBBSk(){

}

vector<Punto*> SkylineBBSk::calculeSkyline(MREP * rep, ushort distanceOption){
    HeapSkyline * heap= new HeapSkyline(distanceOption);
	vector<Punto*> S;
	heap->insert(new Matriz(new Punto(0,0), rep->numberOfNodes, -1));
    while(heap->size() != 0){
        Matriz * n = heap->get();
        if(!isDominatedByS(n->getMinimo(), S)){
            uint firstChild = getFirstChild(rep, n->getI());
            for(uint i = 0; i < pow(K, 2); i++){
                if(!subMatrixIsEmpty(rep, firstChild + i) && !pruned(rep, firstChild, i)){
                    Matriz * n_i = getChildMatrix(rep, n, i);
                    if(!isDominatedByS(n_i->getMinimo(), S)){
                        if(!isALeaf(rep, firstChild + i)){
                            heap->insert(n_i);
                        }else{
                            S.push_back(getChildPoint(rep, n, i));
                        }
                    }
                    
                    
                }
            }
        }
    }

    return S;
}


bool SkylineBBSk::isDominatedByS(Punto * q, vector<Punto*> S){
    for(Punto * p : S){
        if(q->isDominatedBy(p)){
            return true;
        }
    }
    return false;
}
