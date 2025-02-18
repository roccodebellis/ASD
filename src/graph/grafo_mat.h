/*
 * grafo_mat.h
 *
 *  Created on: 27/gen/2017
 *      Author: evil
 */

#ifndef GRAFO_MAT_H_
#define GRAFO_MAT_H_
#include "grafo.h"

template<class P>
class InfoArco {
 public:
	P peso;
	bool vuoto;

	InfoArco(){
		vuoto = true;
	}
};


template<class E, class P>
	class InfoNodo {
 public:
	E   etichetta;
	bool vuoto;
	void* info;
	InfoArco<P>* archi;

	InfoNodo(){
		info = 0;
		vuoto = true;
	}

	~InfoNodo(){
		if (!vuoto)
			delete [] archi;
	}
};


class NodoG{
 public:
	NodoG(int i){
		nodoId = i;
	}
	NodoG(){
	}
	int getId(){ return nodoId; }
	void setId(int id) {nodoId = id;}
 private:
	int nodoId;
};


template<class E, class P>
	class GrafoMat : public Grafo<E, P, NodoG > {
 public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco_<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
		typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoMat(int);
    ~GrafoMat();

    bool vuoto() const;
    void insNodo(NodoG&);
    void insArco(Nodo, Nodo, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);
		//    bool esisteNodo(Nodo);
		//    bool esisteArco(Arco);
    ListaNodi Adiacenti(Nodo) const ;
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;
    void scriviEtichetta(Nodo, Etichetta) ;
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;

		int numNodi(){
			return nodi;
		};
		int numArchi(){
			return archi;
		};


 private:
    InfoNodo<E,P>* matrice;
    int dimensione;
    int nodi;
	int archi;
};


template<class E, class P>
	GrafoMat<E, P>::GrafoMat(int _dimensione){
	dimensione = _dimensione;
	nodi = 0;
	archi = 0;
	matrice = new InfoNodo<E,P>[dimensione];
	for (int i=0; i<dimensione; i++)
		matrice[i].archi = new InfoArco<P>[dimensione];
}

template<class E, class P>
	GrafoMat<E, P>::~GrafoMat() {
	delete [] matrice;
}

template<class E, class P>
	bool GrafoMat<E, P>::vuoto() const {
	return (nodi == 0);
}

template<class E, class P>
	void GrafoMat<E, P>::insNodo(Nodo& N) {
	int n = 0;
	if (nodi < dimensione){
		while (matrice[n].vuoto == false)
			n++;
		nodi++;
		matrice[n].vuoto = false;
	}
	N.setId(n);
}

template<class E, class P>
	void GrafoMat<E, P>::insArco(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
	matrice[n1.getId()].archi[n2.getId()].vuoto = false;
	archi++;
}


template<class E, class P>
	void GrafoMat<E, P>::cancNodo(Nodo n) {
	bool canc = true;
	int i;
	for (i=0; i < dimensione && canc; i++){
		if (!matrice[n.getId()].archi[i].vuoto){
			canc = false;

		}
	}
	for (i=0; i < dimensione && canc; i++){
		if (!matrice[i].vuoto && !matrice[i].archi[n.getId()].vuoto){
			canc = false;

		}
	}
	if (canc){
		delete matrice[n.getId()].archi;
		matrice[n.getId()].vuoto = true;
		nodi--;
	}
}

template<class E, class P>
	void GrafoMat<E, P>::cancArco(Nodo n1, Nodo n2){
	matrice[n1.getId()].archi[n2.getId()].vuoto = true;
	archi--;
}

template<class E, class P>
	typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::Adiacenti(Nodo n) const{
	ListaNodi list;

	for (int i = 0; i < dimensione; i++) {
		if (!matrice[n.getId()].archi[i].vuoto) {
			list.ins_lista(new NodoG(i), list.primo_lista());
		}
	}
	return list;
}

template<class E, class P>
	typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::list_nodi() const {
	ListaNodi list;
	for (int i = 0; i < dimensione; i++)
		if (!matrice[i].vuoto)
			list.ins_lista(new NodoG(i), list.primo_lista());
	return list;
}

template<class E, class P>
	E GrafoMat<E, P>::leggiEtichetta(Nodo n) const {
	return matrice[n.getId()].etichetta;
}

template<class E, class P>
	void GrafoMat<E, P>::scriviEtichetta(Nodo n, E etichetta) {
	matrice[n.getId()].etichetta = etichetta;
}

template<class E, class P>
	P GrafoMat<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	return matrice[n1.getId()].archi[n2.getId()].peso;
}

template<class E, class P>
	void GrafoMat<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
}

#endif /* GRAFO_MAT_H_ */
