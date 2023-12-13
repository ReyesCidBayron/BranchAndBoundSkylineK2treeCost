#include <iostream>
#include <chrono>
#include <numeric>

#include "libs/BBSKC_DEV.hpp"

using namespace std;
using namespace chrono;

int main(int argc, char * argv[]){
    if(argc != 5){
        cerr << argv[0] << " <PATH> <ALPHA> <BETA> <CYCLES>" << endl;
        return -1;
    }
    // Castea los argumentos de angulos alpha y beta a float y el contador de ciclos como int
    float alpha = atof(argv[2]);
    float beta = atof(argv[3]);
    int cycles = atoi(argv[4]);
    if(alpha < 0 || alpha > 90 || beta < 0 || beta > 90){
        cerr << "El valor de alpha debe estar entre 0 y 1\nPor proposito de desarrollo si ingresa un numero mayor a 1 y menor o igual a 90, lo transforma a la escala correspondiente dividiendo a alpha o beta por 90" << endl;
        return -1;
    }
    if(alpha > 1) alpha = alpha / 90;
    if(beta > 1) beta = beta / 90;
    /*
    if((alpha + beta) < 1){
        cerr << "La suma entre alpha y beta debe ser mayor o igual a 1, a + b = " << alpha + beta << endl;
        return -1;
    }
    */
    try{
        cout << "Programa ejecutado: " << argv[0] << ", kTree: " << argv[1] << ", alpha: " << argv[2] << ", beta: " << argv[3] << ", Ciclo(s): " << argv[4] << endl;
        // int cycles = 100; 
        // Carga la representación según la ruta del archivo proporcionada
        MREP * kt = loadRepresentation(argv[1]);
        // Crea una instancia del objeto BBSK
        BBSKC_DEV bbskc;
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
            // Llama a la función skylineExtendedManhattan y la almacena en skyline
            skyline = bbskc.skylineCostEuclidean2(kt, alpha, beta);
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