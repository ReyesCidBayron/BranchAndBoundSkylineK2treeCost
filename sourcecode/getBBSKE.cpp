#include <iostream>
#include <chrono>
#include <numeric>

#include "libs/BBSK.hpp"

using namespace std;
using namespace chrono;

int main(int argc, char * argv[]){
	if(argc != 3){
		cerr << argv[0] << " <PATH> <CYCLES> " << endl;
		return -1;
	}
	int cycles = atoi(argv[2]);
	try{
		cout << "Programa ejecutado: " << argv[0] << ", kTree: " << argv[1] << ", Ciclo(s): " << argv[2] << endl;
		// int cycles = 100;
		// Carga la representación según la ruta del archivo proporcionada
		MREP * kt = loadRepresentation(argv[1]);
		// Crea una instancia del objeto BBSK
		BBSK bbsk;
		// Crea un vector donde almacenar los puntos Skyline
		vector<pair<int, int>> * skyline;
		// Crea las variables para el calculo del tiempo de ejecucion
		auto start = high_resolution_clock::now();
		auto finish = high_resolution_clock::now();
		long ejecutionTime;
		vector<long> times(cycles);
		for(int i = 0; i < cycles; i++){
			// Inicia el conteo de tiempo
			start = high_resolution_clock::now();
			// Llama a la función skylineEuclidean y la almacena en skyline
			skyline = bbsk.skylineEuclidean(kt);
			// Finaliza el conteo de tiempo 
			finish = high_resolution_clock::now();
			// Calcula el tiempo de ejecucion
			ejecutionTime = duration_cast<microseconds> (finish - start).count();
			// Lo almacena en el vector de tiempos de ejecucion
			times[i] = ejecutionTime;
		}
		// Calcula el tiempo minimo y maximo de ejecucion, junto con el tiempo promedio de los ciclos
		auto minTime = min_element(times.begin(), times.end());
		auto maxTime = max_element(times.begin(), times.end());
		long aveTime = static_cast<long>(accumulate(times.begin(), times.end(), 0)) / cycles;
		// Imprime por pantalla la cantidad de puntos skyline obtenidos
		cout << "Cantidad de puntos Skyline (S): " << skyline->size() << endl;
		// Imprime por pantalla las coordenadas de los puntos skyline
		cout << "Puntos Skyline (x,y):" << endl;
		for(int i = 0; i < skyline->size(); i++){
			cout << "\t(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;
		}
		// Imprime por pantalla los tiempo de ejecucion
		cout << "Tiempo de ejecucion minimo: " << *minTime << " microsegundos" << endl; 
		cout << "Tiempo de ejecucion maximo: " << *maxTime << " microsegundos" << endl; 
		cout << "Tiempo de ejecucion promedio para " << cycles << " ciclo(s): " << aveTime << " microsegundos" << endl; 
		// Libera memoria
		delete skyline;
    	delete kt;
		// Finaliza la ejecucion del programa
		cout << "Programa ejecutado con exito" << endl;
		return 0;
	}catch(const exception& e){
		cerr << "Error en la ejecucion del programa" << endl;
		return -1;
	}
}