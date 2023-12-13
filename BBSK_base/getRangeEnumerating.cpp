#include <iostream>

#include "libs/EnumeratingRange.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("%s <PATH>\n", argv[0]);
		return -1;
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	EnumeratingRange er;
	er.enumeratingSkyline(kt);
	
}