#include <iostream>
#include <string>

#include "kTree.h"
#include "EnumeratingRange.h"


// ./mainEnumeratingRange <PATH>
int main(int argc, char * argv[]){
	if(argc < 2){
		cout << "./mainEnumeratingRange <PATH>\n";
		exit(1);
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	EnumeratingRange * esk = new EnumeratingRange();
	esk->enumeratingSkyline(kt);
	
}