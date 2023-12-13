#define CANTIDAD_PUNTOS 50000
#define RANGO 100000
#define VUELTAS 30

#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>

#include "KtreeUtils.h"
#include "Transformador.h"

#include "SkylineBBSk.h"
#include "SkylineX.h"
#include "SkylineIngenuo.h"

#include "CompactCount.h"
#include "RangeCount.h"

#include "EnumeratingCompact.h"
#include "EnumeratingRange.h"


using namespace std;

class CorrectitudTest{
public:
	CorrectitudTest();
	~CorrectitudTest();
	void skylineTests();
	void doOneSkylineTest(uint index);
	void countTests();
	void doOneCountTest(uint index);
	void enumeratingTests();
	void doOneEnumeratingTest(uint index);
	
private:
	Transformador * trans;
	Punto ** dataset;
	ALREP * listaAdyacencia;
	MREP * ktree;
	
	void generateInput(int index);
	bool compareVector(vector<Punto*> v1, vector<Punto*> v2);
	bool comparePoints(Punto * p1, Punto * p2);
	void printVector(vector<Punto*> v);
	void printArray(Punto ** dataset);
	uint naiveCount(Rectangulo * r);

};

CorrectitudTest::CorrectitudTest(){
	trans = new Transformador();
}

CorrectitudTest::~CorrectitudTest(){
	
}

void CorrectitudTest::skylineTests(){
	
	for(uint i = 0; i < VUELTAS; i++){
		doOneSkylineTest(i);
	}
		
}

void CorrectitudTest::countTests(){
	srand(time(NULL));
	for(uint i = 0; i < VUELTAS; i++){
		doOneCountTest(i);
	}
}

void CorrectitudTest::enumeratingTests(){
	for(uint i = 0; i < VUELTAS; i++){
		doOneEnumeratingTest(i);
	}
}

void CorrectitudTest::doOneSkylineTest(uint index){
	generateInput(index);
	

	SkylineIngenuo * skI = new SkylineIngenuo();
	SkylineBBSk * skBBS = new SkylineBBSk();
	SkylineX * skX = new SkylineX();
	
	vector<Punto*> ingenuo = skI->calculeSkyline(this->dataset);
	vector<Punto*> bbs = skBBS->calculeSkyline(this->ktree, MANEHATTAN);
	vector<Punto*> skx = skX->calculeSkyline(this->ktree);
	
	bool exito = true;

	if(!compareVector(ingenuo,bbs)){
		cout << "El Skyline ingenuo es diferente al Skyline BBSK2tree";
		exito = false;
	}
	if(!compareVector(ingenuo,skx)){
		cout << "El Skyline ingenuo es diferente al Skyline X";
		exito = false;
	}
	if(!compareVector(bbs,skx)){
		cout << "El Skyline BBSK2tree es diferente al Skyline X";
		exito = false;
	}

	if(exito){
		cout << "\nTest automático " << index << " exitoso" ;
		
		
	}else{
		cout << "\nContenido del SkI: ";
		printVector(ingenuo);
		cout << "\nContenido del SkB: ";
		printVector(bbs);
		cout << "\nContenido del SkX: ";
		printVector(skx);
		cout << "\nTest automático " << index << " fallido";
	}
	
}



void CorrectitudTest::doOneCountTest(uint index){
	generateInput(index);
	uint x_1 = (uint) (rand() % RANGO);
	uint y_1 = (uint) (rand() % RANGO);
	
	uint x_2 = (uint) ((x_1 + 1) + rand() % (RANGO + 1 - (x_1 + 1)));
	uint y_2 = (uint) ((y_1 + 1) + rand() % (RANGO + 1 - (y_1 + 1)));
	
	Rectangulo * r = new Rectangulo(new Punto(x_1, y_1), new Punto(x_2, y_2));
	
	CompactCount * cc = new CompactCount();
	RangeCount * rc = new RangeCount();
	
	uint result1 = naiveCount(r);
	uint result2 = cc->count(this->ktree, r);
	uint result3 = rc->count(this->ktree, r);
	
	if(result1 == result2 && result2 == result3){
		cout << "Test " << index << " exitoso ";
	}else{
		cout << "Test " << index << " fallido. Ing: " << result1 << " - Com: " << result2  << " - Rang: " << result3;
		r->print();
		
	}
	
	cout << endl;																										
	
}



void CorrectitudTest::doOneEnumeratingTest(uint index){
	
	generateInput(index);
	

	EnumeratingRange * eSkRg = new EnumeratingRange();
	EnumeratingCompact * eSkCm = new EnumeratingCompact();
	
	vector<Punto*> range = eSkRg->enumeratingSkyline(ktree);
	vector<Punto*> range2 = eSkRg->enumeratingCompactSkyline(ktree);
	vector<Punto*> compact = eSkCm->enumeratingSkyline(ktree);
	
	if(!compareVector(range,compact) || !compareVector(range, range2)){
		cout << "\nContenido del range: ";
		printVector(range);
		cout << "\nContenido del range 2: ";
		printVector(range2);
		cout << "\nContenido del compact: ";
		printVector(compact);
		cout << "\nTest automático " << index << " fallido";
	}else{
		cout << "\nTest automático " << index << " exitoso";
	}
	
	
}

void CorrectitudTest::generateInput(int index){
	string path = "automatic_test/CorrectitudTest" + to_string(index);
	char *addr= new char[128];
	strcpy(addr,path.c_str());
	
	
	this->dataset = trans->readListPoint(addr);
	
	this->listaAdyacencia = loadAdyacencyList(addr);
	this->ktree = loadRepresentation(addr);
	
	
}

bool CorrectitudTest::compareVector(vector<Punto*> v1, vector<Punto*> v2){
	for(Punto * p1 : v1){
		bool encontrado = false;
		for(Punto * p2 : v2){
			if(comparePoints(p1,p2)){
				encontrado = true;
				break;
			}
		}
		if(!encontrado){
			cout << "El punto ";
			p1->print();
			cout << " no fue encontrado \n";
			return false;
		}
	}
	return true;
}

bool CorrectitudTest::comparePoints(Punto * p1, Punto * p2){
	return p1->getX() == p2->getX() && p1->getY() == p2->getY() && p1->getDom() == p2->getDom();
}

void CorrectitudTest::printVector(vector<Punto*> v){
	for(Punto * p : v){
		p->print();
		cout << " - ";
	}
}

void CorrectitudTest::printArray(Punto ** dataset){
	int i = 0;
	while(!(dataset[i]->getX() == -1 && dataset[i]->getY() == -1)){
		dataset[i]->print();
		cout << " - ";
		i++;
	}
}

uint CorrectitudTest::naiveCount(Rectangulo * r){
	int total = 0;
	int i = 0;
	while(!(dataset[i]->getX() == -1 && dataset[i]->getY() == -1)){
		if(r->isPointInside(dataset[i])){
			total++;

		}
		i++;
	}
	
	return total;
	
	
}


// ./mainCorrectitudTest 
int main(int argc, char * argv[]){
	CorrectitudTest * a = new CorrectitudTest();
	cout << "SKYLINE: \n\n";
	//a->skylineTests();
	cout << "\nRANGUE COUNT: \n\n";
	//a->countTests();
	cout << "ENUMERATING \n\n";
	a->enumeratingTests();
	cout << "\nLISTO \n";
	
}
