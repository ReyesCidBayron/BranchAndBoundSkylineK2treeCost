#include "RangeCount.h"

RangeCount::RangeCount(){
	
}

RangeCount::~RangeCount(){
	
}

uint RangeCount::count(MREP * rep, Rectangulo * r){
	return compactRangeQuery(rep, r->getMinimo()->getY(), r->getMaximo()->getY(),
								 r->getMinimo()->getX(), r->getMaximo()->getX())[0][0];
}