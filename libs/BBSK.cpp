#include "BBSK.hpp"

// Función de comparación para el montículo (heap) en funcion a la distancia de Manhattan
bool cmpM(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return a.first.first+a.first.second > b.first.first+b.first.second;
}

// Función de comparación para el montículo (heap) en funcion a la distancia Euclidiana
bool cmpE(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return pow(a.first.first,2)+pow(a.first.second,2) > pow(b.first.first,2)+pow(b.first.second,2);
}

// Función principal para calcular el skyline utilizando BBSK con distancia de Manhattan
// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * BBSK::skylineManhattan(MREP * rep){
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	make_heap(heap.begin(), heap.end(), cmpM);
	pair<pair<int, int>, pair<int, int>> r = make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, rep->numberOfNodes));
	pair<pair<int,int>, pair<int, int>> n, n_i;
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned;
	int firstChild, minX, minY, nChild, iChild;
	while(heap.size() != 0){
		n = heap.front();
		pop_heap(heap.begin(), heap.end(), cmpM);
    	heap.pop_back();
		isDominatedBySkyline = false;
		for(int i = 0; i < skyline->size(); i++){
			if(((*skyline)[i].first <= n.first.first) && ((*skyline)[i].second <= n.first.second)
			   	&& (((*skyline)[i].first < n.first.first) || ((*skyline)[i].second < n.first.second))){
				isDominatedBySkyline = true;
				break;
			}
		}
		if(!isDominatedBySkyline){
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
					for(int i = 0; i < skyline->size(); i++){
						if(((*skyline)[i].first <= minX) && ((*skyline)[i].second <= minY)
							&& (((*skyline)[i].first < minX) || ((*skyline)[i].second < minY))){
							isDominatedBySkyline = true;
							break;
						}
					}
					if(!isDominatedBySkyline){
						isALeaf = false;
						if(firstChild + i != -1){
							isALeaf = firstChild + i >= rep->bt_len;
						}
						n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
						if(!isALeaf){
							heap.push_back(n_i);
      						push_heap(heap.begin(), heap.end(), cmpM);
						}else{
							skyline->push_back(n_i.first);
						}
					}
				}
			}
		}
	}
	return skyline;
}

// Función principal para calcular el skyline utilizando BBSK con distancia Euclidiana
// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * BBSK::skylineEuclidean(MREP * rep){
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	make_heap(heap.begin(), heap.end(), cmpE);
	pair<pair<int, int>, pair<int, int>> r = make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, rep->numberOfNodes));
	pair<pair<int,int>, pair<int, int>> n, n_i;
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned;
	int minX, minY, nChild, iChild;
	while(heap.size() != 0){
		n = heap.front();
		pop_heap(heap.begin(), heap.end(), cmpE);
    	heap.pop_back();
		isDominatedBySkyline = false;
		for(int i = 0; i < skyline->size(); i++){
			if(((*skyline)[i].first <= n.first.first) && ((*skyline)[i].second <= n.first.second)
			   	&& (((*skyline)[i].first < n.first.first) || ((*skyline)[i].second < n.first.second))){
				isDominatedBySkyline = true;
				break;
			}
		}
		if(!isDominatedBySkyline){
			uint firstChild = 0;
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
					n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
					isDominatedBySkyline = false;
					for(int i = 0; i < skyline->size(); i++){
						if(((*skyline)[i].first <= n_i.first.first) && ((*skyline)[i].second <= n_i.first.second)
							&& (((*skyline)[i].first < n_i.first.first) || ((*skyline)[i].second < n_i.first.second))){
							isDominatedBySkyline = true;
							break;
						}
					}
					if(!isDominatedBySkyline){
						isALeaf = false;
						if(firstChild + i != -1){
							isALeaf = firstChild + i >= rep->bt_len;
						}
						if(!isALeaf){
							heap.push_back(n_i);
      						push_heap(heap.begin(), heap.end(), cmpE);
						}else{
							skyline->push_back(n_i.first);
						}
					}
				}
			}
		}
	}
	return skyline;
}