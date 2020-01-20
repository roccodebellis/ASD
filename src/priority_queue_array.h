#ifndef PRIORITY_QUEUE_ARRAY_H_
#define PRIORITY_QUEUE_ARRAY_H_

#include "priority_queue.h"
#include "exceptions.h"
#include <iostream>

#define MAX_DIMENSION 10;

template <class T>
class priority_queue_array : public priority_queue<T> {
public:
	typedef typename priority_queue<T>::value_type value_type;

	//constructors
	priority_queue_array();
	priority_queue_array(int);

	//copy constructor
	priority_queue_array(const priority_queue_array<value_type> &);

	//destructor
	~priority_queue_array();

	//operators
	void create();
	bool empty() const;
	void insert(value_type);
	value_type min() const;
	void remove_min();

	priority_queue_array<T> & operator=(const priority_queue_array<T> &);

	template <class K>
	friend std::ostream & operator<<(std::ostream &, const priority_queue_array<K> &);

	//service functions
	const void print();
private:
	value_type * _heap;
	int _last;
	int _max_length;

	//private service functions
	void change_dimension_(int);
	void fix_up_();
	void fix_down_(int, int);
};

template <class T>
priority_queue_array<T>::priority_queue_array() {
	_max_length = MAX_DIMENSION;
	create();
}

template <class T>
priority_queue_array<T>::priority_queue_array(int max_length) : _max_length(max_length) {
	create();
}

template <class T>
priority_queue_array<T>::priority_queue_array(const priority_queue_array<value_type> & copy_pqueue) {
	_max_length = copy_pqueue._max_length;
	create();
	_last = copy_pqueue._last;
	for(int i=0; i<_last; i++) //TODO check if is i<_max_length
		_heap[i] = copy_pqueue._heap[i];
}

template <class T>
priority_queue_array<T>::~priority_queue_array() {
	delete[] _heap;
}

template <class T>
void priority_queue_array<T>::create(){
	_heap = new value_type[_max_length];
	_last = 0;
}

template <class T>
bool priority_queue_array<T>::empty() const {
	return (_last==0);
}

template <class T>
void priority_queue_array<T>::insert(value_type e){
	if(_last >= _max_length)
		change_dimension_(_max_length++);
	_heap[_last++] = e; //copia il nuovo valore e dopo incrementa last
	fix_up_();
}

template <class T>
typename priority_queue_array<T>::value_type priority_queue_array<T>::min() const{
	if(_last == 0)
		throw empty_queue();
	return (_heap[0]);
}

template <class T>
void priority_queue_array<T>::remove_min(){
	if(_last == 0)
		throw empty_queue();
	_heap[0] = _heap[_last-1]; //copia li valore dell'ultima foglia nella radice
	_last--;
	fix_down_(1,_last); //fai scendere verso il basso
}

template <class T>
priority_queue_array<T> & priority_queue_array<T>::operator=(const priority_queue_array<T> & q){
	if(this==&q)
		return *this;
	if(_max_length != q._max_length){
		delete[] _heap;
		_max_length = q._max_length;
		_heap=new value_type[_max_length];
	}
	_last=q._last;

	for(int i=0; i<_last; i++)
		_heap[i] = q._heap[i];
	return *this;
}

template <class K>
std::ostream & operator<<(std::ostream & os, const priority_queue_array<K> & q) {
	os << "|";
	for(int i=0; i<q._last; i++)
		os << q._heap[i] << "|";
	os << std::endl;
	return os;
}

template <class T>
const void priority_queue_array<T>::print(){
	std::cout << "[";
	for(int i=0; i<_last; i++){
		std::cout << _heap[i];
		if(i != _last-1)
			std::cout << ",";
	}
	std::cout << "]" << std::endl;

}

template <class T>
void priority_queue_array<T>::change_dimension_(int new_dimension){
	if(new_dimension > _max_length){
		value_type * tmp_queue = new value_type[new_dimension];
		for(int i=0; i<_last; i++)
			tmp_queue[i] = _heap[i];
		_max_length = new_dimension;
		delete[] _heap;
		_heap = tmp_queue;
	}
}

/* Per ripristinare i vincoli dello heap quando la priorità di un nodo è      *
 * cresciuta, ci spostiamo nello heap verso l'alto, scambiando, se necessario,*
 * il nodo in posizione k con il suo nodo padre (in posizione k/2),           *
 * continuando fintanto che heap[k]<heap[k/2] oppure fino a quando            *
 * raggiungiamo la cima dello heap.                                           */
template <class T>
void priority_queue_array<T>::fix_up_(){
	int k = _last;
	while(k > 1 && _heap[k-1] < _heap[k/2-1]){
		value_type tmp = _heap[k-1];
		_heap[k-1] = _heap[k/2-1];
		_heap[k/2-1] = tmp;
		k = (int) k/2;
	}
}

/* Per ripristinare i vincoli dello heap quando la priorità di un nodo si è   *
 * ridotta, ci spostiamo nello heap verso il basso, scambiando, se necessario,*
 * il nodo in posizione k con il minore dei suoi nodi figli e arrestandoci    *
 * quando il nodo al posto k non è più grande di almeno uno dei suoi figli    *
 * oppure quando raggiungiamo il fondo dello heap. Si noti che se N è pari e  *
 * k è N/2, allora il nodo in posizione k ha un solo figlio: questo caso      *
 * particolare deve essere trattato in modo appropriato.                      */
template <class T>
void priority_queue_array<T>::fix_down_(int k, int N){
	bool swap = 1;
	while(k <= N/2 && swap){
		int j = 2*k;
		value_type tmp;
		if(j < N && _heap[j-1] > _heap[j])
			j++;
		swap = (_heap[j-1] < _heap[k-1]);
		if(swap){
			tmp = _heap[k-1];
			_heap[k-1] = _heap[j-1];
			_heap[j-1] = tmp;
			k = j;
		}
	}

}

#endif /* PRIORITY_QUEUE_ARRAY_H_ */
