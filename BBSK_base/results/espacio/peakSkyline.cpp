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
	
	ofstream out;
	
	int ktree, bbsm, bbse, skx;
	float promBbsm, promBbse, promSkx;
	
	float cantPunt[] = {0.1, 0.5, 1, 5, 10, 50};
	int expCant = 6;
	float dens[] = {1, 5, 10};
	int expDens = 3;
	
	printf("DATOS UNIFORMES\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_skyline_cant_uni.txt");
	for(int i = 0; i < expCant; i++){
		
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
		
		out << cantPunt[i] << "\t" << "\t0\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_skyline_dens_uni.txt");
	for(int i = 0; i < expDens; i++){
		
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
		
		out << dens[i] << "\t" << "\t0\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DATOS CLUSTERIZADOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_skyline_cant_clu.txt");
	for(int i = 0; i < expCant; i++){
		
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
		
		out << cantPunt[i] << "\t" << "\t0\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_skyline_dens_clu.txt");
	for(int i = 0; i < expDens; i++){
		
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
		
		out << dens[i] << "\t" << "\t0\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DATOS MIXTOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_skyline_cant_mix.txt");
	for(int i = 0; i < expCant; i++){
		
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
		
		out << cantPunt[i] << "\t0\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_skyline_dens_mix.txt");
	for(int i = 0; i < expDens; i++){
		
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
		
		out << dens[i] << "\t0\t" << promBbsm << "\t" << promBbse << "\t" << promSkx << endl;
		
	}
	out.close();
	in.close();
	
	return 0;
}