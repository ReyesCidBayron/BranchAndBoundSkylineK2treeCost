#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

// Estructura de coordenada
struct Coordenada {
    int x;
    int y;
};

// Función para generar coordenadas cartesianas aleatorias sin duplicados
vector<Coordenada> generarCoordenadas(int n, int rango) {
    vector<Coordenada> coordenadas;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, rango);
    bool duplicated;
    while (coordenadas.size() < n) {
        Coordenada coord;
        coord.x = dist(gen);
        coord.y = dist(gen);
        duplicated = false;
        for(const auto& coordenada : coordenadas){
            if(coord.x == coordenada.x && coord.y == coordenada.y){
                // cout << "Duplicado: (" << coord.x << ", " << coord.y << ") y (" << coordenada.x << ", " << coordenada.y << ")" << endl;
                duplicated = true;
                break;
            }
        }
        if(!duplicated){
            coordenadas.push_back(coord);
        }
    }
    return coordenadas;
}

// Verifica los duplicados en el vector coordenadas
void verificaDuplicados(const vector<Coordenada>& coordenadas){
    for(int i = 0; i < coordenadas.size(); i++){
        for(int j = 0; j < coordenadas.size(); j++){
            if(coordenadas[i].x == coordenadas[j].x && coordenadas[i].y == coordenadas[j].y && i != j){
                cout << "Duplicado: (" << coordenadas[i].x << ", " << coordenadas[j].y << ") y (" << coordenadas[i].x << ", " << coordenadas[j].y << ")" << endl;
            }
        }
    }
}

// Guarda las coordenadas en un archivo de texto
void guardarCoordenadas(const vector<Coordenada>& coordenadas, const string& nombreArchivo, char* n, char* rango) {
    // Abre el archivo para escritura, si ya existe, lo remplaza
    // DEBE EXISTIR EL DIRECTORIO EN EL CUAL SE ALMACENA EÑ DATASET
    string nombreArchivoTxt = nombreArchivo + "_" + n + "_" + rango + ".txt";
    ofstream archivo(nombreArchivoTxt);
    if (archivo.is_open()) {
        // Escribe cada coordenada en una línea separada
        for (int i = 0; i < coordenadas.size(); i++) {
            if(i != coordenadas.size()-1){
                archivo << coordenadas[i].x << " " << coordenadas[i].y << endl;
            }else{
                archivo << coordenadas[i].x << " " << coordenadas[i].y;
            }
        }
        // Cierra el archivo
        archivo.close();
        cout << "Coordenadas guardadas exitosamente en " << nombreArchivoTxt << endl;
    } else {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
    }
}

// Funcion principal
int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << argv[0] << " <N> <RANGE> <NAME>" << endl;
        return -1;
    }
    int n = stoi(argv[1]);
    int rango = stoi(argv[2]);
    try{
        // Crea las variables para el calculo del tiempo de ejecucion
        auto inicio = high_resolution_clock::now();
        auto fin = high_resolution_clock::now();
        long tiempoDeEjecucion;
        // Inicia el conteo de tiempo
        inicio = high_resolution_clock::now();
        // Genera las coordenadas cartecianas de forma aleatoria
        vector<Coordenada> coordenadas = generarCoordenadas(n, rango);
        // Imprimir las coordenadas generadas
        /*
        cout << "Coordenadas generadas:\n";
        for (const auto& coord : coordenadas) {
            cout << "\t(" << coord.x << ", " << coord.y << ")" << endl;
        }
        */
        // Verifica duplicados en el vector coordenadas
        // VERIFICAR DUPLICADOS ES MUY COSTOSO CON NUMEROS N O RANGO INMENSOS
        // verificaDuplicados(coordenadas);
        // Muestra por pantalla datos de la generacion de coordenadas
        cout << "Coordenadas generadas: " << coordenadas.size() << endl;
        cout << "Rango de generacion: (0, " << argv[2] << ")" << endl;
        // Llama a la función para guardar el vector de coordenadas en un archivo
        guardarCoordenadas(coordenadas, argv[3], argv[1], argv[2]);
        // Finaliza el conteo de tiempo 
        fin = high_resolution_clock::now();
        // Calcula el tiempo de ejecucion
        tiempoDeEjecucion = duration_cast<microseconds> (fin - inicio).count();
        cout << "Tiempo de ejecucion: " << tiempoDeEjecucion << " microsegundos, " << tiempoDeEjecucion / 1000000 << " segundos" << endl;
        return 0;
    }catch(const exception& e){
        cerr << "Error en la generacion de coordenadas" << endl;
        return -1;
    }
}
