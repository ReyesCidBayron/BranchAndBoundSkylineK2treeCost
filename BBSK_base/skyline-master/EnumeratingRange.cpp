#include "EnumeratingRange.h"


EnumeratingRange::EnumeratingRange(){
    
}

EnumeratingRange::~EnumeratingRange(){

}

/*
	Utiliza la consulta de puntos por rango para obtener la cantidad de puntos dominados por cada punto del Skyline
*/
vector<Punto*> EnumeratingRange::enumeratingSkyline(MREP * rep){
	SkylineBBSk * skBBS = new SkylineBBSk();
    vector<Punto*> S = skBBS->calculeSkyline(rep, MANEHATTAN);
	for(Punto * p : S){
		p->setDom(compactRangeQuery(rep, p->getY(), rep->numberOfNodes - 1,
								 p->getX(), rep->numberOfNodes - 1)[0][0] - 1);
		
	}
    return S;
}

/*
	Utiliza el conteo compacto para obtener la cantidad de puntos dominados por cada punto del Skyline
*/
vector<Punto*> EnumeratingRange::enumeratingCompactSkyline(MREP * rep){
	SkylineBBSk * skBBS = new SkylineBBSk();
	CompactCount * cc = new CompactCount();
    vector<Punto*> S = skBBS->calculeSkyline(rep, MANEHATTAN);
	for(Punto * p : S){
		p->setDom(cc->count(rep, new Rectangulo(p, new Punto(rep->numberOfNodes, rep->numberOfNodes))) - 1);
		
	}
    return S;
}
