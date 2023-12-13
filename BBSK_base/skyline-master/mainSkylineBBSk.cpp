#include <iostream>
#include <string>

#include "kTree.h"
#include "SkylineBBSk.h"


// ./mainSkylineBBSk <PATH> <type>
int main(int argc, char * argv[]){
	if(argc < 3){
		cout << "./mainSkylineBBSk <PATH> <type>\n";
		exit(1);
	}
	uint type = atoi(argv[2]);
	if(type != MANEHATTAN && type != EUCLIDEAN){
		cout << "type == 0 OR type == 1\n";
		exit(1);
	}
	MREP * kt = loadRepresentation(argv[1]);
	SkylineBBSk * sk = new SkylineBBSk();
	sk->calculeSkyline(kt, type);
	
}