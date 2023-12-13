#include <iostream>
#include <string>

#include "kTree.h"
#include "RangeCount.h"

// ./mainRangeCount <PATH> <x1> <x2> <y1> <y2>
int main(int argc, char * argv[]){
	if(argc < 2){
		std::cout << "./mainRangeCount <PATH> <x1> <x2> <y1> <y2>\n";
		exit(1);
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	
	int x1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y1 = atoi(argv[4]);
	int y2 = atoi(argv[5]);
	
	Rectangulo * r = new Rectangulo(new Punto(x1, y1), new Punto(x2, y2));
	
	RangeCount * rc = new RangeCount();
	rc->count(kt, r);
	
}