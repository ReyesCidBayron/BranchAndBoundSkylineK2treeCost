#include <iostream>
#include <string>

#include "kTree.h"

using namespace std;

// ./mainCargarKtree <PATH>
int main(int argc, char * argv[]){
	if(argc < 2){
		cout << "./mainCargarKtree <PATH>\n";
		exit(1);
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	
	
}