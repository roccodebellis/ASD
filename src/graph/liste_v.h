/*
 * liste_v.h
 *
 *  Created on: 27/gen/2017
 *      Author: evil
 */

#ifndef LISTE_V_H_
#define LISTE_V_H_
#include <iostream>

#include "liste.h"


template< class T >
class List_vector : public List<T, int>{
 public:
	typedef typename List<T, int>::value_type value_type;
	typedef typename List<T, int>::position position;

	// costruttori
	List_vector();
	List_vector(int);
	// costruttore per copia
	List_vector(const List_vector<T>& );
	//distruttore
	~List_vector();

	// operatori
	void crea_lista();
	bool lista_vuota() const;
	value_type leggi_lista(position) const;
	void scrivi_lista(const value_type &, position);
	position primo_lista() const;
	bool fine_lista(position) const;
	position succ_lista(position) const;
	position prec_lista(position) const;
	void ins_lista(const value_type &, position);
	void canc_lista(position);

	// sovraccarico di operatori
	List_vector<T>& operator=(const List_vector<T>&);
	bool operator==(const List_vector<T> &) const;
	bool operator!=(const List_vector<T> &) const;

 private:
	void change_dimension_(T*& , int , int );
	value_type* elements_;
	int length_; // the length of the list
	int array_dimension_; // array's dimension
};

// costruttore
template< class T >
List_vector< T >::List_vector() {
  array_dimension_ = 10;
  this->crea_lista();
}

// costruttore
template< class T >
List_vector< T >::List_vector(int dim){
  array_dimension_ = dim;
  this->crea_lista();
}

//costruttore di copia
template< class T >
List_vector< T >::List_vector(const List_vector<T>& Lista) {
  this->array_dimension_ = Lista.array_dimension_;
  this->length_ = Lista.length_;
  this->elements_ = new T[array_dimension_];
  for (int i=0; i<Lista.array_dimension_; i++)
     this->elements_[i] = Lista.elements_[i];
}

// distruttore
template< class T >
List_vector< T >::~List_vector(){
	delete elements_;
}

// operatori
template< class T >
void List_vector< T >::crea_lista(){
  this->elements_ = new T[array_dimension_];
  this->length_ = 0;
}

template< class T >
bool List_vector< T >::lista_vuota() const {
    return(length_ == 0);
}

template< class T >
typename List_vector< T >::position List_vector< T >::primo_lista() const {
	return(1);
}

template< class T >
typename List_vector< T >::position List_vector< T >::succ_lista(position p) const {
	if ( (0 < p) && (p < length_+1))
		return(p+1);
	else
		return(p);
}

template< class T >
typename List_vector< T >::position List_vector< T >::prec_lista(position p) const {
	if ( (1 < p) && (p < length_+1))
		return(p-1);
	else
		return(p);
}

template< class T >
bool List_vector< T >::fine_lista(position p) const {
	if ( (0 < p) && (p <= length_+1))
		return( p == length_+1);
	else
		return(false);
}

template< class T >
typename List_vector< T >::value_type List_vector< T >::leggi_lista(position p) const {
	if ( (0 < p) && (p < length_+1)){
		return(elements_[p-1]);
    }else{
        throw out_of_range("Error: Lettura fuori intervallo");
    }
}

template< class T >
void List_vector< T >::scrivi_lista(const value_type &a, position p) {
    if ( (0 < p) && (p < length_+1)){
        elements_[p-1] = a;
    }else{
        throw out_of_range("Error: Scrittura fuori intervallo");

    }

}

template< class T >
void List_vector< T >::ins_lista(const value_type &a, position p){
    if (length_ == array_dimension_){
        change_dimension_(elements_, array_dimension_, array_dimension_ * 2);
        array_dimension_ = array_dimension_ * 2;
    }
    if ( (0 < p) && (p <= length_+1)) {
		for (int i=length_; i>=p; i--)
			elements_[i] = elements_[i-1];
		elements_[p-1]=a;
		length_++;
    }else{
       throw out_of_range("Error: Inserimento fuori intervallo.");
	}
}

template< class T >
void List_vector< T >::canc_lista(position p){
    if ( (0 < p) && ( p < length_ + 1)){
        if (!lista_vuota()) {
			for (int i=p-1;i<(length_-1);i++)
				elements_[i]=elements_[i+1];
			length_--;
		}
    }else{
        throw out_of_range("Error: Cancellazione di un elemento inesistente.");
    }

}

template<class T>
void List_vector< T >::change_dimension_(T*& a, int vecchiaDim, int nuovaDim){

  T* temp = new T[nuovaDim];
  int number;
  if (vecchiaDim < nuovaDim)
     number = vecchiaDim;
  else
     number = nuovaDim;
  for (int i=0; i<number; i++)
     temp[i]=a[i];
  delete [] a;
  a = temp;
}

/* operatore di assegnamento */
template<class T>
List_vector<T>& List_vector<T>::operator=(const List_vector<T>& l){
	if (this != &l){
		this->array_dimension_ = l.array_dimension_;
		this->length_ = l.length_;
		delete this->elements_;
		this->elements_ = new T[array_dimension_];
		for (int i=0; i<l.array_dimension_; i++)
			this->elements_[i] = l.elements_[i];
	}
	return *this;
}

/* operatore di test di uguaglianza */
template<class T>
bool List_vector<T>::operator==(const List_vector<T> &l) const{
	if (l.length_ != this->length_)
		return false;
  for (int i=0; i<this->array_dimension_; i++)
		if (this->elements_[i] != l.elements_[i])
			return false;
	return true;
}

template<class T>
bool List_vector<T>::operator!=(const List_vector<T> &l) const{
	if (l.length_ != this->length_)
		return true;
  for (int i=0; i<this->array_dimension_; i++)
		if (this->elements_[i] != l.elements_[i])
			return true;
	return false;
}





#endif /* LISTE_V_H_ */
