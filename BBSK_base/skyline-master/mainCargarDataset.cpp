#include <iostream>

#include "Transformador.h"

#define SIMPLE 0
#define REAL 1

using namespace std;

// ./mainCargarDataset <PATH> <type>
int main(int argc, char * argv[]){
	if(argc < 3){
		cout << "./mainCargarDataset <PATH> <type>\n";
		exit(1);
	}
	int type = atoi(argv[2]);
	if(type != SIMPLE && type != REAL){
		cout << "type == 0 OR type == 1\n";
		exit(1);
	}
	Transformador * t = new Transformador();
	Punto ** dataset;
	if(type == SIMPLE){
		dataset = t->readListPoint(argv[1]);
	}else{
		dataset = t->readFromRealDataset(argv[1]);
	}
	
	
}