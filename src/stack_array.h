/*
 * stack_array.h
 *
 *  Created on: Jan 3, 2020
 *      Author: roccodebellis
 */

#ifndef STACK_ARRAY_H_
#define STACK_ARRAY_H_

#include <iostream>
#include "stack.h"
#include "exceptions.h"

const int MAX_DIMENSION = 10;

template <class T>
class stack_array : public stack<T> {
public:
	typedef typename stack<T>::value_type value_type;

	//constructors
	stack_array();
	stack_array(int);

	//copy constructor
	stack_array(const stack_array<value_type>&);

	//destructor
	~stack_array();

	//operators
	void create();
	bool empty() const;
	value_type top() const;
	void pop();
	void push(const value_type);

	//service functions
	void print() const;

	template <class U>
	friend std::ostream & operator<<(std::ostream &, const stack_array<U> &);

private:
	value_type* elements;
	int head;
	int max_dimension;

	//private service functions
	void change_dimension(const int);

};

template <class T>
stack_array<T>::stack_array(){
	max_dimension = MAX_DIMENSION;
	create();
}

template <class T>
stack_array<T>::stack_array(int dimension){
	max_dimension = dimension;
	create();
}

template <class T>
stack_array<T>::stack_array(const stack_array<value_type> & stack_copy){
	max_dimension = stack_copy.max_dimension;
	create();
	head = stack_copy.head;
	for(int i=0; i<head; i++)
		elements[i] = stack_copy.elements[i];
}

template <class T>
stack_array<T>::~stack_array(){
	delete[] elements;
}

template <class T>
void stack_array<T>::create(){
	elements = new value_type[max_dimension];
	head = 0;
	return;
}

template <class T>
bool stack_array<T>::empty() const {
	return head==0;
}

template <class T>
typename stack_array<T>::value_type stack_array<T>::top() const {
	if(head > 0)
		return elements[head-1];
	else
		throw empty_stack();
}

template <class T>
void stack_array<T>::pop(){
	if(head > 0)
		head--;
	else
		throw empty_stack();
	return;
}

template <class T>
void stack_array<T>::push(const value_type element){
	if(head == max_dimension)
		change_dimension(max_dimension*2); //TODO
	elements[head] = element;
	head++;
	return;
}

template <class T>
void stack_array<T>::print() const {
	std::cout << "Index\tValue" << std::endl;
	for(int i= head-1; i >= 0; i--)
		std::cout << i << "\t" << elements[i] << std::endl;
	return;
}

template <class T>
void stack_array<T>::change_dimension(const int new_dimension){
	if(new_dimension > max_dimension){
		max_dimension = new_dimension;
		value_type * temp = new value_type[new_dimension];
		for(int i=0; i<head; i++)
			temp[i] = elements[i];
		delete[] elements;
		elements = temp;
	}
	return;
}


template <class T>
std::ostream & operator<<(std::ostream & os, const stack_array<T> & s){
	os << "[";
	for (int i=s.head-1; i>=0; i--){
		os << s.elements[i];
		if(i != 0 )
			os << ", ";
	}
	os << "]";
	return os;
}

#endif /* STACK_ARRAY_H_ */
