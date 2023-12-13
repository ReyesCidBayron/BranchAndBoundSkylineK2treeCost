#include "BBSKE_DEV.hpp"
#include <iostream>

// Función de comparación para el montículo (heap) en funcion a la distancia de Manhattan
bool cmpM(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return a.first.first + a.first.second > b.first.first + b.first.second;
}

// Función de comparación para el montículo (heap) en funcion a la distancia Euclidiana
bool cmpE(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return pow(a.first.first,2)+pow(a.first.second,2) > pow(b.first.first,2)+pow(b.first.second,2);
}

// Función principal para calcular el skyline utilizando BBSK con distancia de Manhattan
// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * BBSKE_DEV::skylineExtendedEuclidean(MREP * rep, float alpha, float beta){
    cout << "INICIO, ALPHA: " << alpha << " y BETA: " << beta << endl;
	// Crea dinámicamente un nuevo vector en el heap para almacenar el skyline
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	// Este vector se utiliza para almacenar nodos en el proceso de búsqueda del algoritmo
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	// Inicializa un montículo (heap) con un nodo que representa toda la matriz de búsqueda
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	// Configura el vector heap para que sea un montículo
	make_heap(heap.begin(), heap.end(), cmpE);
	// Crea una variable r que representa un nodo o punto en el espacio
	pair<pair<int, int>, pair<int, int>> r = make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, rep->numberOfNodes));
	// Declara dos variables del tipo pair<pair<int, int>, pair<int, int>>
	pair<pair<int,int>, pair<int, int>> n, n_i;
	// Declara cuatro variables de tipo boolean
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned;
	// Declara cuatro variables de tipo integer
	int firstChild, minX, minY, nChild, iChild, contadorDeCiclo = 0;
	// Bucle principal hasta que el montículo esté vacío
	while(heap.size() != 0){
		contadorDeCiclo++;
		// Extrae el nodo con la menor suma de coordenadas del montículo
		n = heap.front();
		cout << "-\nCICLO: " << contadorDeCiclo << endl;
		cout << "\tHEAP actual: " << heap.size() << endl;
		for(const auto& heap : heap){
			cout << "\t\tNODO N(" << heap.first.first << ", " << heap.first.second << ")(nChild(" << heap.second.first << "), iChild(" << heap.second.second << "))" << endl;
		}
		cout << "\tExtrae el NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) desde el HEAP, HEAP actual: " << heap.size() - 1 << endl;
		// Reorganiza el rango [heap.begin(), heap.end()) con el criterio comparativo cmpE
		pop_heap(heap.begin(), heap.end(), cmpE);
		// Elimina el último elemento del vector heap
    	heap.pop_back();
		// Asigna a la variable isDominatedBySkyline el valor false
		isDominatedBySkyline = false;
		// Verifica si el nodo está dominado por el skyline actual
		cout << "\tVerifica si el NODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) esta dominado por el SKYLINE actual: " << skyline->size() << endl;
		for(int i = 0; i < skyline->size(); i++){
			cout << "\t\tCompara el NODO N(" <<  n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) con SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")"  << endl;
 			// Verifica si el nodo o punto se encuentra en una de las tres regiones de dominancia
			if(((*skyline)[i].first <= n.first.first) && ((*skyline)[i].second <= n.first.second)
			   	&& (((*skyline)[i].first < n.first.first) || ((*skyline)[i].second < n.first.second))){
				// El nodo o punto se encuentra en la region dominada
				cout << "\t\t\tNODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) se encuentra en la region dominada superior derecha de SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;
				isDominatedBySkyline = true;
				break;
			}
			if(((*skyline)[i].first >= n.first.first && (*skyline)[i].second <= n.first.second)
				&& (((*skyline)[i].first > n.first.first) || ((*skyline)[i].second < n.first.second))){
				cout << "\t\t\tNODO N(" << n.first.first << ", " << n.first.second << ")(nChild(" << n.second.first << "), iChild(" << n.second.second << ")) se encuentra en la region de dominancia superior izquierda de SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;
				// El nodo o punto se encuentra en la region de dominancia superior izquierda
				if(alpha > 0 && alpha < 90){
					// Si alpha esta dentro del rango de 0 y 90, verifica que el nodo o punto se encuentre sobre la recta
					float tanAlpha = tan((alpha + 90)*(M_PI/180)); 
	                float aux = (tanAlpha*(n.first.first - (*skyline)[i].first)) + ((*skyline)[i].second);
					cout << "\t\t\tCompara el NODO N(" <<  n.first.first << ", " << n.first.second << ") con S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con ALPHA = " << alpha  << endl;
					cout << "\t\t\t\tCuando S(x = " << n.first.first << ", y = " << aux << ") en relacion a ALPHA, el NODO esta en N(" << n.first.first << ", " << n.first.second << ")" << endl;
					if(aux <= n.first.second){
						cout << "\t\t\t\tNODO N(" << n.first.first << ", " << n.first.second << ") se encuentra en la region dominada superior izquierda de SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con ALPHA = " << alpha  << endl;
						isDominatedBySkyline = true;
						break;
					}else{
						cout << "\t\t\t\tNODO N(" << n.first.first << ", " << n.first.second << ") se encuentra fuera de la region dominada por SKYLINE S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con ALPHA = " << alpha  << endl;
					}
				}
			}
			if(((*skyline)[i].first <= n.first.first && (*skyline)[i].second >= n.first.second)
				&& (((*skyline)[i].first < n.first.first) || ((*skyline)[i].second > n.first.second))){
				cout << "\t\t\tNODO N(" << n.first.first << ", " << n.first.second << ") se encuentra en la region de dominancia inferior derecha de S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;							
				// EL nodo o punto se encuentra en la region de dominancia inferior derecha
				if(beta > 0 && beta < 90){
					// Si beta esta dentro del rango de 0 y 90, verifica que el nodo o punto se encuentre sobre la recta
					float tanBeta= tan((360 - beta)*(M_PI/180)); 
	            	float aux = (tanBeta*(n.first.first - (*skyline)[i].first)) + ((*skyline)[i].second);
					cout << "\t\t\t\tCompara el NODO N(" <<  n.first.first << ", " << n.first.second << ") con S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con BETA = " << beta  << endl;
					cout << "\t\t\t\t\tCuando S(x = " << n.first.first << ", y = " << aux << ") en relacion a BETA, el NODO esta en N(" << n.first.first << ", " << n.first.second << ")" << endl;
					if(aux <= n.first.second){
						cout << "\t\t\t\t\tNODO N(" << n.first.first << ", " << n.first.second << ") se encuentra en la region dominada inferior derecha de S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con BETA = " << beta  << endl;
						isDominatedBySkyline = true;
						break;
					}
				}	
			}
			if(((*skyline)[i].first >= n.first.first && (*skyline)[i].second >= n.first.second)
				&& (((*skyline)[i].first > n.first.first) || ((*skyline)[i].second > n.first.second))){
				cout << "ESTO NO DEBIESE DE SUCEDER" << endl; 
			}
		}
		// Si el nodo no está dominado por el skyline actual
		if(!isDominatedBySkyline){
			// Calcula el índice del primer hijo en la representación de bits
			firstChild = 0;
			if(n.second.second != -1){
				firstChild = rank1(rep->btl, n.second.second) * pow(K, 2);
			}
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
					// maxX = minX + (n.second.first / K) * (i % K);
					// maxY = maxY + (n.second.first / K) * ceil( i / K);
					nChild = n.second.first / K;
					iChild = firstChild + i;
					/*
					cout << "NODO HIJO H(" << minX << "->" << maxX << ", " << minY << "->" << maxY <<"), nChild: " << nChild << ", iChild: " << iChild << endl;
 					cout << "maxX = " << maxX << endl;
					cout << "maxY = " << maxY << endl;
					*/
					// Asigna a la variable isDominatedBySkyline el valor false
					isDominatedBySkyline = false;
					// Verifica si el hijo está dominado por el skyline actual
					cout << "-\n\tVerifica si el HIJO H(" << minX << ", " << minY << ") esta dominado por el skyline actual: " << skyline->size() << endl;
					for(int i = 0; i < skyline->size(); i++){
						cout << "\t\tCompara el HIJO H(" <<  minX << ", " << minY << ") con S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")"  << endl;
						// Verifica si el nodo o punto se encuentra en uno de las tres regiones de dominancia
						if(((*skyline)[i].first <= minX) && ((*skyline)[i].second <= minY)
							&& (((*skyline)[i].first < minX) || ((*skyline)[i].second < minY))){
							// El nodo o punto se encuentra en la region dominada
							cout << "\t\t\tHIJO H(" << minX << ", " << minY << ") se encuentra en la region dominada superior derecha de S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;
							isDominatedBySkyline = true;
							break;
						}
						if(((*skyline)[i].first >= minX && (*skyline)[i].second <= minY)
							&& (((*skyline)[i].first > minX) || ((*skyline)[i].second < minY))){
							cout << "\t\t\tHIJO H(" << minX << ", " << minY << ") se encuentra en la region de dominancia superior izquierda de S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;
							// El nodo o punto se encuentra en la region de dominancia superior izquierda
							if(alpha > 0 && alpha < 90){
								// Si alpha esta dentro del rango de 0 y 90, verifica que el nodo o punto se encuentre sobre la recta
								float tanAlpha = tan((alpha + 90)*(M_PI/180)); 
	                			float aux = (tanAlpha*(minX - (*skyline)[i].first)) + ((*skyline)[i].second);
								cout << "tanALpha: " << tanAlpha << ", AUX: " << aux << endl;
								cout << "\t\t\t\tCompara el HIJO H(" <<  minX << ", " << minY << ") con S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con ALPHA = " << alpha  << endl;
								cout << "\t\t\t\t\tCuando S(x = " << minX << ", y = " << aux << ") en relacion a ALPHA, el HIJO esta en H(" << minX << ", " << minY << ")" << endl;
								if(aux <= minY){
									cout << "\t\t\t\t\tHIJO H(" << minX << ", " << minY << ") se encuentra en la region dominada superior izquierda de S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con ALPHA = " << alpha  << endl;
									isDominatedBySkyline = true;
									break;
								}
							}
						}
						if(((*skyline)[i].first <= minX && (*skyline)[i].second >= minY)
							&& (((*skyline)[i].first < minX) || ((*skyline)[i].second > minY))){
							cout << "\t\t\tHIJO H(" << minX << ", " << minY << ") se encuentra en la region de dominancia inferior derecha de S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;							
							// EL nodo o punto se encuentra en la region de dominancia inferior derecha
							if(beta > 0 && beta < 90){
								// Si beta esta dentro del rango de 0 y 90, verifica que el nodo o punto se encuentre sobre la recta
								float tanBeta= tan((360 - beta)*(M_PI/180)); 
	                			float aux = (tanBeta*(minX - (*skyline)[i].first)) + ((*skyline)[i].second);
								cout << "\t\t\t\tCompara el HIJO H(" <<  minX << ", " << minY << ") con S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con BETA = " << beta  << endl;
								cout << "\t\t\t\t\tCuando S(x = " << minX << ", y = " << aux << ") en relacion a BETA, el HIJO esta en H(" << minX << ", " << minY << ")" << endl;
								if(aux <= minY){
									cout << "\t\t\t\t\tHIJO H(" << minX << ", " << minY << ") se encuentra en la region dominada inferior derecha de S(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con BETA = " << beta  << endl;
									isDominatedBySkyline = true;
									break;
								}
							}	
						}
						if(((*skyline)[i].first >= minX && (*skyline)[i].second >= minY)
							&& (((*skyline)[i].first > minX) || ((*skyline)[i].second > minY))){
							cout << "ESTO NO DEBIESE DE SUCEDER" << endl; 
						}
					}
					// Si el hijo no está dominado por el skyline actual
					if(!isDominatedBySkyline){
						// Verifica si el hijo es una hoja
						isALeaf = false;
						if(firstChild + i != -1){
							isALeaf = firstChild + i >= rep->bt_len;
						}
						n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
						// Si no es una hoja, agrega el hijo al montículo
						if(!isALeaf){
							heap.push_back(n_i);
      						push_heap(heap.begin(), heap.end(), cmpE);
							cout << "\t\t***Agrega el HIJO H(" << n_i.first.first << ", " << n_i.first.second << ") al HEAP***" << endl;

						}else{
							// Si es una hoja, agrega al skyline
							skyline->push_back(n_i.first);
							cout << "\t\t***Agrega el HIJO H(" << n_i.first.first << ", " << n_i.first.second << ") al SKYLINE***" << endl;
						}
					}
				}
			}
		}
		if((heap.size() == 0) && (alpha != 0 || beta != 0)){
			cout << "\tVerifica el SKYLINE" << endl;
			for(int i = 0; i < skyline->size(); i++){
				for(int j = 0; j < skyline->size(); j++){
					cout << "\t\tCompara el SKYLINE S1(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") con el SKYLINE S2(" << (*skyline)[j].first << ", " << (*skyline)[j].second << ")" << endl;
					if(((*skyline)[i].first >= (*skyline)[j].first && (*skyline)[i].second <= (*skyline)[j].second)
						&& (((*skyline)[i].first > (*skyline)[j].first) || ((*skyline)[i].second < (*skyline)[j].second))){
						cout << "\t\t\tSKYLINE S2(" << (*skyline)[j].first << ", " << (*skyline)[j].second << ") se encuentra en la region de dominancia superior izquierda de SKYLINE S1(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;
						// El nodo o punto se encuentra en la region de dominancia superior izquierda
						if(alpha > 0 && alpha < 90){
							// Si alpha esta dentro del rango de 0 y 90, verifica que el punto Skyline se encuentre sobre la recta
							float tanAlpha = tan((alpha + 90)*(M_PI/180));  
							float aux = (tanAlpha*((*skyline)[j].first - (*skyline)[i].first)) + ((*skyline)[i].second);
							cout << "\t\t\t\tCompara el SKYLINE S2(" <<  (*skyline)[j].first << ", " << (*skyline)[j].second << ") con SKYLINE S1(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con ALPHA = " << alpha  << endl;
							cout << "\t\t\t\t\tCuando S1(x = " << (*skyline)[j].first << ", y = " << aux << ") en relacion a ALPHA, el SKYLINE esta en S2(" << (*skyline)[j].first << ", " << (*skyline)[j].second << ")" << endl;
							if(aux <= (*skyline)[j].second){
								cout << "\t\t\t\t\tSKYLINE S2(" << (*skyline)[j].first << ", " << (*skyline)[j].second << ") se encuentra en la region dominada superior izquierda de S1(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con ALPHA = " << alpha  << endl;
								skyline->erase(skyline->begin() + j);
							}
						}
					}
					if(((*skyline)[i].first <= (*skyline)[j].first && (*skyline)[i].second >= (*skyline)[j].second)
						&& (((*skyline)[i].first < (*skyline)[j].first) || ((*skyline)[i].second > (*skyline)[j].second))){
						cout << "\t\t\tSKYLINE S2(" << (*skyline)[j].first << ", " << (*skyline)[j].second << ") se encuentra en la region de dominancia inferior derecha de SKYLINE S1(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ")" << endl;							
						// EL nodo o punto se encuentra en la region de dominancia inferior derecha
						if(beta > 0 && beta < 90){
							// Si beta esta dentro del rango de 0 y 90, verifica que el nodo o punto se encuentre sobre la recta
							float tanBeta = tan((360 - beta)*(M_PI/180)); 
	                		float aux = (tanBeta*((*skyline)[j].first - (*skyline)[i].first)) + ((*skyline)[i].second);
							cout << "\t\t\t\tCompara el SKYLINE S2(" <<  (*skyline)[j].first << ", " << (*skyline)[j].second << ") con SKYLINE S1(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con BETA = " << beta  << endl;
							cout << "\t\t\t\t\tCuando S1(x = " << (*skyline)[j].first << ", y = " << aux << ") en relacion a BETA, el SKYLINE esta en S2(" << (*skyline)[j].first << ", " << (*skyline)[j].second << ")" << endl;
							if(aux <= (*skyline)[j].second){
								cout << "\t\t\t\t\tSKYLINE S2(" << (*skyline)[j].first << ", " << (*skyline)[j].second << ") se encuentra en la region dominada inferior derecha de S1(" << (*skyline)[i].first << ", " << (*skyline)[i].second << ") en relacion con BETA = " << beta  << endl;
								skyline->erase(skyline->begin() + j);
							}
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
