#include <iostream>
#include <fstream>
#include <cmath>
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
	
	printf("LOS TIEMPOS ESTAN EN MILISEGUNDOS\n");
	
	ofstream out;
	
	string filename;
	int naive, range, compact;
	float promNaive, promRange, promCompact;
	
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
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << cantPunt[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_count_dens_uni.txt");
	for(int i = 0; i < expDens; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << dens[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DE LA MATRIZ\n");
	out.open("data_count_matr_uni.txt");
	for(int i = 0; i < expMatr; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << tamMatr[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DEL RANGO\n");
	out.open("data_count_rang_uni.txt");
	for(int i = 0; i < expRang; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << tamRang[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DATOS CLUSTERIZADOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_count_cant_clu.txt");
	for(int i = 0; i < expCant; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << cantPunt[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_count_dens_clu.txt");
	for(int i = 0; i < expDens; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << dens[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DE LA MATRIZ\n");
	out.open("data_count_matr_clu.txt");
	for(int i = 0; i < expMatr; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << tamMatr[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DEL RANGO\n");
	out.open("data_count_rang_clu.txt");
	for(int i = 0; i < expRang; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << tamRang[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DATOS MIXTOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_count_cant_mix.txt");
	for(int i = 0; i < expCant; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << cantPunt[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_count_dens_mix.txt");
	for(int i = 0; i < expDens; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << dens[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DE LA MATRIZ\n");
	out.open("data_count_matr_mix.txt");
	for(int i = 0; i < expMatr; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << tamMatr[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("TAMAÑO DEL RANGO\n");
	out.open("data_count_rang_mix.txt");
	for(int i = 0; i < expRang; i++){
		promNaive = 0.0;
		promRange = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> filename >> naive >> range >> compact;
			promNaive += naive;
			promRange += range;
			promCompact += compact;
		}
		
		promNaive /= N;
		promRange /= N;
		promCompact /= N;
		promNaive /= 1000;
		promRange /= 1000;
		promCompact /= 1000;
		
		out << tamRang[i] << "\t" << promNaive << "\t" << promRange << "\t" << promCompact << endl;
		
	}
	out.close();
	
	in.close();
	return 0;
}