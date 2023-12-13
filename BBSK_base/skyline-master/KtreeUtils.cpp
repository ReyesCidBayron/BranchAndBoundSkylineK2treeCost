#include "KtreeUtils.h"

bool isALeaf(MREP * rep, int i){
	if(i == -1) return false;
	return i >= rep->bt_len;
}

bool subMatrixIsEmpty(MREP * rep, uint i){
	return !isBitSet(rep->btl, i);
}

uint getFirstChild(MREP * rep, uint i){
	if(i == -1) return 0;
    return rank1(rep->btl, i) * pow(K,2);
}

uint getLastChild(MREP * rep, int i){
	if(i == -1) return pow(K,2) - 1;
    return rank1(rep->btl, i) * pow(K,2) + pow(K,2) - 1;
}

bool pruned(MREP * rep, uint firstChild, uint i){
	bool isOne = false;
    for(ushort j = 0; j < (i / K); j++){
        for(ushort l = 0; l < (i % K); l++){
            isOne = isOne || isBitSet(rep->btl, firstChild + l);
        }
    }
    return isOne;
}

Matriz* getChildMatrix(MREP * rep, Matriz * m, uint i){
	int minX = m->getMinimo()->getX() + (m->getN() / K) * (i % K);
    int minY = m->getMinimo()->getY() + (m->getN() / K) * ceil( i / K);
    Punto * min = new Punto(minX,minY);
    return new Matriz(min, m->getN() / K, getFirstChild(rep, m->getI()) + i);
}

Punto* getChildPoint(MREP * rep, Matriz * m, uint i){
	int x = m->getMinimo()->getX() + (i % K);
    int y = m->getMinimo()->getY() + ceil( i / K);
    Punto * p = new Punto(x,y);
    return p;
}


void printKtree(MREP * rep){
	printf("********* kTree *********\n");
	printf("rep->numberOfNodes: %d\n", rep->numberOfNodes);
	printf("rep->numberOfEdges: %ld\n", rep->numberOfEdges);
	printf("rep->maxLevel: %d\n", rep->maxLevel);
	printf("rep->bt_len: %d\n", rep->bt_len);
	printf("rep->btl_len: %d\n", rep->btl_len);
	int i;
	printf("Bitmap:\n");
	for(i=0; i<rep->btl_len; i++){
		//printf("%u=%u\n", i,  isBitSet(rep->btl, i)?1:0);
	}
	printf("\n********* FIN *********\n");
}