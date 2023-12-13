#include <stdio.h>
#include <math.h>
#include <string.h>
#include "libs/kTree.h"

/*****************************************************
Muestra información de archivos .kt en formato
k2-tree
*****************************************************/

int main(int argc, char* argv[]){

	if(argc<2){
		fprintf(stderr,"USAGE: %s <GRAPH>\n",argv[0]);
		return(-1);
	}
	MREP * rep = loadRepresentation(argv[1]);
	printf("********* kTree *********\n");
	printf("rep->numberOfNodes: %d\n", rep->numberOfNodes);
	printf("rep->numberOfEdges: %ld\n", rep->numberOfEdges);
	printf("rep->maxLevel: %d\n", rep->maxLevel);
	printf("rep->bt_len: %d\n", rep->bt_len);
	printf("rep->btl_len: %d\n", rep->btl_len);
	int i;
	printf("Bitmap:\n");
	/*
	for(i=0; i<rep->btl_len; i++){
		printf("%u",isBitSet(rep->btl, i)?1:0);
	}
	*/
	printf("\n********* FIN *********\n");
	destroyRepresentation(rep);
  	return 0;
}
