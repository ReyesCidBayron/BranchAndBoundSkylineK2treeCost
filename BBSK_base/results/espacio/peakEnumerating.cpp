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
	
	int ktree, range, rangeCompact, compact;
	float promRange, promRangeCompact, promCompact;
	
	float cantPunt[] = {0.1, 0.5, 1, 5, 10, 50};
	int expCant = 6;
	float dens[] = {1, 5, 10};
	int expDens = 3;
	
	printf("DATOS UNIFORMES\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_enumerating_cant_uni.txt");
	for(int i = 0; i < expCant; i++){
		
		promRange = 0.0;
		promRangeCompact = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> rangeCompact >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promRangeCompact += (rangeCompact-ktree) > 0 ? (rangeCompact-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promRangeCompact /= N;
		promCompact /= N;
		
		
		out << cantPunt[i] << "\t0\t" << promRange << "\t" << promRangeCompact << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_enumerating_dens_uni.txt");
	for(int i = 0; i < expDens; i++){
		
		promRange = 0.0;
		promRangeCompact = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> rangeCompact >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promRangeCompact += (rangeCompact-ktree) > 0 ? (rangeCompact-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promRangeCompact /= N;
		promCompact /= N;
		
		
		out << dens[i] << "\t0\t" << promRange << "\t" << promRangeCompact << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DATOS CLUSTERIZADOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_enumerating_cant_clu.txt");
	for(int i = 0; i < expCant; i++){
		
		promRange = 0.0;
		promRangeCompact = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> rangeCompact >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promRangeCompact += (rangeCompact-ktree) > 0 ? (rangeCompact-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promRangeCompact /= N;
		promCompact /= N;
		
		
		out << cantPunt[i] << "\t0\t" << promRange << "\t" << promRangeCompact << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_enumerating_dens_clu.txt");
	for(int i = 0; i < expDens; i++){
		
		promRange = 0.0;
		promRangeCompact = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> rangeCompact >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promRangeCompact += (rangeCompact-ktree) > 0 ? (rangeCompact-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promRangeCompact /= N;
		promCompact /= N;
		
		
		out << dens[i] << "\t0\t" << promRange << "\t" << promRangeCompact << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DATOS MIXTOS\n");
	printf("CANTIDAD DE PUNTOS\n");
	out.open("data_enumerating_cant_mix.txt");
	for(int i = 0; i < expCant; i++){
		
		promRange = 0.0;
		promRangeCompact = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> rangeCompact >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promRangeCompact += (rangeCompact-ktree) > 0 ? (rangeCompact-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promRangeCompact /= N;
		promCompact /= N;
		
		
		out << cantPunt[i] << "\t0\t" << promRange << "\t" << promRangeCompact << "\t" << promCompact << endl;
		
	}
	out.close();
	
	printf("DENSIDAD\n");
	out.open("data_enumerating_dens_mix.txt");
	for(int i = 0; i < expDens; i++){
		
		promRange = 0.0;
		promRangeCompact = 0.0;
		promCompact = 0.0;
		for(int j = 0; j < N; j++){
			in >> range >> rangeCompact >> compact >> ktree;
			
			promRange += (range-ktree) > 0 ? (range-ktree) : 0;
			promRangeCompact += (rangeCompact-ktree) > 0 ? (rangeCompact-ktree) : 0;
			promCompact += (compact-ktree) > 0 ? (compact-ktree) : 0;
		}
		
		
		promRange /= N;
		promRangeCompact /= N;
		promCompact /= N;
		
		
		out << dens[i] << "\t0\t" << promRange << "\t" << promRangeCompact << "\t" << promCompact << endl;
		
	}
	out.close();
	in.close();
	
	return 0;
}