#include <iostream>
#include <fstream>
#define N 10

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
	
	ofstream out;
	
	string filename;
	int naive, bbsm, bbse, skx;
	float promNaive, promBbsm, promBbse, promSkx;
	
	float cantPunt[] = {0.1, 0.5, 1, 5, 10, 50};
	int expCant = 6;
	float dens[] = {1, 5, 10};
	int expDens = 3;
	
	printf("DATOS UNIFORMES\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_skyline_cant_uni.txt");
	for(int i = 0; i < expCant; i++){
		promNaive = 0.0;
		promBbsm = 0.0;
		promBbse = 0.0;
		promSkx = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> bbsm >> bbse >> skx;
			promNaive += naive;
			promBbsm += bbsm;
			promBbse += bbse;
			promSkx += skx;
		}
		
		promNaive /= N;
		promBbsm /= N;
		promBbse /= N;
		promSkx /= N;
		
		out << cantPunt[i] << "\t" << promNaive << "\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_skyline_dens_uni.txt");
	for(int i = 0; i < expDens; i++){
		promNaive = 0.0;
		promBbsm = 0.0;
		promBbse = 0.0;
		promSkx = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> bbsm >> bbse >> skx;
			promNaive += naive;
			promBbsm += bbsm;
			promBbse += bbse;
			promSkx += skx;
		}
		
		promNaive /= N;
		promBbsm /= N;
		promBbse /= N;
		promSkx /= N;
		
		out << dens[i] << "\t" << promNaive << "\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DATOS CLUSTERIZADOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_skyline_cant_clu.txt");
	for(int i = 0; i < expCant; i++){
		promNaive = 0.0;
		promBbsm = 0.0;
		promBbse = 0.0;
		promSkx = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> bbsm >> bbse >> skx;
			promNaive += naive;
			promBbsm += bbsm;
			promBbse += bbse;
			promSkx += skx;
		}
		
		promNaive /= N;
		promBbsm /= N;
		promBbse /= N;
		promSkx /= N;
		
		out << cantPunt[i] << "\t" << promNaive << "\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_skyline_dens_clu.txt");
	for(int i = 0; i < expDens; i++){
		promNaive = 0.0;
		promBbsm = 0.0;
		promBbse = 0.0;
		promSkx = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> bbsm >> bbse >> skx;
			promNaive += naive;
			promBbsm += bbsm;
			promBbse += bbse;
			promSkx += skx;
		}
		
		promNaive /= N;
		promBbsm /= N;
		promBbse /= N;
		promSkx /= N;
		
		out << dens[i] << "\t" << promNaive << "\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DATOS MIXTOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_skyline_cant_mix.txt");
	for(int i = 0; i < expCant; i++){
		promNaive = 0.0;
		promBbsm = 0.0;
		promBbse = 0.0;
		promSkx = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> bbsm >> bbse >> skx;
			promNaive += naive;
			promBbsm += bbsm;
			promBbse += bbse;
			promSkx += skx;
		}
		
		promNaive /= N;
		promBbsm /= N;
		promBbse /= N;
		promSkx /= N;
		
		out << cantPunt[i] << "\t" << promNaive << "\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_skyline_dens_mix.txt");
	for(int i = 0; i < expDens; i++){
		promNaive = 0.0;
		promBbsm = 0.0;
		promBbse = 0.0;
		promSkx = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> bbsm >> bbse >> skx;
			promNaive += naive;
			promBbsm += bbsm;
			promBbse += bbse;
			promSkx += skx;
		}
		
		promNaive /= N;
		promBbsm /= N;
		promBbse /= N;
		promSkx /= N;
		
		out << dens[i] << "\t" << promNaive << "\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	in.close();
	
	return 0;
}