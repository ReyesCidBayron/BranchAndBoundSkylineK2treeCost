#include "BBSKC_DEV.hpp"
#include <iostream>

// Define a Alpha y Beta como variables globales
float Alpha;
float Beta;

// Función de comparación para el montículo (heap) en funcion a la distancia de Manhattan
bool cmpM(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return a.first.first + a.first.second > b.first.first + b.first.second;
}

// Función de comparación para el montículo (heap) en funcion a la distancia Euclidiana
bool cmpE(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return pow(a.first.first,2)+pow(a.first.second,2) > pow(b.first.first,2)+pow(b.first.second,2);
}

// Función de comparación para el montículo (heap) en relacion a la Funcion de Costos Manhattan
bool cmpCM(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	// Funcion de costos para el NODO a(x,y) y b(x,y)
	double aCostAlpha = (((1 - (Alpha))*(a.first.first)) + ((Alpha)*(a.first.second)));
	double aCostBeta = (((Beta)*(a.first.first)) + ((1 - (Beta))*(a.first.second)));
	double bCostAlpha = (((1 - (Alpha))*(b.first.first)) + ((Alpha)*(b.first.second)));
	double bCostBeta = (((Beta)*(b.first.first)) + ((1 - (Beta))*(b.first.second)));
	bool retorno = (aCostAlpha + aCostBeta) > (bCostAlpha + bCostBeta);
	cout << "Funcion cmpCM{" << endl;
	if(retorno == 1) cout << "\tC(p1(" << a.first.first << ", " << a.first.second << ")) = (" << aCostAlpha << ", " << aCostBeta << "), es mayor que C(p2(" << b.first.first << ", " << b.first.second << ")) = (" << bCostAlpha << ", " << bCostBeta << ")\n\t}" << endl;
	else cout << "\tC(p1(" << a.first.first << ", " << a.first.second << ")) = (" << aCostAlpha << ", " << aCostBeta << "), es menor que C(p2(" << b.first.first << ", " << b.first.second << ")) = (" << bCostAlpha << ", " << bCostBeta << ")\n\t}" << endl;
	return (aCostAlpha + aCostBeta) > (bCostAlpha + bCostBeta);
}

// Función de comparación para el montículo (heap) en relacion a la Funcion de Costos Euclidean
bool cmpCE(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	// Funcion de costos para el NODO a(x,y) y b(x,y)
	double aCostAlpha = (((1 - (Alpha))*(a.first.first)) + ((Alpha)*(a.first.second)));
	double aCostBeta = (((Beta)*(a.first.first)) + ((1 - (Beta))*(a.first.second)));
	double bCostAlpha = (((1 - (Alpha))*(b.first.first)) + ((Alpha)*(b.first.second)));
	double bCostBeta = (((Beta)*(b.first.first)) + ((1 - (Beta))*(b.first.second)));
	bool retorno = (pow(aCostAlpha, 2) + pow(aCostBeta, 2)) >= (pow(bCostAlpha, 2) + pow(bCostBeta, 2));
	cout << "Funcion cmpCE{" << endl;
	if(retorno == true) cout << "\tC(p1(" << a.first.first << ", " << a.first.second << ")) = (" << aCostAlpha << ", " << aCostBeta << "), es mayor que C(p2(" << b.first.first << ", " << b.first.second << ")) = (" << bCostAlpha << ", " << bCostBeta << ")\n\t}" << endl;
	else cout << "\tC(p1(" << a.first.first << ", " << a.first.second << ")) = (" << aCostAlpha << ", " << aCostBeta << "), es menor que C(p2(" << b.first.first << ", " << b.first.second << ")) = (" << bCostAlpha << ", " << bCostBeta << ")\n\t}" << endl;
	return (pow(aCostAlpha, 2) + pow(aCostBeta, 2)) >= (pow(bCostAlpha, 2) + pow(bCostBeta, 2));
}

// Función principal para calcular el skyline utilizando BBSK la Funcion de costos euclideana
// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * BBSKC_DEV::skylineCostEuclidean2(MREP * rep, float alpha, float beta){
	// Le da valores a las variables globales
	Alpha = alpha;
	Beta = beta;
    cout << "-\nINICIO DE LA FUNCION, ALPHA: " << alpha << " y BETA: " << beta << endl;
	// Crea dinámicamente un nuevo vector en el heap para almacenar el skyline
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	// Este vector se utiliza para almacenar nodos en el proceso de búsqueda del algoritmo
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	// Inicializa un montículo (heap) con un nodo que representa toda la matriz de búsqueda
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	// Configura el vector heap para que sea un montículo
	make_heap(heap.begin(), heap.end(), cmpCE);
	// Crea una variable r que representa un nodo o punto en el espacio
	pair<pair<int, int>, pair<int, int>> r = make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, rep->numberOfNodes));
	// Declara dos variables del tipo pair<pair<int, int>, pair<int, int>>
	pair<pair<int,int>, pair<int, int>> n, n_i;
	// Declara cuatro variables de tipo boolean
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned, isSkyline;
	// Declara cuatro variables de tipo integer
	int firstChild, minX, minY, nChild, iChild, contadorDeCiclo = 0;
	// Declara cuatro variables de tipo double
	double aCostAlpha, aCostBeta, bCostAlpha, bCostBeta;
	// Bucle principal hasta que el montículo esté vacío
	while(heap.size() != 0){
		contadorDeCiclo++;
		// Extrae el nodo con la menor suma de coordenadas del montículo
		n = heap.front();
		cout << "-\nCICLO: " << contadorDeCiclo << endl;
		cout << "\tMuestra el HEAP, elementos en el HEAP: " << heap.size() << endl;
		for(const auto& heap : heap){
			cout << "\t\tNODO N(" << heap.first.first << ", " << heap.first.second << ")(nChild(" << heap.second.first << "), iChild(" << heap.second.second << "))" << endl;
		}
		cout << "\tExtrae el NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) desde el HEAP, HEAP actual: " << heap.size() - 1 << endl;
		// Reorganiza el rango [heap.begin(), heap.end()) con el criterio comparativo cmpCE
		pop_heap(heap.begin(), heap.end(), cmpCE);
		// Elimina el último elemento del vector heap
    	heap.pop_back();
		// Verifica si el nodo está dominado por el skyline actual
		cout << "\t\tVerifica si el NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) esta dominado por el SKYLINE actual: " << skyline->size() << endl;
		// Funcion de costos para el NODO N(x,y)
		aCostAlpha = (((1 - (alpha))*(n.first.first)) + ((alpha)*(n.first.second)));
		aCostBeta = (((beta)*(n.first.first)) + ((1 - (beta))*(n.first.second)));
		// Asigna a la variable isDominatedBySkyline el valor false
		isDominatedBySkyline = false;
		// Calcula el costo del NODO N(x,y) en relacion a la Funcion de Costos y los angulos alpha y beta
		cout << "\t\t\tCalcula el costo del NODO N("<< n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ") en relacion a alpha: " << alpha << " y beta: " << beta << endl;
		cout << "\t\t\t\tC(N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) = (" << aCostAlpha << ", " << aCostBeta << ")" << endl;
		for(int i = 0; i < skyline->size(); i++){
			cout << "\t\t\tCompara el NODO N(" <<  n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) con SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion a la Funcion de Costos"  << endl;
			// Calcula el costo del SKYLINE S(x,y)
			bCostAlpha =  (((1 - (alpha))*((*skyline)[i].first)) + ((alpha)*((*skyline)[i].second)));
			bCostBeta = (((beta)*((*skyline)[i].first)) + ((1 - (beta))*((*skyline)[i].second)));
			cout << "\t\t\t\tCalcula el costo del SKYLINE S("<< (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion a alpha: " << alpha << " y beta: " << beta << endl;
			cout << "\t\t\t\t\tC(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")) = (" << bCostAlpha << ", " << bCostBeta << ")" << endl;
			// Funcion de comparacion de Costes
			if((aCostAlpha >= bCostAlpha && aCostBeta >= bCostBeta) && (aCostAlpha > bCostAlpha || aCostBeta > bCostBeta)){
				cout << "\t\t\t\t\tC(N(" << n.first.first << ", " << n.first.second << ")) = (" << aCostAlpha << ", " << aCostBeta << "), SI es dominado por C(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") = (" << bCostAlpha << ", " << bCostBeta << ")" << endl; 
				isDominatedBySkyline = true;
				break;
			}else{
				cout << "\t\t\t\t\tC(N(" << n.first.first << ", " << n.first.second << ")) = (" << aCostAlpha << ", " << aCostBeta << "), NO es dominado por C(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") = (" << bCostAlpha << ", " << bCostBeta << ")" << endl; 
			}
		}
		// Asigna a la variable isSkyline el valor false
		isSkyline = false;
		// Verifica si el NODO N es una HOJA
		if(!isDominatedBySkyline && !isSkyline && n.second.second != -1){
			cout << "\t\t\tComo el NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) no es dominado por el SKYLINE, verifica si es una HOJA" << endl;
			isALeaf = n.second.second >= rep->bt_len;
			/*
			if(n.second.second != -1){
				isALeaf = n.second.second >= rep->bt_len;
				// cout << "\t\t\t\tisALeaf: " << isALeaf <<  ", iChild: " << n.second.second << endl;
			}
			*/
			// Si es una hoja, agrega el hijo al conjunto Skyline
			if(isALeaf){
				// Si es una hoja, agrega al skyline
				isSkyline = true;
				skyline->push_back(n.first);
				cout << "\t\t\t\tNODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) SI es una HOJA, por lo tanto lo agrega al SKYLINE" << endl;
				cout << "\t\t\t\t***Agrega el NODO HOJA NH(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) al SKYLINE***" << endl;
			}
			else{
				cout << "\t\t\t\tNODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) NO es una HOJA" << endl;
			}
		}
		// Si el nodo no está dominado por el skyline actual
		if(!isDominatedBySkyline && !isSkyline){
			// Calcula el índice del primer hijo en la representación de bits
			firstChild = 0;
			if(n.second.second != -1){
				firstChild = rank1(rep->btl, n.second.second) * pow(K, 2);
			}
			// Itera los hijos del NODO N(x,y)
			cout << "\tItera los HIJOS del NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << "))" << endl;
			// Itera sobre los hijos potenciales
			for(uint i = 0; i < pow(K, 2); i++){
				// Verifica si la submatriz correspondiente al hijo está vacía
				subMatrixEmpty = !isBitSet(rep->btl, firstChild + i);
				isPruned = false;
				// Verifica si la submatriz está podada, en resumen, descarta al segundo nodo o punto
				for(ushort j = 0; j < (i / K); j++){
					for(ushort l = 0; l < (i % K); l++){
						isPruned = isPruned || isBitSet(rep->btl, firstChild + l);
					}
				}
				// Si la submatriz no está vacía y no está podada
				if(!subMatrixEmpty && !isPruned){
					// Calcula las coordenadas de la esquina inferior izquierda del hijo
					minX = n.first.first + (n.second.first / K) * (i % K);
    				minY = n.first.second + (n.second.first / K) * ceil( i / K);
					nChild = n.second.first / K;
					iChild = firstChild + i;
					// Asigna a la variable isDominatedBySkyline el valor false
					isDominatedBySkyline = false;
					// Verifica si el hijo está dominado por el skyline actual
					cout << "\t\tVerifica si el HIJO H(" << minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ")) esta dominado por el skyline actual: " << skyline->size() << endl;
					// Funcion de costos para el HIJO H(x,y)
					aCostAlpha = (((1 - (alpha))*(minX)) + ((alpha)*(minY)));
					aCostBeta = (((beta)*(minX)) + ((1 - (beta))*(minY)));
					// Calcula el costo del HIJO H(x,y) en relacion a la Funcion de Costos y los angulos alpha y beta
					cout << "\t\t\tCalcula el costo del HIJO H("<< minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ") en relacion a alpha: " << alpha << " y beta: " << beta << endl;
					cout << "\t\t\t\tC(H(" << minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ")) = (" << aCostAlpha << ", " << aCostBeta << ")" << endl;
					for(int i = 0; i < skyline->size(); i++){
						cout << "\t\t\tCompara el HIJO H(" <<  minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ")) con SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")"  << endl;
						// Calcula el costo del SKYLINE S(x,y)
						bCostAlpha = (((1 - (alpha))*((*skyline)[i].first)) + ((alpha)*((*skyline)[i].second)));
						bCostBeta = (((beta)*((*skyline)[i].first)) + ((1 - (beta))*((*skyline)[i].second)));
						cout << "\t\t\t\tCalcula el costo del SKYLINE S("<< (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion a alpha: " << alpha << " y beta: " << beta << endl;
						cout << "\t\t\t\t\tC(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")) = (" << bCostAlpha << ", " << bCostBeta << ")" << endl;
						// Funcion de comparacion de Costes
						if((aCostAlpha >= bCostAlpha && aCostBeta >= bCostBeta) && (aCostAlpha > bCostAlpha || aCostBeta > bCostBeta)){
							cout << "\t\t\t\t\tC(H(" << minX << ", " << minY << ")) = (" << aCostAlpha << ", " << aCostBeta << "), SI es dominado por C(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") = (" << bCostAlpha << ", " << bCostBeta << ")" << endl; 
							isDominatedBySkyline = true;
							break;
						}else{
							cout << "\t\t\t\t\tC(H(" << minX << ", " << minY << ")) = (" << aCostAlpha << ", " << aCostBeta << "), NO es dominado por C(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") = (" << bCostAlpha << ", " << bCostBeta << ")" << endl; 
						}
					}
					// Si el hijo no está dominado por el skyline actual lo agrega al heap
					if(!isDominatedBySkyline){
						// Crea el objeto para añadir al heap
						n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
						// Lo agrega al final del heap
						heap.push_back(n_i);
						// Reorganiza el heap
      					push_heap(heap.begin(), heap.end(), cmpCE);
						cout << "\t\t\tComo el HIJO H(" << n_i.first.first << ", " << n_i.first.second << ")(nChild(" << n_i.second.first << "), iChild(" << n_i.second.second << ")) no es dominado por el SKYLINE lo agrega al HEAP" << endl;
						cout << "\t\t\t\t***Agrega el HIJO H(" << n_i.first.first << ", " << n_i.first.second << ")(nChild(" << n_i.second.first << "), iChild(" << n_i.second.second << ")) al HEAP***" << endl;
					}
				}
			}
		}
		cout << "\tMuestra el HEAP, elementos en el HEAP: " << heap.size() << endl;
		for(const auto& heap : heap){
			cout << "\t\tHEAP HP(" << heap.first.first << ", " << heap.first.second << "), nChild(" << heap.second.first << "), iChild(" << heap.second.second << ")" << endl;
		}
	}
	// Devuelve el skyline encontrado
	return skyline;
}

// Función principal para calcular el skyline utilizando BBSK la Funcion de costos euclideana con descarte prematuro
// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * BBSKC_DEV::skylineCostEuclidean1(MREP * rep, float alpha, float beta){
	// Le da valores a las variables globales
	Alpha = alpha;
	Beta = beta;
    cout << "-\nINICIO DE LA FUNCION, ALPHA: " << alpha << " y BETA: " << beta << endl;
	// Crea dinámicamente un nuevo vector en el heap para almacenar el skyline
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	// Este vector se utiliza para almacenar nodos en el proceso de búsqueda del algoritmo
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	// Inicializa un montículo (heap) con un nodo que representa toda la matriz de búsqueda
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	// Configura el vector heap para que sea un montículo
	make_heap(heap.begin(), heap.end(), cmpCE);
	// Crea una variable r que representa un nodo o punto en el espacio
	pair<pair<int, int>, pair<int, int>> r = make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, rep->numberOfNodes));
	// Declara dos variables del tipo pair<pair<int, int>, pair<int, int>>
	pair<pair<int,int>, pair<int, int>> n, n_i;
	// Declara cuatro variables de tipo boolean
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned;
	// Declara cuatro variables de tipo integer
	int firstChild, minX, minY, nChild, iChild;
	// Declara cuatro variables de tipo double
	double aCostAlpha, aCostBeta, bCostAlpha, bCostBeta, contadorDeCiclo = 0;
	// Bucle principal hasta que el montículo esté vacío
	while(heap.size() != 0){
		contadorDeCiclo++;
		// Extrae el nodo con la menor suma de coordenadas del montículo
		n = heap.front();
		cout << "-\nCICLO: " << contadorDeCiclo << endl;
		cout << "\tMuestra el HEAP, elementos en el HEAP: " << heap.size() << endl;
		for(const auto& heap : heap){
			cout << "\t\tNODO N(" << heap.first.first << ", " << heap.first.second << ")(nChild(" << heap.second.first << "), iChild(" << heap.second.second << "))" << endl;
		}
		cout << "\tExtrae el NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) desde el HEAP, HEAP actual: " << heap.size() - 1 << endl;
		// Reorganiza el rango [heap.begin(), heap.end()) con el criterio comparativo cmpCE
		pop_heap(heap.begin(), heap.end(), cmpCE);
		// Elimina el último elemento del vector heap
    	heap.pop_back();
		// Asigna a la variable isDominatedBySkyline el valor false
		isDominatedBySkyline = false;
		// Verifica si el nodo está dominado por el skyline actual
		cout << "\t\tVerifica si el NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) esta dominado por el SKYLINE actual: " << skyline->size() << endl;
		// Funcion de costos para el NODO N(x,y)
		aCostAlpha = (((1 - (alpha))*(n.first.first)) + ((alpha)*(n.first.second)));
		aCostBeta =  (((beta)*(n.first.first)) + ((1 - (beta))*(n.first.second)));
		// Calcula el costo del NODO N(x,y) en relacion a la Funcion de Costos y los angulos alpha y beta
		cout << "\t\t\tCalcula el costo del NODO N("<< n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ") en relacion a alpha: " << alpha << " y beta: " << beta << endl;
		cout << "\t\t\t\tC(N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) = (" << aCostAlpha << ", " << aCostBeta << ")" << endl;
		for(int i = 0; i < skyline->size(); i++){
			cout << "\t\t\tCompara el NODO N(" <<  n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) con SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion a la Funcion de Costos"  << endl;
			// Calcula el costo del SKYLINE S(x,y)
			bCostAlpha = (((1 - (alpha))*((*skyline)[i].first)) + ((alpha)*((*skyline)[i].second)));
			bCostBeta = (((beta)*(n.first.first)) + ((1 - (beta))*(n.first.second)));
			cout << "\t\t\t\tCalcula el costo del SKYLINE S("<< (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion a alpha: " << alpha << " y beta: " << beta << endl;
			cout << "\t\t\t\t\tC(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")) = (" << bCostAlpha << ", " << bCostBeta << ")" << endl;
			// Funcion de comparacion de Costes
			if((aCostAlpha >= bCostAlpha && aCostBeta >= bCostBeta) && (aCostAlpha > bCostAlpha || aCostBeta > bCostBeta)){
				cout << "\t\t\t\t\tC(N(" << n.first.first << ", " << n.first.second << ")) = (" << aCostAlpha << ", " << aCostBeta << "), SI es dominado por C(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") = (" << bCostAlpha << ", " << bCostBeta << ")" << endl; 
				isDominatedBySkyline = true;
				break;
			}else{
				cout << "\t\t\t\t\tC(N(" << n.first.first << ", " << n.first.second << ")) = (" << aCostAlpha << ", " << aCostBeta << "), NO es dominado por C(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") = (" << bCostAlpha << ", " << bCostBeta << ")" << endl; 
			}
		}
		// Si el nodo no está dominado por el skyline actual
		if(!isDominatedBySkyline){
			// Calcula el índice del primer hijo en la representación de bits
			firstChild = 0;
			if(n.second.second != -1){
				firstChild = rank1(rep->btl, n.second.second) * pow(K, 2);
			}
			// Itera los hijos del NODO N(x,y)
			cout << "\tItera los HIJOS del NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << "))" << endl;
			// Itera sobre los hijos potenciales
			for(uint i = 0; i < pow(K, 2); i++){
				// Verifica si la submatriz correspondiente al hijo está vacía
				subMatrixEmpty = !isBitSet(rep->btl, firstChild + i);
				isPruned = false;
				// Verifica si la submatriz está podada, en resumen, descarta al segundo nodo o punto
				for(ushort j = 0; j < (i / K); j++){
					for(ushort l = 0; l < (i % K); l++){
						isPruned = isPruned || isBitSet(rep->btl, firstChild + l);
					}
				}
				// Si la submatriz no está vacía y no está podada
				if(!subMatrixEmpty && !isPruned){
					// Calcula las coordenadas de la esquina inferior izquierda del hijo
					minX = n.first.first + (n.second.first / K) * (i % K);
    				minY = n.first.second + (n.second.first / K) * ceil( i / K);
					nChild = n.second.first / K;
					iChild = firstChild + i;
					// Asigna a la variable isDominatedBySkyline el valor false
					isDominatedBySkyline = false;
					// Verifica si el hijo está dominado por el skyline actual
					cout << "\t\tVerifica si el HIJO H(" << minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ")) esta dominado por el skyline actual: " << skyline->size() << endl;
					// Funcion de costos para el HIJO H(x,y)
					aCostAlpha = (((1 - (alpha))*(minX)) + ((alpha)*(minY)));
					aCostBeta = (((beta)*(minX)) + ((1 - (beta))*(minY)));
					// Calcula el costo del HIJO H(x,y) en relacion a la Funcion de Costos y los angulos alpha y beta
					cout << "\t\t\tCalcula el costo del HIJO H("<< minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ") en relacion a alpha: " << alpha << " y beta: " << beta << endl;
					cout << "\t\t\t\tC(H(" << minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ")) = (" << aCostAlpha << ", " << aCostBeta << ")" << endl;
					for(int i = 0; i < skyline->size(); i++){
						cout << "\t\t\tCompara el HIJO H(" <<  minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ")) con SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")"  << endl;
						// Calcula el costo del SKYLINE S(x,y)
						bCostAlpha = (((1 - (alpha))*((*skyline)[i].first)) + ((alpha)*((*skyline)[i].second)));
						bCostBeta = (((beta)*((*skyline)[i].first)) + ((1 - (beta))*((*skyline)[i].second)));
						cout << "\t\t\t\tCalcula el costo del SKYLINE S("<< (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion a alpha: " << alpha << " y beta: " << beta << endl;
						cout << "\t\t\t\t\tC(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")) = (" << bCostAlpha << ", " << bCostBeta << ")" << endl;
						// Funcion de comparacion de Costes
						if((aCostAlpha >= bCostAlpha && aCostBeta >= bCostBeta) && (aCostAlpha > bCostAlpha || aCostBeta > bCostBeta)){
							cout << "\t\t\t\t\tC(H(" << minX << ", " << minY << ")) = (" << aCostAlpha << ", " << aCostBeta << "), SI es dominado por C(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") = (" << bCostAlpha << ", " << bCostBeta << ")" << endl; 
							isDominatedBySkyline = true;
							break;
						}else{
							cout << "\t\t\t\t\tC(H(" << minX << ", " << minY << ")) = (" << aCostAlpha << ", " << aCostBeta << "), NO es dominado por C(S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") = (" << bCostAlpha << ", " << bCostBeta << ")" << endl; 
						}
					}
					// Si el hijo no está dominado por el skyline actual
					if(!isDominatedBySkyline){
						// Verifica si el hijo es una hoja
						cout << "\t\t\tVerifica si el HIJO H(" << minX << ", " << minY << ")(nChild(" << nChild << "), iChild(" << iChild << ")) es una NODO o una HOJA" << endl;
						isALeaf = false;
						if(firstChild + i != -1){
							isALeaf = firstChild + i >= rep->bt_len;
							cout << "\t\t\t\tisALeaf: " << isALeaf <<  ", firstChild + i: " << firstChild + i << endl;
						}
						n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
						// Si no es una hoja, agrega el hijo al montículo
						if(!isALeaf){
							heap.push_back(n_i);
      						push_heap(heap.begin(), heap.end(), cmpCE);
							cout << "\t\t\t\t***Agrega el HIJO H(" << n_i.first.first << ", " << n_i.first.second << ")(nChild(" << n_i.second.first << "), iChild(" << n_i.second.second << ")) al HEAP***" << endl;

						}else{
							// Si es una hoja, agrega al skyline
							skyline->push_back(n_i.first);
							cout << "\t\t\t\t***Agrega el HIJO H(" << n_i.first.first << ", " << n_i.first.second << ")(nChild(" << n_i.second.first << "), iChild(" << n_i.second.second << ")) al SKYLINE***" << endl;
						}
					}
				}
			}
		}
		cout << "\tMuestra el HEAP, elementos en el HEAP: " << heap.size() << endl;
		for(const auto& heap : heap){
			cout << "\t\tHEAP HP(" << heap.first.first << ", " << heap.first.second << "), nChild(" << heap.second.first << "), iChild(" << heap.second.second << ")" << endl;
		}
	}
	// Devuelve el skyline encontrado
	return skyline;
}


