#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

#include <iostream>
#include "queue.h"
#include "exceptions.h"

const int MAX_DIMENSION = 10;

template <class T>
class queue_array : public queue<T> {
	//friend bool operator==(const queue<T>& x, const queue<T>& y); //TODO
	//friend bool operator<(const queue<T>& x, const queue<T>& y);  //TODO

public:
	typedef typename queue<T>::value_type value_type;

	//constructors
	queue_array();
	queue_array(int);

	//copy constructor
	queue_array(const queue_array<value_type> &);

	//destructor
	~queue_array();

	//operators
	void create();
	bool empty() const;
	value_type top() const;
	void dequeue();
	void enqueue(const value_type);

	//service function
	void print() const;

	queue_array<T>& operator=(const queue_array<T> &);
	//queue_array<value_type>& operator=(const queue_array<value_type> &);

	template <class U>
	friend std::ostream & operator<<(std::ostream &, const queue_array<U> &);

private:
	value_type* elements;
	int max_dimension, length, head;

	//private service funzions
	void change_dimension(const int);
};

template <class T>
queue_array<T>::queue_array(){
	max_dimension = MAX_DIMENSION;
	create();
}

template <class T>
queue_array<T>::queue_array(int dim){
	max_dimension = dim;
	create();
}

template <class T>
queue_array<T>::queue_array(const queue_array<value_type> & queue_copy){
	max_dimension = queue_copy.max_dimension;
	create();
	length = queue_copy.length;
	head = queue_copy.head;

	for(int i=head; i<length; i++)
		elements[i] = queue_copy.elements[i];
}

template <class T>
queue_array<T>::~queue_array(){
	delete[] elements;
}

template <class T>
void queue_array<T>::create(){
	elements = new value_type[max_dimension];
	length = 0;
	head = 0;
	return;
}

template <class T>
bool queue_array<T>::empty() const {
	return (length==0);
}

template <class T>
typename queue_array<T>::value_type queue_array<T>::top() const {
	if(!empty())
		return (elements[head]);
	else
		throw empty_queue();
}

template <class T>
void queue_array<T>::dequeue(){
	if(!empty()){
		head = (head+1) % max_dimension; //TODO WHATTTTTT ????????????
		length--;
	} else
		throw empty_queue();
}

template <class T>
void queue_array<T>::enqueue(const value_type element){
	if(length == max_dimension)
		change_dimension(max_dimension++);
	elements[(head+length) % max_dimension] = element;
	length++;
	return;
}

template <class T>
void queue_array<T>::print() const {
	std::cout<< "Index\tValue" <<std::endl;
	for(int i=length-1;i>=0;i--)
		std::cout << length-1-i << "\t" << elements[(i+head) % max_dimension] << std::endl;
	return;
}

template <class T>
void queue_array<T>::change_dimension(int new_dimension){
	if(new_dimension > max_dimension){
		max_dimension = new_dimension;
		value_type* tmp = new value_type[new_dimension];
		for(int i=0; i<length; i++)
			tmp[i] = elements[i];
		delete[] elements;
		elements = tmp;
	}
	return;
}

template <class T>
queue_array<T>& queue_array<T>::operator=(const queue_array<T> & q){
	//TODO: secondo me è da migliorare
	//posso semplicemente chiamare il costruttuore per copia ed ottenere lo stesso risultato
	if(this==&q) return *this;

	if(max_dimension != q.max_dimension){
		this->~queue_array();
		max_dimension = q.max_dimension;
		elements = new value_type[max_dimension];
	}

	head = q.head;
	length = q.length;

	for(int i=head; i<length; i++)
		elements[i] = q.elements[i];
	return *this;
}

template <class T>
std::ostream & operator<<(std::ostream & os, const queue_array<T> & q){
	os << "H:" <<q.head << " L:" << q.length << " M:" << q.max_dimension << " "; //TODO DELETE
	os << "[";
	for(int i=0; i<q.length; i++){
		os << q.elements[(q.head+i) % q.max_dimension] << "[" << &(q.elements[(q.head+i) % q.max_dimension])  << "]";
		if(i<q.length-1)
			os << ", ";
	}
	os << "]";
	return os;
}

#endif /* QUEUE_ARRAY_H_ */
