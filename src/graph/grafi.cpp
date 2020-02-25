//============================================================================
// Name        : grafi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "grafo_mat.h"
#include <string>

using namespace std;

int main(void) {

	GrafoMat<string,double> G(10);
	NodoG n1,n2,n3,n4,n5,n6;

	G.insNodo(n1);
	G.scriviEtichetta(n1,"1");
	G.insNodo(n2);
	G.scriviEtichetta(n2,"2");
	G.insNodo(n3);
	G.scriviEtichetta(n3,"3");
	G.insNodo(n4);
	G.scriviEtichetta(n4,"4");
	//G.insNodo(n5);
	//G.scriviEtichetta(n5,"e");
	//G.insNodo(n6);
	//G.scriviEtichetta(n6,"f");



	G.insArco(n1,n2, 1.0);
	G.insArco(n3,n2, 0.9);
	G.insArco(n1,n3, 0.3);
	G.insArco(n3,n3, 0.1);
	G.insArco(n2,n4, 0.2);
	G.insArco(n4,n2, 1.0);

	//G.insArco(n4,n1, 0.5);
	//G.insArco(n5,n2, 0.4);
	//G.insArco(n5,n3, 0.2);
    g.

	cout << "\nNumNodi " << G.numNodi();
	cout << "\nNumArchi " << G.numArchi();

	G.cancNodo(n6);

	cout << "\nNumNodi " << G.numNodi() << endl;


	//int x;
	//cin>>x;
    //return 0;

}
