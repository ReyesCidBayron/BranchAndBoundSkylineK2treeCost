#include "SkylineIngenuo.h"

SkylineIngenuo::SkylineIngenuo(){
	
}

SkylineIngenuo::~SkylineIngenuo(){
	
}


vector<Punto*> SkylineIngenuo::calculeSkyline(Punto ** dataset){
	vector<Punto*> sk;
	uint i = 0;
	uint j = 0;
	Punto * p;
	Punto * q;
	while(!(dataset[i]->getX() == -1 && dataset[i]->getY() == -1)){
		bool pEsSkyline = true;
		j = 0;
		while(!(dataset[j]->getX() == -1 && dataset[j]->getY() == -1)){
			if(dataset[i]->isDominatedBy(dataset[j])){
				pEsSkyline = false;
				break;
			}
			j++;
		}
		if(pEsSkyline){
			sk.push_back(dataset[i]);
		}
		i++;
	}
	
	return sk;
}

