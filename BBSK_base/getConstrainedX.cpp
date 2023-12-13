#include <iostream>

#include "libs/ConstrainedX.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 6){
		printf("%s <PATH> <X_1> <X_2> <Y_1> <Y_2>\n", argv[0]);
		return -1;
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	int x1 = atoi(argv[2]);
	int x2 = atoi(argv[3]);
	int y1 = atoi(argv[4]);
	int y2 = atoi(argv[5]);
	ConstrainedX cx;
	cx.constrainedX(kt, x1, x2, y1, y2);
	
	
}