#include <iostream>
#include <vector> 
#include <string>

#include "SkylineBBSk.h"
#include "SkylineX.h"
#include "SkylineIngenuo.h"
#include "Transformador.h"
#include "kTree.h"

using namespace std;

class StaticTest{
public:
	StaticTest();
	~StaticTest();
	void doStaticsTest();
private:
	Transformador * trans;
	void doAStaticTest(char *  nombre);
	void testBBS(MREP * rep);
	void testX(MREP * rep);
	void testIngenuo(Punto ** lista);
};

StaticTest::StaticTest(){
	trans = new Transformador();
}

StaticTest::~StaticTest(){
	
}

/*Calcula el Skyline con los archivos predefinidos existentes*/
void StaticTest::doStaticsTest(){
	cout << "\nTEST 1\n";
    doAStaticTest("test1");
	cout << "\nTEST 1_1\n";
	doAStaticTest("test1_1");
	cout << "\nTEST 2\n";
	doAStaticTest("test2");
	cout << "\nTEST 3\n";
	doAStaticTest("test3");
	cout << "\nTEST 4\n";
	doAStaticTest("test4");
	cout << "\nTEST 5\n";
	doAStaticTest("test5");
	cout << "\nTEST 6\n";
	doAStaticTest("test6");
	cout << "\nTEST 7\n";
	doAStaticTest("test7");
	cout << "\nTEST 8\n";
	doAStaticTest("test8");
}

/*Calcula el Skyline con los 3 algoritmos existentes y los datos predefinidos*/
void StaticTest::doAStaticTest(char * nombre){
	string path = "static_test/";
	path += nombre;
	char * addr= new char[128];
	strcpy(addr,path.c_str());
	Punto ** dataset = trans->readListPoint(addr);
	ALREP * listaAdyacencia = trans->fromListPointToAdList(dataset);
	MREP * ktree = trans->fromAdListToKtree(listaAdyacencia);
	
	testIngenuo(dataset);
	testBBS(ktree);
	testX(ktree);
}

/*Calcula el Skyline BBS*/
void StaticTest::testBBS(MREP * rep){
    SkylineBBSk * myk = new SkylineBBSk();
    vector<Punto*> skyline = myk->calculeSkyline(rep, MANEHATTAN);
    cout << "Resultados de la consulta SkylineBBSk: \n";
    for(Punto * p : skyline){
        p->print();
        cout << "\n";
    }
}

/*Calcula el Skyline X*/
void StaticTest::testX(MREP * rep){
    SkylineX * myk = new SkylineX();
    vector<Punto*> skyline = myk->calculeSkyline(rep);
    cout << "Resultados de la consulta SkylineX: \n";
    for(Punto * p : skyline){
        p->print();
        cout << "\n";
    }
}

/*Calcula el Skyline ingenuo*/
void StaticTest::testIngenuo(Punto ** lista){
    SkylineIngenuo * myk = new SkylineIngenuo();
    vector<Punto*> skyline = myk->calculeSkyline(lista);
    cout << "Resultados de la consulta Skyline Ingenuo: \n";
    for(Punto * p : skyline){
        p->print();
        cout << "\n";
    }
}

int main(){
	StaticTest * st = new StaticTest();
	st->doStaticsTest();
}