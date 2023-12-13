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
	
	int ktree, range, rangeCompact, compact;
	float promRange, promRangeCompact, promCompact;
	
	out.open("peak_enumerating.txt");
	
	for(int i = 0; i < 12; i++){
		if(i != 9){
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

			out << i << "\t" << "\t" << promRange << "\t" << promRangeCompact << "\t" << promCompact << endl;
		}
	}
	
	out.close();
	
	in.close();
	
	return 0;
}