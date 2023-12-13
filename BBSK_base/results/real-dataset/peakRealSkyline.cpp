#include <iostream>
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
	
	printf("LA MEMORIA ESTA EN KILOBYTES\n");
	printf("Datos reales\n");
	
	ofstream out;
	
	int ktree, bbsm, bbse, skx;
	float promBbsm, promBbse, promSkx;
	
	out.open("peak_skyline.txt");
	
	for(int i = 0; i < 12; i++){
		promBbsm = 0.0;
		promBbse = 0.0;
		promSkx = 0.0;
		for(int j = 0; j < N; j++){
			in >> bbsm >> bbse >> skx >> ktree;
			promBbsm += (bbsm-ktree) > 0 ? (bbsm-ktree) : 0;
			promBbse += (bbse-ktree) > 0 ? (bbse-ktree) : 0;
			promSkx += (skx-ktree) > 0 ? (skx-ktree) : 0;
		}
		promBbsm /= N;
		promBbse /= N;
		promSkx /= N;
		
		out << i << "\t" << "\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
	}
	
	out.close();
	
	in.close();
	
	return 0;
}