#include "ConstrainedBBSK.hpp"

bool cmpCM(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return a.first.first+a.first.second > b.first.first+b.first.second;
}

bool cmpCE(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return pow(a.first.first,2)+pow(a.first.second,2) > pow(b.first.first,2)+pow(b.first.second,2);
}

// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * ConstrainedBBSK::constrainedManhattan(MREP * rep, int x1, int x2, int y1, int y2){
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	make_heap(heap.begin(), heap.end(), cmpCM);
	
	pair<pair<int,int>, pair<int, int>> n, n_i;
	
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned, 
		interserctRange, isMinInside, isMaxInside;
	int firstChild, minX, minY, nChild, iChild;
	
	while(heap.size() != 0){
		n = heap.front();
		pop_heap(heap.begin(), heap.end(), cmpCM);
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

				isMinInside = x1 <= n.first.first && y1 <= n.first.second 
					&& n.first.first <= x2 && n.first.second <= y2;
				isMaxInside = x1 <= n.first.first+n.second.first-1 
					&& y1 <= n.first.second+n.second.first-1
					&& n.first.first+n.second.first-1 <= x2 
					&& n.first.second+n.second.first-1 <= y2;

				if(isMinInside && isMaxInside){
					for(ushort j = 0; j < (i / K); j++){
						for(ushort l = 0; l < (i % K); l++){
							isPruned = isPruned || isBitSet(rep->btl, firstChild + l);
						}
					}
				}

				if(!subMatrixEmpty && !isPruned){
					minX = n.first.first + (n.second.first / K) * (i % K);
					minY = n.first.second + (n.second.first / K) * ceil( i / K);
					nChild = n.second.first / K;
					iChild = firstChild + i;
					
					interserctRange = !(x2 < minX || minX+nChild-1 < x1) &&
										!(y2 < minY || minY+nChild-1 < y1);
					if(interserctRange){
						isDominatedBySkyline = false;
						for(int i = 0; i < skyline->size(); i++){
							if(((*skyline)[i].first <= minX) && ((*skyline)[i].second <= minY)
								&& (((*skyline)[i].first < minX) || ((*skyline)[i].second < minY))){
								isDominatedBySkyline = true;
								break;
							}
						}

						if(!isDominatedBySkyline){
							n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
							isALeaf = false;
							if(firstChild + i != -1){
								isALeaf = firstChild + i >= rep->bt_len;
							}
							if(!isALeaf){
								heap.push_back(n_i);
								push_heap(heap.begin(), heap.end(), cmpCM);
							}else{
								skyline->push_back(n_i.first);
							}

						}
					}

				}
			}		
		}
		
	}
	
	return skyline;
}

// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * ConstrainedBBSK::constrainedEuclidean(MREP * rep, int x1, int x2, int y1, int y2){
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	make_heap(heap.begin(), heap.end(), cmpCE);
	
	pair<pair<int,int>, pair<int, int>> n, n_i;
	
	bool isDominatedBySkyline, isALeaf, subMatrixEmpty, isPruned, 
		interserctRange, isMinInside, isMaxInside;
	int firstChild, minX, minY, nChild, iChild;
	
	while(heap.size() != 0){
		n = heap.front();
		pop_heap(heap.begin(), heap.end(), cmpCE);
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

				isMinInside = x1 <= n.first.first && y1 <= n.first.second 
					&& n.first.first <= x2 && n.first.second <= y2;
				isMaxInside = x1 <= n.first.first+n.second.first-1 
					&& y1 <= n.first.second+n.second.first-1
					&& n.first.first+n.second.first-1 <= x2 
					&& n.first.second+n.second.first-1 <= y2;

				if(isMinInside && isMaxInside){
					for(ushort j = 0; j < (i / K); j++){
						for(ushort l = 0; l < (i % K); l++){
							isPruned = isPruned || isBitSet(rep->btl, firstChild + l);
						}
					}
				}

				if(!subMatrixEmpty && !isPruned){
					minX = n.first.first + (n.second.first / K) * (i % K);
					minY = n.first.second + (n.second.first / K) * ceil( i / K);
					nChild = n.second.first / K;
					iChild = firstChild + i;
					
					interserctRange = !(x2 < minX || minX+nChild-1 < x1) &&
										!(y2 < minY || minY+nChild-1 < y1);
					if(interserctRange){
						isDominatedBySkyline = false;
						for(int i = 0; i < skyline->size(); i++){
							if(((*skyline)[i].first <= minX) && ((*skyline)[i].second <= minY)
								&& (((*skyline)[i].first < minX) || ((*skyline)[i].second < minY))){
								isDominatedBySkyline = true;
								break;
							}
						}

						if(!isDominatedBySkyline){
							n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
							isALeaf = false;
							if(firstChild + i != -1){
								isALeaf = firstChild + i >= rep->bt_len;
							}
							if(!isALeaf){
								heap.push_back(n_i);
								push_heap(heap.begin(), heap.end(), cmpCE);
							}else{
								skyline->push_back(n_i.first);
							}

						}
					}

				}
			}		
		}
		
	}
	
	return skyline;
}