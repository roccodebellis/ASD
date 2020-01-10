/*
 * stack_pointer.h
 *
 *  Created on: Jan 3, 2020
 *      Author: roccodebellis
 */

#ifndef STACK_POINTER_H_
#define STACK_POINTER_H_

#import <iostream>
#include "stack.h"
#include "node.h"
#include "exceptions.h"

template <class T>
class stack_pointer : public stack<T> {
public:
	typedef typename stack<T>::value_type value_type;

	//constructor
	stack_pointer();

	//copy constructor
	stack_pointer(const stack_pointer<value_type>&);

	//destructor
	~stack_pointer();

	//operators
	void create();
	bool empty() const;
	value_type top() const;
	void pop();
	void push(const value_type);

	//service functions
	void print() const;

	stack_pointer<T>& operator=(const stack_pointer<T>&);

	template <class U>
	friend std::ostream &operator<<(std::ostream &os, const stack_pointer<U> &s);

private:
	node<value_type>* head;
};

template <class T>
stack_pointer<T>::stack_pointer(){
	head = new node<value_type>;
	create();
}

template <class T>
stack_pointer<T>::stack_pointer(const stack_pointer<value_type>& copy_stack){
	node<value_type>* c;
	node<value_type>* curr;
	node<value_type>* prec;

	head = new node<value_type>;
	create();
	prec = head;

	for(c=copy_stack.head->get_next(); c!=nullptr; c=c->get_next()){
		curr = new node<value_type>;
		prec->set_next(curr);
		curr->set_value(c->get_value());
		curr-> set_next(nullptr);
		prec = prec->get_next();
	}
}

template <class T>
stack_pointer<T>::~stack_pointer(){
	node<value_type>* c;
	node<value_type>* curr;
	c = head;
	curr = head;
	while(curr!=nullptr){
		c = curr->get_next();
		delete curr;
		curr = c;
	}
}

template <class T>
void stack_pointer<T>::create(){
	head->set_next(nullptr);
	return;
}

template <class T>
bool stack_pointer<T>::empty() const{
	return (!head->get_next()) ? true : false;
}

template <class T>
typename stack_pointer<T>::value_type stack_pointer<T>::top() const{
	return (head->get_next()) ? head->get_next()->get_value() : throw empty_stack(); //TODO !=NULL
}

template <class T>
void stack_pointer<T>::pop() {
	(head->get_next()) ? head->set_next(head->get_next()->get_next()) : throw empty_stack();//TODO !=NULL
	return;
}

template <class T>
void stack_pointer<T>::push(const value_type elem){
	node<value_type>* curr;
	curr = new node<value_type>;
	curr->set_value(elem);
	curr->set_next(head->get_next());
	head->set_next(curr);
	return;
}

template <class T>
void stack_pointer<T>::print() const {
	std::cout << "Index\tValue" << std::endl;
	for(node<value_type>* i = head->get_next(); i!= nullptr; i=i->get_next())
		std::cout << i << "\t" << i->get_value() << std::endl;
	return;
}

template <class T>
stack_pointer<T>& stack_pointer<T>::operator=(const stack_pointer<T>& s){
	if(this==&s) return *this;

	if(!s.empty()){
		this->~stack_pointer();

		head = new node<value_type>;
		create(); //operazione inutile

		node<T>* tmp = s.head->get_next();

		node<value_type>* curr = new node<value_type>;
		head->set_next(curr);

		while(tmp){
			curr->set_value(tmp->get_value());
			if(tmp->get_next()){
				node<value_type>* next = new node<value_type>;
				curr->set_next(next);
				curr = next;
			}
			tmp = tmp->get_next();
		}
	} else throw empty_stack();

	return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const stack_pointer<T>& s){
	node<T>* tmp = s.head->get_next();
	os << "^[";
	while(tmp){
		os << *tmp;
		tmp = tmp->get_next();
		if(tmp)
			os << ", ";

	}
	os << "]";
	return os;
}

#endif /* STACK_POINTER_H_ */
