#include <iostream>

#include "libs/EnumeratingCompact.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("%s <PATH>\n", argv[0]);
		return -1;
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	EnumeratingCompact ec;
	ec.enumeratingSkyline(kt);
}