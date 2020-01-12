#ifndef QUEUE_POINTER_H_
#define QUEUE_POINTER_H_

//#define NULL 0
//#define NULL nullptr
#include <iostream>
#include "queue.h"
#include "exceptions.h"
#include "node.h"


template <class T>
class queue_pointer : public queue<T> {
public:
	typedef typename queue<T>::value_type value_type;

	//constructors
	queue_pointer();

	//copy constructor
	queue_pointer(const queue_pointer<value_type> &);

	//destructor
	~queue_pointer();

	//operators
	void create();
	bool empty() const;
	value_type top() const;
	void dequeue();
	void enqueue(const value_type);

	//service function

	//queue_array<T>& operator=(const queue_array<T> &); //Utilizzo quello implementato dal compilatore

	template <class U>
	friend std::ostream & operator<<(std::ostream &, const queue_pointer<U> &);

private:
	node<value_type> * head;
	node<value_type> * tail;
};

template <class T>
queue_pointer<T>::queue_pointer() {
	head = new node<value_type>;
	tail = new node<value_type>;
	create();
}

template <class T> //TODO da implementare
queue_pointer<T>::queue_pointer(const queue_pointer<value_type> & queue_copy) {
	//head = new node<value_type>:
	//				tail = new node<value_type>:
	//				create();

}

template <class T>
queue_pointer<T>::~queue_pointer() {
	while(!empty())
		dequeue();
	head->set_next(nullptr);
	//tail->set_next(nullptr);
	return;
}

//create testa puntatore head null
template <class T>
void queue_pointer<T>::create() {
	head = nullptr;//head->set_next(nullptr);
	//tail->set_next(nullptr);
	return;
}

//empty puntatore testa nullo
template <class T>
bool queue_pointer<T>::empty() const {
	return (head==nullptr) ? true : false; //==nullptr
}

template <class T> //TODO da rivedere
typename queue_pointer<T>::value_type queue_pointer<T>::top() const {
	if(!empty())
		return head->get_next()->get_value(); // todo modificato
	else
		throw empty_queue();
}

template <class T> //TODO da rivedere
void queue_pointer<T>::dequeue() {
	if(!empty())
		if(!head->get_next()){
			delete head;
			create();
		} else {
			node<value_type> * tmp = head->get_next();
			delete head;
			head = tmp;
		}
	else
		throw empty_queue();
}

template <class T> //TODO da rivedere
void queue_pointer<T>::enqueue(const value_type element) {
	//std::cout << "enqueue("<< element << "):" ; //TODO del
	node<value_type> * new_node = new node<value_type>;
	new_node->set_value(element);
	if(empty()){
		head = new_node;//head->set_next(new_node);
		tail = new_node;
	} else
		tail->set_next(new_node);
	tail = new_node;
	//std::cout << " new_node-"<< new_node << " ("<< new_node->get_value()<<")"<<std::endl  ;
	//std::cout << "\thead-"<< head << " tail-" << tail <<std::endl ;
}

template <class T>
std::ostream & operator<<(std::ostream & os, const queue_pointer<T> & q) {
	os << "[";
	node<T>* it = q.head;
	while(it){
		os << it->get_value();//     << "-" << it << " next-" << it->get_next();
		if(it->get_next())
			os << ", ";//os  <<",\n\t";
		it = it->get_next();
	}
	os << "]";
	return os;
}

#endif /* QUEUE_POINTER_H_ */
