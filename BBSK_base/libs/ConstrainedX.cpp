#include "ConstrainedX.hpp"

bool cmpCX(pair<pair<int,int>, pair<int, int>> & a, pair<pair<int,int>, pair<int, int>> & b){
	if(a.first.first != b.first.first){
		return a.first.first > b.first.first;
	}else{
		return a.first.second > b.first.second;
	}
}

// Matriz: pair<pair<int,int>, pair<int, int>>: <minPunt, <n (tam), i(rep en T:L)>>
vector<pair<int, int>> * ConstrainedX::constrainedX(MREP * rep, int x1, int x2, int y1, int y2){
	vector<pair<int, int>> * skyline = new vector<pair<int, int>>();
	vector<pair<pair<int,int>, pair<int, int>>> heap;
	heap.push_back(make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, -1)));
	make_heap(heap.begin(), heap.end(), cmpCX);
	vector<pair<pair<int,int>, pair<int, int>>> Q;
	
	pair<pair<int, int>, pair<int, int>> r = 
		make_pair(make_pair(0, 0), make_pair(rep->numberOfNodes, rep->numberOfNodes));
	pair<pair<int,int>, pair<int, int>> n, n_i;
	
	bool intesectRN, isALeaf, subMatrixEmpty, isPruned, 
		intersectRange, isMinInside, isMaxInside;
	int firstChild, minX, minY, nChild, iChild;
	
	while(heap.size() != 0){
		n = heap.front();
		pop_heap(heap.begin(), heap.end(), cmpCX);
    	heap.pop_back();
		
		intesectRN = !(r.second.first < n.first.first || n.first.first+n.second.first-1 < r.first.first) &&
						  !(r.second.second < n.first.second || n.first.second+n.second.first-1 < r.first.second);
		if(intesectRN){
			isALeaf = false;
			if(n.second.second != -1){
				isALeaf = n.second.second  >= rep->bt_len;
			}

			if(!isALeaf){
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
						
						intersectRange = !(x2 < minX || minX+nChild-1 < x1) &&
										!(y2 < minY || minY+nChild-1 < y1);
						if(intersectRange){
							intesectRN = !(r.second.first < minX || minX+nChild-1 < r.first.first) &&
									!(r.second.second < minY || minY+nChild-1 < r.first.second);
						

							if(intesectRN){
								n_i = make_pair(make_pair(minX, minY), make_pair(nChild, iChild));
								heap.push_back(n_i);
								push_heap(heap.begin(), heap.end(), cmpCX);
							}
						}
					}
				}
			}else{
				intersectRange = x1 <= n.first.first && n.first.first <= x2
								&& y1 <= n.first.second && n.first.second <= y2;
				
				if(intersectRange){
					skyline->push_back(n.first);
					r.first.first = n.first.first+1;
					r.second.second = n.first.second-1;
				}
			}
			
		}
		
	}
	return skyline;
}