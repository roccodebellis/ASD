/*
 * liste.h
 *
 *  Created on: 27/gen/2017
 *      Author: evil
 */

#ifndef LISTE_H_
#define LISTE_H_
#include <iostream>
#include <stdexcept>
using std::out_of_range;
using std::cout;
using std::endl;
using std::ostream;

// classe astratta listaLinare
template< class T, class P >
class List{
 public:
	typedef T value_type;
	typedef P position;

	// operators
	virtual ~List(){};
	virtual void crea_lista()=0;
	virtual bool lista_vuota() const=0;
	virtual value_type leggi_lista(position) const=0;
	virtual void scrivi_lista(const value_type &, position)=0;
	virtual position primo_lista() const=0;
	virtual bool fine_lista(position) const=0;
	virtual position succ_lista(position) const=0;
	virtual position prec_lista(position) const=0;
	virtual void ins_lista(const value_type &, position)=0;
	virtual void canc_lista(position)=0;




};


template< class T, class P >
ostream& operator<<(ostream& os, const List<T,P> &l){
	typename List<T,P>::position p;
	p = l.primo_lista();
	cout << "[";

	while (!l.fine_lista(p)){
		if (p != l.primo_lista())
			cout << ", " << l.leggi_lista(p);
		else
			cout << l.leggi_lista(p);
		p = l.succ_lista(p);

	}
	cout << "]" << endl;
	return os;
}




#endif /* LISTE_H_ */
