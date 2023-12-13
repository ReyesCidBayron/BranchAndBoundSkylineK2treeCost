#include "EnumeratingCompact.hpp"

bool cmpMB(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	return a.first.first+a.first.second > b.first.first+b.first.second;
}

// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<pair<int, int>, int>> * EnumeratingCompact::enumeratingSkyline(MREP * rep){
	Count cc;
	int NSize = rank1(rep->btl, rep->bt_len) + 1;
	int * N = new int[NSize];
	for(int i = 0; i < NSize; i++){
		N[i] = 0;
	}
	
	vector<pair<pair<int, int>, int>> * skyline = new vector<pair<pair<int, int>, int>>();
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	make_heap(heap.begin(), heap.end(), cmpMB);
	
	pair<pair<int,int>, pair<int, int>> n, n_i;
	
	bool isDominatedBySkyline, subMatrixEmpty, isPruned, isALeaf;
	int firstChild, minX, minY, nChild, iChild, x, y, counter;
	
    while(heap.size() != 0){
		n = heap.front();
		pop_heap(heap.begin(), heap.end(), cmpMB);
    	heap.pop_back();
		
		isDominatedBySkyline = false;
		for(int i = 0; i < skyline->size(); i++){
			if(((*skyline)[i].first.first <= n.first.first) && 
			   ((*skyline)[i].first.second <= n.first.second) && 
			   (((*skyline)[i].first.first < n.first.first) || 
				((*skyline)[i].first.second < n.first.second))){
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
				minX = n.first.first + (n.second.first / K) * (i % K);
				minY = n.first.second + (n.second.first / K) * ceil( i / K);
				nChild = n.second.first / K;
				iChild = firstChild + i;
				n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
				
				subMatrixEmpty = !isBitSet(rep->btl, firstChild + i);
				
				if(!subMatrixEmpty){
					isDominatedBySkyline = false;
					for(int i = 0; i < skyline->size(); i++){
						if(((*skyline)[i].first.first <= n_i.first.first) && 
						   ((*skyline)[i].first.second <= n_i.first.second) && 
						   (((*skyline)[i].first.first < n_i.first.first) || 
							((*skyline)[i].first.second < n_i.first.second))){
							isDominatedBySkyline = true;
							break;
						}
					}
				}
				
				
                if(!subMatrixEmpty && !isDominatedBySkyline){
					isPruned = false;
					for(ushort j = 0; j < (i / K); j++){
						for(ushort l = 0; l < (i % K); l++){
							isPruned = isPruned || isBitSet(rep->btl, firstChild + l);
						}
					}
					
                    if(!isPruned){
						isALeaf = false;
						if(firstChild + i != -1){
							isALeaf = firstChild + i >= rep->bt_len;
						}
						
						if(!isALeaf){
							heap.push_back(n_i);
      						push_heap(heap.begin(), heap.end(), cmpMB);
						}else{
							x = n.first.first + (i % K);
							y = n.first.second + ceil(i / K);
							counter = enumeratingCount(rep, cc, x, y, N);
							skyline->push_back(make_pair(make_pair(x, y), counter));
						}
					}else{
						if(N[rank1(rep->btl, n_i.second.second)] == 0){
							N[rank1(rep->btl, n_i.second.second)] = cc.countMatrix(rep, n_i.second.second);
						}
					}				
                }
            }
        }
    }

	delete [] N;
    return skyline;
}


int EnumeratingCompact::enumeratingCount(MREP * rep, Count & cc, int x, int y, int * N){
	int total = 0;
	queue<pair<pair<int,int>, pair<int, int>>> cola;
	cola.push(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	
	pair<pair<int,int>, pair<int, int>> n, n_i;
	int firstChild, minX, minY, nChild, iChild;
	bool isMinInside, isMaxInside, isALeaf, intersectRN, subMatrixEmpty;
	
	while(cola.size() != 0){
		n = cola.front();
		cola.pop();
		
		firstChild = 0;
		if(n.second.second != -1){
			firstChild = rank1(rep->btl, n.second.second) * pow(K,2);
		}
		
		for(uint i = 0; i < pow(K, 2); i++){
			subMatrixEmpty = !isBitSet(rep->btl, firstChild + i);
			if(!subMatrixEmpty){
				minX = n.first.first + (n.second.first / K) * (i % K);
				minY = n.first.second + (n.second.first / K) * ceil( i / K);
				nChild = n.second.first / K;
				iChild = firstChild + i;
				n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
				
				isMinInside = x <= minX && y <= minY && 
					minX <= rep->numberOfNodes-1 && minY <= rep->numberOfNodes-1;
				isMaxInside = x <= minX+nChild-1 && y <= minY+nChild-1
					&& minX+nChild-1 <= rep->numberOfNodes-1 && minY+nChild-1 <= rep->numberOfNodes-1;
				
				if(isMinInside && isMaxInside){
					isALeaf = false;
					if(firstChild + i != -1){
						isALeaf = firstChild + i >= rep->bt_len;
					}
					
					if(!isALeaf){
						if(N[rank1(rep->btl, n_i.second.second)] == 0){
							N[rank1(rep->btl, n_i.second.second)] = cc.countMatrix(rep, n_i.second.second);
						}
						total += N[rank1(rep->btl, n_i.second.second)];
					}else{
						total++;
					}
				}else{
					intersectRN = !(rep->numberOfNodes-1 < minX || minX+nChild-1 < x) &&
						  			!(rep->numberOfNodes-1 < minY || minY+nChild-1 < y);
					
					if(intersectRN){
						cola.push(n_i);
					}
				}
			}
		}
	}
	return total-1;
}
