#include "BBSKC.hpp"

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
	double aCostAlpha = (((1 - (Alpha))*(a.first.first)) + ((Alpha)*(a.first.second)));
	double aCostBeta = (((Beta)*(a.first.first)) + ((1 - (Beta))*(a.first.second)));
	double bCostAlpha = (((1 - (Alpha))*(b.first.first)) + ((Alpha)*(b.first.second)));
	double bCostBeta = (((Beta)*(b.first.first)) + ((1 - (Beta))*(b.first.second)));
	return (aCostAlpha + aCostBeta) > (bCostAlpha + bCostBeta);
}

// Función de comparación para el montículo (heap) en relacion a la Funcion de Costos Euclidean
bool cmpCE(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	double aCostAlpha = (((1 - (Alpha))*(a.first.first)) + ((Alpha)*(a.first.second)));
	double aCostBeta = (((Beta)*(a.first.first)) + ((1 - (Beta))*(a.first.second)));
	double bCostAlpha = (((1 - (Alpha))*(b.first.first)) + ((Alpha)*(b.first.second)));
	double bCostBeta = (((Beta)*(b.first.first)) + ((1 - (Beta))*(b.first.second)));
	return (pow(aCostAlpha, 2) + pow(aCostBeta, 2)) >= (pow(bCostAlpha, 2) + pow(bCostBeta, 2));
}

// Función principal para calcular el skyline utilizando BBSK con Funcion de Costos Euclidean
// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * BBSKC::skylineCostEuclidean(MREP * rep, float alpha, float beta){
	Alpha = alpha;
	Beta = beta;
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	make_heap(heap.begin(), heap.end(), cmpCE);
	pair<pair<int, int>, pair<int, int>> r = make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, rep->numberOfNodes));
	pair<pair<int,int>, pair<int, int>> n, n_i;
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned, isSkyline;
	int firstChild, minX, minY, nChild, iChild;
	double aCostAlpha, aCostBeta, bCostAlpha, bCostBeta;
	while(heap.size() != 0){
		n = heap.front();
		pop_heap(heap.begin(), heap.end(), cmpCE);
    	heap.pop_back();
		aCostAlpha = (((1 - (alpha))*(n.first.first)) + ((alpha)*(n.first.second)));
		aCostBeta = (((beta)*(n.first.first)) + ((1 - (beta))*(n.first.second)));
		isDominatedBySkyline = false;
		for(int i = 0; i < skyline->size(); i++){
			bCostAlpha =  (((1 - (alpha))*((*skyline)[i].first)) + ((alpha)*((*skyline)[i].second)));
			bCostBeta = (((beta)*((*skyline)[i].first)) + ((1 - (beta))*((*skyline)[i].second)));
			if((aCostAlpha >= bCostAlpha && aCostBeta >= bCostBeta) && (aCostAlpha > bCostAlpha || aCostBeta > bCostBeta)){
				isDominatedBySkyline = true;
				break;
			}
		}
		isSkyline = false;
		if(!isDominatedBySkyline && !isSkyline && n.second.second != -1){
			isALeaf = n.second.second >= rep->bt_len;
			if(isALeaf){
				isSkyline = true;
				skyline->push_back(n.first);
			}
		}
		if(!isDominatedBySkyline && !isSkyline){
			firstChild = 0;
			if(n.second.second != -1){
				firstChild = rank1(rep->btl, n.second.second) * pow(K, 2);
			}
			for(uint i = 0; i < pow(K, 2); i++){
				subMatrixEmpty = !isBitSet(rep->btl, firstChild + i);
				isPruned = false;
				for(ushort j = 0; j < (i / K); j++){
					for(ushort l = 0; l < (i % K); l++){
						isPruned = isPruned || isBitSet(rep->btl, firstChild + l);
					}
				}
				if(!subMatrixEmpty && !isPruned){
					minX = n.first.first + (n.second.first / K) * (i % K);
    				minY = n.first.second + (n.second.first / K) * ceil( i / K);
					nChild = n.second.first / K;
					iChild = firstChild + i;
					isDominatedBySkyline = false;
					aCostAlpha = (((1 - (alpha))*(minX)) + ((alpha)*(minY)));
					aCostBeta = (((beta)*(minX)) + ((1 - (beta))*(minY)));
					for(int i = 0; i < skyline->size(); i++){
						bCostAlpha = (((1 - (alpha))*((*skyline)[i].first)) + ((alpha)*((*skyline)[i].second)));
						bCostBeta = (((beta)*((*skyline)[i].first)) + ((1 - (beta))*((*skyline)[i].second)));
						if((aCostAlpha >= bCostAlpha && aCostBeta >= bCostBeta) && (aCostAlpha > bCostAlpha || aCostBeta > bCostBeta)){
							isDominatedBySkyline = true;
							break;
						}
					}
					if(!isDominatedBySkyline){
						n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
						heap.push_back(n_i);
      					push_heap(heap.begin(), heap.end(), cmpCE);
					}
				}
			}
		}
	}
	return skyline;
}

// Función principal para calcular el skyline utilizando BBSK con Funcion de Costos Manhattan
// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * BBSKC::skylineCostManhattan(MREP * rep, float alpha, float beta){
	Alpha = alpha;
	Beta = beta;
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	make_heap(heap.begin(), heap.end(), cmpCM);
	pair<pair<int, int>, pair<int, int>> r = make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, rep->numberOfNodes));
	pair<pair<int,int>, pair<int, int>> n, n_i;
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned, isSkyline;
	int firstChild, minX, minY, nChild, iChild;
	double aCostAlpha, aCostBeta, bCostAlpha, bCostBeta;
	while(heap.size() != 0){
		n = heap.front();
		pop_heap(heap.begin(), heap.end(), cmpCM);
    	heap.pop_back();
		aCostAlpha = (((1 - (alpha))*(n.first.first)) + ((alpha)*(n.first.second)));
		aCostBeta = (((beta)*(n.first.first)) + ((1 - (beta))*(n.first.second)));
		isDominatedBySkyline = false;
		for(int i = 0; i < skyline->size(); i++){
			bCostAlpha =  (((1 - (alpha))*((*skyline)[i].first)) + ((alpha)*((*skyline)[i].second)));
			bCostBeta = (((beta)*((*skyline)[i].first)) + ((1 - (beta))*((*skyline)[i].second)));
			if((aCostAlpha >= bCostAlpha && aCostBeta >= bCostBeta) && (aCostAlpha > bCostAlpha || aCostBeta > bCostBeta)){
				isDominatedBySkyline = true;
				break;
			}
		}
		isSkyline = false;
		if(!isDominatedBySkyline && !isSkyline && n.second.second != -1){
			isALeaf = n.second.second >= rep->bt_len;
			if(isALeaf){
				isSkyline = true;
				skyline->push_back(n.first);
			}
		}
		if(!isDominatedBySkyline && !isSkyline){
			firstChild = 0;
			if(n.second.second != -1){
				firstChild = rank1(rep->btl, n.second.second) * pow(K, 2);
			}
			for(uint i = 0; i < pow(K, 2); i++){
				subMatrixEmpty = !isBitSet(rep->btl, firstChild + i);
				isPruned = false;
				for(ushort j = 0; j < (i / K); j++){
					for(ushort l = 0; l < (i % K); l++){
						isPruned = isPruned || isBitSet(rep->btl, firstChild + l);
					}
				}
				if(!subMatrixEmpty && !isPruned){
					minX = n.first.first + (n.second.first / K) * (i % K);
    				minY = n.first.second + (n.second.first / K) * ceil( i / K);
					nChild = n.second.first / K;
					iChild = firstChild + i;
					isDominatedBySkyline = false;
					aCostAlpha = (((1 - (alpha))*(minX)) + ((alpha)*(minY)));
					aCostBeta = (((beta)*(minX)) + ((1 - (beta))*(minY)));
					for(int i = 0; i < skyline->size(); i++){
						bCostAlpha = (((1 - (alpha))*((*skyline)[i].first)) + ((alpha)*((*skyline)[i].second)));
						bCostBeta = (((beta)*((*skyline)[i].first)) + ((1 - (beta))*((*skyline)[i].second)));
						if((aCostAlpha >= bCostAlpha && aCostBeta >= bCostBeta) && (aCostAlpha > bCostAlpha || aCostBeta > bCostBeta)){
							isDominatedBySkyline = true;
							break;
						}
					}
					if(!isDominatedBySkyline){
						n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
						heap.push_back(n_i);
      					push_heap(heap.begin(), heap.end(), cmpCM);
					}
				}
			}
		}
	}
	return skyline;
}