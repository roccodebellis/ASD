#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>
//#define NULL 0
//#define NULL nullptr

template <class T>
class node{
public:
	//constructor
	node();

	//copy constructor
	node(const node<T>&);

	//desctructor
	~node();

	//operators
	void set_value(T);
	T get_value() const;
	void set_next(node<T>*);
	node<T>* get_next() const;

	//service functions
	//TODO: implementare bool operator ==(Nodo &)
	/* bool Nodo::operator==(Nodo & n){
	 * 		return(get_value()==n.get_value());
	 * }
	 */

	template <class K>
	friend std::ostream & operator<<(std::ostream &, const node<K> & s);

private:
	T value;
	node<T>* next;
};

template <class T>
node<T>::node(){
	next = nullptr;
	//value = NULL; // TODO: in tutte le realizzazioni non c'èera

}

template <class T>
node<T>::node(const node<T>& copy_node){
	value = copy_node.value;
	next = copy_node.next;
}

template <class T>
node<T>::~node(){}

template <class T>
void node<T>::set_value(T elem){
	value = elem;
	return;
}

template <class T>
T node<T>::get_value() const{
	return value;
}

template <class T>
void node<T>::set_next(node<T>* n){
	next = n;
	return;
}

template <class T>
node<T>* node<T>::get_next() const{
	return next;
}

template <class T>
std::ostream & operator<<(std::ostream & os, const node<T> & n){
	return os << n.get_value();
	//return os << "("<<n.get_value() << ": "<<n.get_next() <<")"; //TODO: ripristinare sopra
}

#endif /* NODE_H_ */
