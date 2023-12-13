#include <iostream>
#include <string>
#include <fstream>
#define N 100

using namespace std;

int main(int argc, char ** argv){
	if(argc != 2){
		printf("ERROR! USE %s <filename>\n", argv[0]);
		return -1;
	}
	ifstream in;
	in.open(argv[1]);
	if(!in.is_open()){
		printf("Archivo %s no encontrado\n", argv[1]);
		return -1;
	}
	
	printf("LOS TIEMPOS ESTAN EN MICROSEGUNDOS\n");
	printf("Datos reales\n");
	
	ofstream out;
	
	string nombre;
	int ktree, bbsm, bbse, skx, zero;
	float promBbsm, promBbse, promSkx;
	float tamRang[] = {0.01, 0.1, 1, 10, 25, 50, 99, 100};
	int expRang = 8;
	
	out.open("time_constrained.txt");
	
	for(int k = 0; k < expRang; k++){
		promBbsm = 0.0;
		promBbse = 0.0;
		promSkx = 0.0;
		for(int i = 0; i < 12; i++){
			in >> nombre >> zero >> bbsm >> bbse >> skx;
			promBbsm += bbsm;
			promBbse += bbse;
			promSkx += skx;
		}
		promBbsm /= 12;
		promBbse /= 12;
		promSkx /= 12;

		out << tamRang[k] << "\t" << "\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
	}
	
	out.close();
	
	in.close();
	
	return 0;
}