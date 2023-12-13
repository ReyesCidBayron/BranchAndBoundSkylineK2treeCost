#include <iostream>
#include <string>

#include "kTree.h"
#include "SkylineX.h"

// ./mainSkylineX <PATH> 
int main(int argc, char * argv[]){
	if(argc < 2){
		cout << "./mainSkylineX <PATH> \n";
		exit(1);
	}
		
	MREP * kt = loadRepresentation(argv[1]);
	SkylineX * sk = new SkylineX();
	sk->calculeSkyline(kt);
	
}