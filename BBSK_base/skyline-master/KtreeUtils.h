#include <math.h>

#include "kTree.h"
#include "Punto.h"
#include "Matriz.h"

bool isALeaf(MREP * rep, int i);
bool subMatrixIsEmpty(MREP * rep, uint i);
uint getFirstChild(MREP * rep, uint i);
uint getLastChild(MREP * rep, int i);
bool pruned(MREP * rep, uint firstChild, uint i);
Matriz* getChildMatrix(MREP * rep, Matriz * m, uint i);
Punto* getChildPoint(MREP * rep, Matriz * m, uint i);
void printKtree(MREP * rep);