#ifndef LISTE_P_H_
#define LISTE_P_H_

#include <stdexcept>
#include "linear_list.h"


//NOT TESTED - NOT TESTED - NOT TESTED - NOT TESTED - NOT TESTED


template <class T>
class Nodo
{
private:
	T valore;
	Nodo *succ, *prec;

public:
	Nodo();
	Nodo(const T& valore);
	T leggi_nodo()		{ return valore; }
	Nodo* succ_nodo()	{ return succ; }
	Nodo* prec_nodo()	{ return prec; }
	void scrivi_nodo(T d)		{ valore = d; }
	void cambia_succ(Nodo *n)	{ succ = n; }
	void cambia_prec(Nodo *p)	{ prec = p; }
};



template< class T >
class List_pointer : public linear_list<T, Nodo<T>*>{
public:
	typedef typename linear_list<T, Nodo<T>*>::value_type value_type;
	typedef typename linear_list<T, Nodo<T>*>::position position;

	// costruttori
	List_pointer();
	// costruttore per copia
	List_pointer(const List_pointer<T> & );
	//distruttore
	~List_pointer();

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const value_type &, position);
	void erase(position);

	// sovraccarico di operatori
	void operator=(const List_pointer<T>&);
	bool operator==(const List_pointer<T> &) const;
	bool operator!=(const List_pointer<T> &) const;

private:

	int lunghezza;
	position sentinella;
};

template <class T>
Nodo<T>::Nodo()
{
}


template <class T>
Nodo<T>::Nodo(const T& valore)
{
	this->valore = valore;

}

template <class T>
List_pointer<T>::List_pointer()
{
	create();
	this->lunghezza = 0;
}

template <class T>
List_pointer<T>::List_pointer(const List_pointer<T> &lista_copia)
{
	position tmp1;
	position tmp;
	tmp=lista_copia.begin();
	this->create();
	tmp1=this->begin();
	while(!lista_copia.end(tmp)){
		this->insert(lista_copia.read(tmp),tmp1);
		tmp=lista_copia.next(tmp);
		tmp1=this->next(tmp1);
	}
}

template <class T>
List_pointer<T>::~List_pointer()
{

	while (sentinella->succ_nodo() !=sentinella->prec_nodo()){
		erase(sentinella->succ_nodo());
	}

	delete sentinella;
}

template <class T>
void List_pointer<T>::create()
{
	value_type elemento;
	sentinella=new Nodo<T>;
	sentinella->scrivi_nodo(elemento);
	sentinella->cambia_succ(sentinella);
	sentinella->cambia_prec(sentinella);

}

template <class T>
bool List_pointer<T>::empty() const
{
	return((sentinella->succ_nodo()==sentinella)&&(sentinella->prec_nodo()==sentinella));

}

template <class T>
typename List_pointer<T>::position List_pointer<T>::begin() const
{
	return sentinella->succ_nodo();

}

template <class T>
typename List_pointer<T>::position List_pointer<T>::next(position p) const
{
	return p->succ_nodo();
}

template <class T>
typename List_pointer<T>::position List_pointer<T>::previous(position p) const
{
	return p->prec_nodo();
}

template <class T>
bool List_pointer<T>::end(position p) const
{
	return (p==sentinella);
}

template <class T>
typename List_pointer<T>::value_type List_pointer<T>::read(position p) const
{   if(p!=sentinella){
	return p->leggi_nodo();
}else{
	//throw out_of_range("Error: Lettura fuori intervallo");
}
}

template <class T>
void List_pointer<T>::write(const value_type &elem,position p)
{   if(p!=sentinella){
	p->scrivi_nodo(elem);
}else{
	//throw out_of_range("Error: Scrittura fuori intervallo");
}
}

template <class T>
void List_pointer<T>::insert(const value_type &elem,position p)
{

	position temp;
	temp=new Nodo<T>;
	temp->scrivi_nodo(elem);
	temp->cambia_prec(p->prec_nodo());
	temp->cambia_succ(p);
	(p->prec_nodo())->cambia_succ(temp);
	p->cambia_prec(temp);
	p=temp;
	lunghezza=lunghezza+1;


}

template <class T>
void List_pointer<T>::erase(position p)
{
	if(!end(p)){
		position temp;
		temp=p;
		(p->succ_nodo())->cambia_prec(p->prec_nodo());
		(p->prec_nodo())->cambia_succ(p->succ_nodo());
		p=p->succ_nodo();
		delete (temp);
	}else{

		//throw out_of_range("Error: Cancellazione di un elemento inesistente.");
	}
}

template <class T>
bool List_pointer<T>::operator==(const List_pointer<T> &l1) const
{

	if(this->lunghezza!=l1.lunghezza){

		return false;
	}else{
		position tmp1 = l1.begin();
		position tmp2 = this->begin();
		while ((!l1.end(tmp1)) && (!this->end(tmp2)))
		{
			if(this->read(tmp1)!=l1.read(tmp2)){
				return false;
			}
			tmp1=l1.next(tmp1);
			tmp2=this->next(tmp2);
		}

		return true;

	}



}

template <class T>
bool List_pointer<T>::operator!=(const List_pointer<T> &l1) const
{

	if(this->lunghezza!=l1.lunghezza){

		return true;
	}else{
		position tmp1 = l1.begin();
		position tmp2 = this->begin();
		int valori_corretti=0;
		while ((!l1.end(tmp1)) && (!this->end(tmp2)))
		{
			if(this->read(tmp1)!=l1.read(tmp2)){
				return true;
			}
			tmp1=l1.next(tmp1);
			tmp2=this->next(tmp2);
		}

		return false;

	}



}


template <class T>
void List_pointer<T>::operator=(const List_pointer<T> &l1)
{
	if((l1.lunghezza-this->lunghezza)<0){
		position tmp;
		position tmp1;
		tmp=l1.begin();
		tmp1=this->begin();
		while(!l1.end(tmp)){
			this->write(l1.read(tmp),tmp1);
			tmp=l1.next(tmp);
			tmp1=this->next(tmp1);
		}
		while(!this->end(tmp1)){
			this->erase(tmp1);
			tmp1=this->next(tmp1);
		}

	}else if(l1.lunghezza==this->lunghezza){
		position tmp;
		position tmp1;
		tmp=l1.begin();
		tmp1=this->begin();
		while(!l1.end(tmp)){
			this->write(l1.read(tmp),tmp1);
			tmp=l1.next(tmp);
			tmp1=this->next(tmp1);
		}
	}else if(this->lunghezza==0){
		position tmp;
		position tmp1;
		tmp=l1.begin();
		tmp1=this->begin();
		while(!l1.end(tmp)){
			this->insert(l1.read(tmp),tmp1);
			tmp=l1.next(tmp);
			tmp1=this->next(this->next(tmp1));
		}

	}else{
		position tmp;
		position tmp1;
		tmp=l1.begin();
		tmp1=this->begin();
		while(!this->end(tmp1)){
			this->write(l1.read(tmp),tmp1);
			tmp=l1.next(tmp);
			tmp1=this->next(tmp1);
		}
		while(!l1.end(tmp)){
			this->insert(l1.read(tmp),tmp1);
			tmp=l1.next(tmp);
			tmp1=this->next(tmp1);
		}


	}

}




#endif /* LISTE_P_H_ */
