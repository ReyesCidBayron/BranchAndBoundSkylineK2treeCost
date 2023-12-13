#include "Transformador.h"

bool cmpT(Punto * a, Punto * b){
	if(a->getY() != b->getY()){
		return a->getY() < b->getY();
	}
	return  a->getX() < b->getX();
}

Transformador::Transformador(){

}

Transformador::~Transformador(){
	
}

/*Lee la lista de puntos desde disco y entrega un array con puntos*/
Punto ** Transformador::readListPoint(char * path){
	uint tamano = 1000000;
	string completo(path);
	completo+= ".txt";
	ifstream fe(completo.c_str()); 
	char cadena[128];
	char vacia[] = "";
	Punto ** dataset = new Punto*[tamano];
	
	fe.getline(cadena, 128);
	uint i = 0;
	uint x, y;
	while(strcmp (cadena, vacia) != 0){
		string p = strtok(cadena, " ");
		x = stoi(p);
		p = strtok(NULL, " ");
		y = stoi(p);
		
		dataset[i] = new Punto(x, y);
		i++;
		if(i == tamano){
			dataset = enlargeListPoints(dataset, tamano);
			tamano *= 2;
		}
		fe.getline(cadena, 128);
	}
	
	dataset[i] = new Punto(-1, -1);
	
	return dataset;
}

/*Lee la lista de puntos desde disco y entrega un array con puntos. 
La diferencia con la funcion anterior es que los datos del conjunto real vienen en otro formato
*/
Punto ** Transformador::readFromRealDataset(char * path){
	string completo(path);
	completo+= ".txt";
	ifstream fe(completo.c_str()); 
	
	uint tamano = 1000000;
	Punto ** dataset = new Punto*[tamano];
	
	char cadena[128];
	char vacia[] = "";
	fe.getline(cadena, 128);
	fe.getline(cadena, 128);
	uint i = 0;
	uint x, y;
	
	while(strcmp (cadena, vacia) != 0){
		string p = strtok(cadena, "\t");
		p = strtok(NULL, "\t");
		x = stoi(p);
			
		p = strtok(NULL, "\t");
		y = stoi(p);
		
		dataset[i] = new Punto(x, y);
		i++;
		if(i == tamano){
			dataset = enlargeListPoints(dataset, tamano);
			tamano *= 2;
		}
		fe.getline(cadena, 128);
	}
	
	dataset[i] = new Punto(-1, -1);
	return dataset;
	
}

/*Transforma la lista de puntos en una lista de adyacencia*/
ALREP* Transformador::fromListPointToAdList(Punto ** dataset){
	uint nodos = calcularNodes(dataset);
	ulong edges = calcularEdges(dataset);
	sort(dataset, dataset + edges, cmpT);
	ALREP * listaAdyacencia = new ALREP();
	uint tamano = 100000000;
	int * lista= new int[tamano];
	uint indice = 0;
	int fila = 1;
	int y, lastY;
	uint i = 0;
	while(!(dataset[i]->getX() == -1 && dataset[i]->getY() == -1)){
		Punto * p = dataset[i];
		y = p->getY()+1;
		while(fila <= y){
			lista[indice] = -(fila);
			indice++;
			if(indice == tamano){
				lista = enlargeAdList(lista, tamano);
				tamano *= 2;
			}
			fila++;
		}
		
		lastY = y;
		if(y == lastY){
			lista[indice] = p->getX()+1;
			indice++;
			if(indice == tamano){
				lista = enlargeAdList(lista, tamano);
				tamano *= 2;
			}
		}
		
		
		i++;
	}
	
	while(fila <= nodos){
		lista[indice] = -fila;
		indice++;
		if(indice == tamano){
			lista = enlargeAdList(lista, tamano);
			tamano *= 2;
		}
		fila++;
	}
		
	listaAdyacencia->numNodes = nodos;
	listaAdyacencia->numEdges = edges;
	listaAdyacencia->listady = lista;
	
	return listaAdyacencia;
}


/*Transforma una lista de adyacencia en un k2tree*/
MREP* Transformador::fromAdListToKtree(ALREP * listaAdyacencia){
	int nodes = listaAdyacencia->numNodes;
	int edges = listaAdyacencia->numEdges;

	uint max_level = floor(log(nodes)/log(K)); 
	if(floor(log(nodes)/log(K))==(log(nodes)/log(K))) {
		max_level=max_level-1;
	}
	
	uint nodes_read=0;
	uint *xedges = new uint[edges];
	uint *yedges = new uint[edges];
	uint cedg = 0;
	int k;
	for(int i=0;i<nodes+edges;i++) {
		k = listaAdyacencia->listady[i];
		if(k<0) {
			nodes_read++;
		}
		else {
			k--;
			xedges[cedg]=nodes_read-1;
			yedges[cedg]=k;
			cedg++;
		}
	}
	
	MREP * ktree = compactCreateKTree(xedges, yedges, nodes,edges,max_level);
	
	return ktree;
}

/*Imprime los datos de una lista de adyacencia*/
void Transformador::printAdList(ALREP * listaAdyacencia){
	printf("Nodes: %d\n", listaAdyacencia->numNodes);
	printf("Edges: %ld", listaAdyacencia->numEdges);

	printf("\n*****  Lista de Adyacencia  *****");
	int aux, i;
	for(i=0; i < listaAdyacencia->numNodes + listaAdyacencia->numEdges; i++){
		aux = listaAdyacencia->listady[i];
		if(aux < 0){
			printf("\n%d\t", aux);
		}else{
			printf("%d\t", aux);			
		}

	}
	printf("\n*****  Fin de Lista  *****\n");
}

/*Calcula la cantidad de nodos de la lista de adyacencia*/
uint Transformador::calcularNodes(Punto ** dataset){
	uint nodos = 0;
	uint i = 0;
	while(!(dataset[i]->getX() == -1 && dataset[i]->getY() == -1)){
		Punto * p = dataset[i];
		if(p->getX() > nodos){
			nodos = (uint) p->getX();
		}
		if(p->getY() > nodos){
			nodos = (uint) p->getY();
		}
		i++;
	}
	nodos++;
	uint pot2 = 2;
	while(pot2 < nodos){
		pot2 *= 2;
	}
	return pot2;
}

/*Calcula la cantidad de aristas de la lista de adyacencia*/
ulong Transformador::calcularEdges(Punto ** dataset){
	uint i = 0;
	while(!(dataset[i]->getX() == -1 && dataset[i]->getY() == -1)){
		i++;
	}
	return i;
}

/*Entrega el punto cuyo valor de Y es menor. Si ambos tienen igual Y, entrega el del menor X*/
/*bool Transformador::menor(Punto * a, Punto * b){
	if(a->getY() < b->getY()){
		return true;
	}else{
		if(a->getY() == b->getY() && a->getX() < b-> getX()){
			return true;
		}else{
			return false;
		}
	}
}*/

/*Entrega más memoria a una lista de adyacencia*/
int * Transformador::enlargeAdList(int * lista, ulong tamano){
	ulong nuevoTam = tamano * 2;
	int * nuevaLista = new int[nuevoTam];
	for(ulong i = 0; i < tamano; i++){
		nuevaLista[i] = lista[i];
	}
	return nuevaLista;
}

/*Entrega más memoria a un array de puntos de adyacencia*/
Punto ** Transformador::enlargeListPoints(Punto ** lista, ulong tamano){
	ulong nuevoTam = tamano * 2;
	Punto ** nuevaLista = new Punto*[nuevoTam];
	for(ulong i = 0; i < tamano; i++){
		nuevaLista[i] = lista[i];
	}
	return nuevaLista;
}

