#include <iostream>
#include <string>

#include "kTree.h"
#include "CompactCount.h"


// ./mainCompactCount <PATH> <x1> <x2> <y1> <y2>
int main(int argc, char * argv[]){
	if(argc < 6){
		cout << "./mainCompactCount <PATH> <x1> <x2> <y1> <y2>\n";
		exit(1);
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	
	int x1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y1 = atoi(argv[4]);
	int y2 = atoi(argv[5]);
	
	Rectangulo * r = new Rectangulo(new Punto(x1, y1), new Punto(x2, y2));
	
	CompactCount * cc = new CompactCount();
	cc->count(kt, r);
}