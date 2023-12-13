#include <iostream>
#include <fstream>
#include <cmath>
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
	
	int ktree, range, compact;
	float promRange, promCompact;
	
	float cantPunt[] = {0.1, 0.5, 1, 5, 10, 50};
	int expCant = 6;
	float dens[] = {1, 5, 10};
	int expDens = 3;
	int tamMatr[] = {(int)pow(2, 13), (int)pow(2, 14), (int)pow(2, 15), (int)pow(2, 16)};
	int expMatr = 4;
	float tamRang[] = {0.01, 0.1, 1, 10, 25, 50, 99, 100};
	int expRang = 8;
	
	printf("DATOS UNIFORMES\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_count_cant_uni.txt");
	for(int i = 0; i < expCant; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << cantPunt[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_count_dens_uni.txt");
	for(int i = 0; i < expDens; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << dens[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DE LA MATRIZ\n");
	out.open("data_count_matr_uni.txt");
	for(int i = 0; i < expMatr; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << tamMatr[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DEL RANGO\n");
	out.open("data_count_rang_uni.txt");
	for(int i = 0; i < expRang; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << tamRang[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DATOS CLUSTERIZADOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_count_cant_clu.txt");
	for(int i = 0; i < expCant; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << cantPunt[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_count_dens_clu.txt");
	for(int i = 0; i < expDens; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << dens[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DE LA MATRIZ\n");
	out.open("data_count_matr_clu.txt");
	for(int i = 0; i < expMatr; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << tamMatr[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DEL RANGO\n");
	out.open("data_count_rang_clu.txt");
	for(int i = 0; i < expRang; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << tamRang[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DATOS MIXTOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_count_cant_mix.txt");
	for(int i = 0; i < expCant; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << cantPunt[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_count_dens_mix.txt");
	for(int i = 0; i < expDens; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << dens[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DE LA MATRIZ\n");
	out.open("data_count_matr_mix.txt");
	for(int i = 0; i < expMatr; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << tamMatr[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DEL RANGO\n");
	out.open("data_count_rang_mix.txt");
	for(int i = 0; i < expRang; i++){
		
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promCompact /= N;
		
		
		out << tamRang[i] << "\t0\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	in.close();
	return 0;
}