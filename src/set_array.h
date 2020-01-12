#ifndef SET_ARRAY_H_
#define SET_ARRAY_H_

const int MAX_DIMENSION = 10;

#include "set.h"
#include <iostream>
#include "exceptions.h"

template <class T>
class set_array : public set<T> {
public:
	typedef typename set<T>::value_type value_type;

	//constructor
	set_array();
	set_array(int);

	//copy constructor
	set_array(const set_array<value_type> &);

	//destructor
	~set_array();

	//operators
	void create();
	bool empty() const;
	bool contains(const value_type) const;
	void insert(const value_type);
	void remove(const value_type);
	set_array<value_type> uni(const set_array<value_type> &) const; //set_array<U> union(const set_array<U> &);
	set_array<value_type> intersection(const set_array<value_type> &) const;
	set_array<value_type> difference(const set_array<value_type> &) const;

	//service function
	template <class U>
	friend std::ostream & operator<<(std::ostream &, const set_array<U> &);

private:
	bool * elements;
	int max_dimension;

	//private service functions
	void change_dimension(const int);
};

template <class T>
set_array<T>::set_array(){
	max_dimension = MAX_DIMENSION;
	create();
}

template <class T>
set_array<T>::set_array(int dimension){
	max_dimension = dimension;
	create();
}

template <class T>
set_array<T>::set_array(const set_array<value_type> & set_copy) {
	max_dimension = set_copy.max_dimension;
	create();
	for(int i=0; i<max_dimension; i++)
		elements[i] = set_copy.elements[i];
}

template <class T>
set_array<T>::~set_array() {
	delete[] elements;
}

template <class T>
void set_array<T>::create() {
	elements = new bool[max_dimension];
	for(int i=0; i<max_dimension; i++)
		elements[i] = false;
}

template <class T>
bool set_array<T>::empty() const {
	for(int i=0; i<max_dimension; i++)
		if(elements[i]) return false;
	return true;
}

template <class T>
bool set_array<T>::contains(const value_type value) const {
	if(value < max_dimension)
		return elements[value];
	else throw illegalParameterValue("out of bound");
}

template <class T>
void set_array<T>::insert(const value_type value) {
	if(value>=max_dimension)
		change_dimension(value + 1);
	elements[value] = true;
	return;
}

template <class T>
void set_array<T>::remove(const value_type value) {
	if(value < max_dimension)
		elements[value] = false;
	else throw illegalParameterValue("out of bound");
	return;
}

template <class T>
set_array<typename set<T>::value_type> set_array<T>::uni(const set_array<value_type> & set_b) const {
	if(max_dimension < set_b.max_dimension)
		return set_b.uni(*this);
	else {
		set_array<value_type> set_c(max_dimension);
		int i = 0;
		while(i < set_b.max_dimension){
			set_c.elements[i] = elements[i] || set_b.elements[i]; i++;
		}
		while(i < max_dimension){
			set_c.elements[i] = elements[i]; i++;
		}
		return set_c;
	}
}

template <class T>
set_array<typename set<T>::value_type> set_array<T>::intersection(const set_array<value_type> & set_b) const {
	int card = (max_dimension < set_b.max_dimension) ? max_dimension : set_b.max_dimension;
	set_array<value_type> set_c(card);
	for(int i=0; i<card; i++)
		set_c.elements[i] = elements[i] && set_b.elements[i];
	return set_c;
}

template <class T>//TODO testare con insiemi di grandezze differenti
set_array<typename set<T>::value_type> set_array<T>::difference(const set_array<value_type> & set_b) const {
	set_array<value_type> set_c(max_dimension);
	for(int i=0; i<max_dimension; i++)
		set_c.elements[i] = (set_b.max_dimension>=i) ? (elements[i] && !set_b.elements[i]) : elements[i];
	return set_c;
}

template <class T>
std::ostream & operator<<(std::ostream & os, const set_array<T> & set) {
	os << "( ";
	for (int i=0; i<set.max_dimension; i++){
		int curr = set.elements[i];
		if(curr)
			os << i << " ";
	}
	os << ")";
	return os;
}

template <class T>
void set_array<T>::change_dimension(int new_dimension){
	if(new_dimension > max_dimension){
		bool * tmp = new bool[new_dimension];
		for(int i=0; i<max_dimension; i++)
			tmp[i] = elements[i];
		delete[] elements;
		elements = tmp;
		max_dimension = new_dimension;
	}
}

#endif /* SET_ARRAY_H_ */
