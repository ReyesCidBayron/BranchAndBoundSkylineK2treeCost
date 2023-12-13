#include <iostream>

#include "libs/BBSK.hpp"

using namespace std;

int main(int argc, char * argv[]){
	if(argc < 2){
		printf("%s <PATH>\n", argv[0]);
		return -1;
	}
	
	MREP * kt = loadRepresentation(argv[1]);
	BBSK bbsk;


        vector<pair<int, int>> * skyline = bbsk.skylineManhattan(kt);


		// Imprime por pantalla la cantidad de puntos skyline obtenidos
		cout << "Cantidad de puntos Skyline (S): " << skyline->size() << endl;
		// Imprime por pantalla las coordenadas de los puntos skyline
		cout << "Puntos Skyline (x,y):" << endl;
		for(int i = 0; i < skyline->size(); i++){
			cout << "\t(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;
		}
	
	
}
