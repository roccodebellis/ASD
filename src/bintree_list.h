#ifndef BINTREE_LIST_H_
#define BINTREE_LIST_H_

#include "bintree_node.h"
#include "binary_tree.h"
#include "exceptions.h" //empty_bintree

template <class T>
class bintree_list : public binary_tree<T, bintree_node<T> *> {
public:
	typedef typename binary_tree<T, bintree_node<T> *>::value_type value_type;
	typedef typename binary_tree<T, bintree_node<T> *>::node node;

	//constructors
	bintree_list();

	//copy constructors
	bintree_list(const bintree_list<T> &);

	//destructor
	//~bintree_list();

	//operator
	bintree_list& operator=(const bintree_list<T> &);
	void create();
	bool empty() const;
	node root() const;
	node parent(const node) const;
	node left(const node) const;
	node right(const node) const;
	bool left_empty(const node) const;
	bool right_empty(const node) const;
	void erase(const node);
	value_type read(const node) const;
	void write(const node, const value_type);

	//advantage
	void insert(const value_type);
	node search(const node, const value_type) const;
	node minimum(node) const;
	node maximum(node) const;
	node successor(node) const;
	node predecessor(node) const;

	//service function
	void insertRoot(const value_type);
	void insertLeft(node, const value_type);
	void insertRight(node, const value_type);
	void deleteLeft(bintree_node<T> *);
	void deleteRight(bintree_node<T> *);

	void pre_view(const node) const;
	void post_view(const node) const;
	void symmetric_view(const node) const;

	size_t getNumberOfNodes() { return _numberOfNodes;}

	//template <class U>
	//friend std::ostream & operator<<(std::ostream &, const bintree_list<U> &);

private:
	bintree_node<T> * _root;
	size_t _numberOfNodes;

	//private service function
	bintree_node<T> * copynode(const bintree_node<T> *, const bintree_node<T> *);
	void deleteNode(bintree_node<T> *);
};

template <class T>
bintree_list<T>::bintree_list() {
	std::cout << "bintree_list()" << std::endl;
	_root = nullptr;
	_numberOfNodes = 0;
	//create();
	std::cout << "-bintree_list()" << std::endl;
}

template <class T>
bintree_list<T>::bintree_list(const bintree_list<T> & bt) {
	_root = copynode(bt._root, nullptr); //bintree_list<T>::
	_numberOfNodes = 0;
}

template <class T>
bintree_node<T> * bintree_list<T>::copynode(const bintree_node<T> * to_copy, const bintree_node<T> * parent) {
	if(to_copy == nullptr)
		return nullptr;
	bintree_node<T> * new_node = new bintree_node<T>;
	new_node->parent = parent;
	new_node->_data = to_copy->_data;
	new_node->_left = copynode(to_copy->_left, to_copy); //bintree_list<T>::
	new_node->_right = copynode(to_copy->_right, to_copy); //bintree_list<T>::
	_numberOfNodes++;
	return new_node;
}

/*
template <class T>
bintree_list<T>::~bintree_list(){
	erase(_root);
	_root = nullptr;
}
*/

template <class T>
bintree_list<T> & bintree_list<T>::operator=(const bintree_list<T> & bt) {
	if(this != &bt){
		_root->clear();
		delete _root;
		_numberOfNodes = 0;
		_root = bintree_list<T>::copynode(bt._root, nullptr);
	}
}

template <class T>
void bintree_list<T>::create() {
	std::cout << "create()" << std::endl;
	if(!empty())
		_root->clear();
	_root = nullptr;
	_root->_parent = nullptr;
	_numberOfNodes = 0;
	std::cout << "-create()" << std::endl;
	return;
}

template <class T>
bool bintree_list<T>::empty() const {
	std::cout << "empty()" << std::endl;
	return (_root == nullptr);
	std::cout << "-empty()" << std::endl;
}

template <class T>
typename bintree_list<T>::node bintree_list<T>::root() const {
	return _root;
}

template <class T>
typename bintree_list<T>::node bintree_list<T>::parent(const node n) const {
	return n->_parent;//return n->getParent();
}

template <class T>
typename bintree_list<T>::node bintree_list<T>::left(const node n) const {
	return n->_left; //return n->getLeft();
}

template <class T>
typename bintree_list<T>::node bintree_list<T>::right(const node n) const {
	return n->_right;//return n->getRight();
}

template <class T>
bool bintree_list<T>::left_empty(const node n) const {
	return (n->_left == nullptr);
}

template <class T>
bool bintree_list<T>::right_empty(const node n) const {
	return (n->_right == nullptr);
}

template <class T>
void bintree_list<T>::erase(const node n) {
	if(n->_parent == nullptr){
		deleteNode(n);
		_root = nullptr;
	} else if(n->_parent->getLeft() == n)
		deleteLeft(n->_parent);
	else
		deleteRight(n->_parent); //WTF???
	return;
}

template <class T>
typename bintree_list<T>::value_type bintree_list<T>::read(const node n) const {
	return (n->_data);
}

template <class T>
void bintree_list<T>::write(const node n, const value_type n_data) {
	n->_data = n_data;
	return;
}

template <class T>
typename bintree_list<T>::node bintree_list<T>::search(const node search_n, const value_type search_data) const {
	if(search_n == nullptr)
		throw empty_bintree();
	else {
		if(search_data == search_n->_data)
			return search_n;
		else if(search_data < search_n->_data)
			return search(search_n->_left, search_data);
		else
			return search(search_n->_right, search_data);
	}
}

template <class T>
typename bintree_list<T>::node bintree_list<T>::minimum(node start_node) const {
	while(start_node->_left != nullptr)
		start_node = start_node->_left;
	return start_node;
}

template <class T>
typename bintree_list<T>::node bintree_list<T>::maximum(node start_node) const {
	while(start_node->_right != nullptr)
		start_node = start_node->_right;
	return start_node;
}


template <class T>
typename bintree_list<T>::node bintree_list<T>::successor(node curr_n) const {
	if(curr_n != nullptr)
		return minimum(curr_n->_right);
	bintree_node<T> * curr_parent  = curr_n->_parent;
	while(curr_parent != nullptr && curr_n == curr_parent->_right){
		curr_n = curr_parent;
		curr_parent = curr_n->_parent;
	}
	return curr_n;
}

template <class T>
typename bintree_list<T>::node bintree_list<T>::predecessor(node curr_n) const {
	if(curr_n != nullptr)
		return minimum(curr_n->_left);
	bintree_node<T> * curr_parent  = curr_n->_parent;
	while(curr_parent != nullptr && curr_n == curr_parent->_left){
		curr_n = curr_parent;
		curr_parent = curr_n->_parent;
	}
	return curr_n;

}


template <class T>
void bintree_list<T>::insert(const value_type n_data) {
	bintree_node<T> * new_node_parent = nullptr;
	bintree_node<T> * node_itr = _root;
	while(node_itr != nullptr){
		new_node_parent = node_itr;
		if(node_itr->_data >= n_data)
			node_itr = node_itr->_left;
		else
			node_itr = node_itr->_right;
	}
	bintree_node<T> * new_node = new bintree_node<T>;
	new_node->_parent = new_node_parent;
	new_node->_data = n_data;
	new_node->_left = nullptr;
	new_node->_right = nullptr;

	if(new_node_parent == nullptr)
		_root = new_node;
	else if (new_node_parent->_data >= n_data)
		new_node_parent->_left = new_node;
	else new_node_parent->_right = new_node;
	return;
}

template <class T>
void bintree_list<T>::insertRoot(const value_type root_data) {
	if(_root == nullptr){
		bintree_node<T> * root_node = new bintree_node<T>;
		root_node->_data = root_data;
		_root = root_node;
		_numberOfNodes++;
	} else throw root_exist();


	return;
}

template <class T>
void bintree_list<T>::insertLeft(node parent_node, const value_type node_data){
	if(parent_node->_left == nullptr){
		bintree_node<T> * new_left_node = new bintree_node<T>;
		new_left_node->_data = node_data;
		new_left_node->_parent = parent_node;
		parent_node->_left = new_left_node;
		_numberOfNodes++;
	} else throw node_exist();

	return;
}

template <class T>
void bintree_list<T>::insertRight(node parent_node, const value_type node_data){
	if(parent_node->_right == nullptr){
		bintree_node<T> * new_right_node = new bintree_node<T>;
		new_right_node->_data = node_data;
		new_right_node->_parent = parent_node;
		parent_node->_right = new_right_node;
		_numberOfNodes++;
	} else throw node_exist();
	return;
}

template <class T>
void bintree_list<T>::deleteLeft(bintree_node<T> * to_delete){
	if(to_delete != nullptr){
		deleteNode(to_delete->_left);
		to_delete->_left = nullptr;
	}
}

template <class T>
void bintree_list<T>::deleteRight(bintree_node<T> *to_delete){
	if(to_delete != nullptr){
		deleteNode(to_delete->_right);
		to_delete->_right = nullptr;
	}
}


template <class T>
void bintree_list<T>::deleteNode(bintree_node<T> * to_delete) {
	if(to_delete != nullptr){
		deleteNode(to_delete->_left);
		deleteNode(to_delete->_right);
		delete to_delete;
		_numberOfNodes--;
	}
}

template <class T>
void bintree_list<T>::pre_view(const node n) const {
	std::cout << read(n) <<" ";
	if(!left_empty(n)) pre_view(left(n));
	if(!right_empty(n)) pre_view(right(n));
}

template <class T>
void bintree_list<T>::post_view(const node n) const {
	if(!left_empty(n)) post_view(left(n));
	if(!right_empty(n)) post_view(right(n));
	std::cout << read(n) <<" ";
}


template <class T>
void bintree_list<T>::symmetric_view(const node n) const {
	if(!left_empty(n)) symmetric_view(left(n));
	std::cout << read(n) <<" ";
	if(!right_empty(n)) symmetric_view(right(n));
}

/*
template <class T>
std::ostream & operator<<(std::ostream & os, const bintree_list<T> & bt){

}
 */

#endif /* BINTREE_LIST_H_ */
