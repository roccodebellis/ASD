#ifndef TREE_LINK_H_
#define TREE_LINK_H_

#include <iostream>
#include "exceptions.h"

template <class I>
class tree_link;

template <class I>
class tree_node{
public:
	friend class tree_link<I>;
	tree_node(){
		_parent = nullptr;
		_firstChild = nullptr;
		_nextSibling = nullptr;
	}
	void operator=(tree_node<I> & node){
		_parent = node._parent;
		_firstChild = node._firstChild;
		_nextSibling = node._nextSibling;
	}

private:
	tree_node<I> * _parent;
	tree_node<I> * _firstChild;
	tree_node<I> * _nextSibling;
	I _item;
};

template <class I>
class tree_link{
public:
	typedef I item;
	typedef tree_node<I> * node;

	tree_link(){
		create();
	}

	void create() { _root = nullptr; _size=0; };
	bool empty() const {
		return (_root == nullptr); };
	void insertRoot(item);
	node root() const { return (_root); };
	node parent(node) const ;
	bool leaf(node) const;
	node firstChild(node) const;
	bool lastSibling(node) const;
	node nextSibling(node) const;
	void insertFirstSubTree(node, tree_link<I> &);
	void insertSubTree(node, tree_link<I> &);
	void removeSubTree(node);

	void insertFirst(node, item);
	void insert(node, item);

	void writeNode(node n, item e){ n->_item = e; };
	item readNode(node n) const { return (n->_item); };

	void print() const;
private:
	node _root;
	int _size;

	void print(node) const;
};

template <class I>
void tree_link<I>::insertRoot(item e) {
	if(!empty())
		root_exist();
	_root = new tree_node<I>();
	_root->_item = e;
	_size++;
}

template <class I>
typename tree_link<I>::node tree_link<I>::parent(node n) const {
	if(empty())
		throw empty_tree();
	if(n == _root)
		throw is_root();
	return (n->_parent); //TODO check
}

template <class I>
bool tree_link<I>::leaf(node n) const {
	if(empty())
		throw empty_tree();
	return (n->_firstChild == nullptr);
}

template <class I>
typename tree_link<I>::node tree_link<I>::firstChild(node n) const {
	if(!leaf(n))
		return (n->_firstChild);
}

template <class I>
bool tree_link<I>::lastSibling(node n) const {
	if(empty())
		throw empty_tree();
	return (n->_nextSibling == nullptr);
}

template <class I>
typename tree_link<I>::node tree_link<I>::nextSibling(node n) const {
	if(!lastSibling(n))
		return (n->_nextSibling);
}

template <class I>
void tree_link<I>::insertFirstSubTree(node n, tree_link<I> & subTree){
	if(empty() || subTree.empty())
		throw empty_tree(); //uno dei due
	node subTree_root = subTree._root;
	subTree_root->_nextSibling = n->_firstChild; //firstChild(n)
	n->_firstChild = subTree_root;
	subTree_root->_parent = n;
	_size+=subTree._size;
}

template <class I>
void tree_link<I>::insertSubTree(node n, tree_link<I> & subTree){
	if(empty() || subTree.empty())
		throw empty_tree(); //uno dei due
	node subTree_root = subTree._root;
	subTree_root->_nextSibling = n->_nextSibling;
	subTree_root->_parent = n;
	n->_nextSibling = subTree_root;
	_size+=subTree._size;
}

template <class I>
void tree_link<I>::removeSubTree(node n) {
	if(n == _root)
		throw is_root();
	while(!leaf(n))
		removeSubTree(firstChild(n));
	if(n->_parent->_firstChild == n)
		n->_parent->_firstChild = n->_nextSibling;
	else {
		node it = n->_parent->_firstChild;
		while(!lastSibling(it)){
			if(it->_nextSibilling == n) break;
			it = nextSibling(it);
		}
		nextSibling(it) = nextSibling(n);
	}
	delete n;
	_size--;
}

template <class I>
void tree_link<I>::insertFirst(node n, item e) {
	//insert node like firstChild of n
	node new_n = new tree_node<I>();
	new_n->_item = e;
	new_n->_parent = n;
	new_n->_nextSibling = n->_firstChild;
	n->_firstChild = new_n;
	_size++;
}

template <class I>
void tree_link<I>::insert(node n, item e) {
	//insert node like sibling of n
	node new_n = new tree_node<I>();
	new_n->_item = e;
	new_n->_parent = n->_parent;
	new_n->_nextSibling = n->_nextSibling;
	n->_nextSibling = new_n;
	_size++;
}

template <class I>
void tree_link<I>::print() const {
	std::cout << "--- n_nodes: " << _size<< "---" << std::endl;
	print(_root);
}

template <class I>
void tree_link<I>::print(node n) const {
	//std::cout << "print(" << readNode(n) << ")" << std::endl; //DELETE
	/*
	if(n != root())
		std::cout << n->_item << "\t";
	if(n->_nextSibilling != nullptr)
		print(n->_nextSibilling);
	if(n->_firstChild != nullptr){
		std::cout << std::endl;
		std::cout << n->_item << ": ";
		print(n->_firstChild);
	} else {
		std::cout << std::endl;
		std::cout << n->_item  << std::endl;
	}
	 */
	node p;
	std::cout << n->_item ;
	if (!leaf(n)) {
		std::cout << ":";
		p=firstChild(n);
		while (!lastSibling(p)) {
			std::cout << " " << p->_item;
			p=nextSibling(p);
		}
		std::cout << " " << p->_item << std::endl;
		p=firstChild(n);
		while (!lastSibling(p)) {
			print(p);
			p=nextSibling(p);
		}
		print(p);
	} else {
		std::cout << std::endl;
	}

}

#endif /* TREE_LINK_H_ */
