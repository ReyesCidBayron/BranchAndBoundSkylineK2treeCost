#include <iostream>
#include <string>

#include "kTree.h"
#include "EnumeratingCompact.h"


// ./mainEnumeratingCompact <PATH>
int main(int argc, char * argv[]){
	if(argc < 2){
		cout << "./mainEnumeratingCompact <PATH>\n";
		exit(1);
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	
	EnumeratingCompact * esk = new EnumeratingCompact();
	esk->enumeratingSkyline(kt);
}