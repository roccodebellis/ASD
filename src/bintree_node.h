#ifndef BINTREE_NODE_H_
#define BINTREE_NODE_H_

#include "exceptions.h"

//#define NULL 0
//#define nullptr NULL

template <class>
class bintree_list;

template<class T>
class bintree_node {
public:
	friend class bintree_list<T>;

	//constructors
	bintree_node();
	bintree_node(T);
	bintree_node(T, bintree_node<T> *);

	//copy constructors
	bintree_node(const bintree_node<T> &);

	//destructor
	~bintree_node();

	//operators
	T getData() const {
		return _data;
	}

	bintree_node<T> * getParent() const{
		return _parent;
	}

	bintree_node<T> * getLeft() const{
		return _left;
	}

	bintree_node<T> * getRight() const{
		return _right;
	}

	bintree_node<T> & operator=(const bintree_node<T> * &);//TODO: why *&

	template <class U>
	friend std::ostream & operator<<(std::ostream &, const bintree_node<U> &);

	//service function
	void clear();
	void insertLeft(const bintree_node<T> *, const T);
	void insertRight(const bintree_node<T> *, const T);
	void deleteLeft(bintree_node<T> *);
	void deleteRight(bintree_node<T> *);
	void insertLeftSub(const bintree_node<T> *, const bintree_node<T> *);
	void insertRightSub(const bintree_node<T> *, const bintree_node<T> *);


private:
	T _data;
	bintree_node<T> * _parent;
	bintree_node<T> * _left;
	bintree_node<T> * _right;

	void create();
	void remove(bintree_node<T> *);//FIXME remove_node()
	bintree_node<T> * copynode(const bintree_node<T> *, const bintree_node<T> *);
};

template <class T>
bintree_node<T>::bintree_node() {
	create();
}

template <class T>
bintree_node<T>::bintree_node(T data) : _data(data) {
	create();
}

template <class T>
bintree_node<T>::bintree_node(T data, bintree_node<T> * parent) : _data(data) {
	create();
	_parent = parent;
}

template <class T>
bintree_node<T>::bintree_node(const bintree_node<T> & node_to_copy) {
	this = copynode(node_to_copy, nullptr);
}

template <class T>
void bintree_node<T>::create() {
	_parent = nullptr;
	_left = nullptr;
	_right = nullptr;
}

template <class T>
bintree_node<T> * bintree_node<T>::copynode(const bintree_node<T> * to_copy, const bintree_node<T> * to_copy_parent){
	if(to_copy == nullptr)
		return nullptr;
	bintree_node<T> * new_node = new bintree_node<T>;
	new_node->_parent = to_copy_parent;
	new_node->_left = copynode(to_copy->_left, to_copy);
	new_node->_right = copynode(to_copy->_right, to_copy);
	new_node->_data = to_copy->_data;
	return new_node;
}

template <class T>
bintree_node<T>::~bintree_node() {
	//TODO
	//remove(this);
}

template <class T>
bintree_node<T> & bintree_node<T>::operator=(const bintree_node<T> * &node) {
	if(this != node){
		clear();
		this = copynode(node, nullptr);
	}
	return *this;
}

template <class T>
void bintree_node<T>::clear() {
	std::cout << "clear()" << std::endl;
	deleteLeft(this);
	deleteRight(this);
	std::cout << "-clear()" << std::endl;
	return;
}

template <class T>
void bintree_node<T>::insertLeft(const bintree_node<T> * parent_node, const T node_data){
	if(parent_node->_left == nullptr){
		bintree_node<T> * new_node = new bintree_node<T>;
		new_node->_parent = parent_node;
		new_node->_data = node_data;
		parent_node->_left = new_node;
	} else throw node_exist(); //left node already exist
}

template <class T>
void bintree_node<T>::insertRight(const bintree_node<T> * parent_node, const T node_data){
	if(parent_node->_right == nullptr){
		bintree_node<T> * new_node = new bintree_node<T>;
		new_node->_parent = parent_node;
		new_node->_data = node_data;
		parent_node->_right = new_node;
	}else throw node_exist(); //right node already exist
}

template <class T>
void bintree_node<T>::deleteLeft(bintree_node<T> * to_remove){
	if(to_remove != nullptr){
		remove(to_remove->_left);
		to_remove->_left = nullptr;
	}else throw node_not_valid();
}

template <class T>
void bintree_node<T>::deleteRight(bintree_node<T> * to_remove){
	if(to_remove != nullptr){
		remove(to_remove->_right);
		to_remove->_right = nullptr;
	}else throw node_not_valid();
}

template <class T>
void bintree_node<T>::remove(bintree_node<T> * to_remove){
	if(to_remove != nullptr){
		remove(to_remove->_left);
		remove(to_remove->_right);
		delete to_remove;
	}
}

template <class T>
void bintree_node<T>::insertLeftSub(const bintree_node<T> * position, const bintree_node<T> * sub){
	if(position->_left == nullptr){
		if(sub->_parent == nullptr){
			position->_left = sub;
			sub->_parent = position;
		} else throw node_not_valid(); //sub had jet a parent
	}else throw node_exist(); //left node already exist
}

template <class T>
void bintree_node<T>::insertRightSub(const bintree_node<T> * position, const bintree_node<T> * sub){
	if(position->_right == nullptr){
			if(sub->_parent == nullptr){
				position->_right = sub;
				sub->_parent = position;
			} else throw node_not_valid(); //sub had jet a parent
		}else throw node_exist(); //right node already exist
}

template <class T>
std::ostream & operator<<(std::ostream & os, const bintree_node<T> & bt_node){
	os << "[" << bt_node._left << ", " << bt_node._parent << ", " << bt_node._right << ", " << bt_node._data << "]";
	return os;
}

#endif /* BINTREE_NODE_H_ */
