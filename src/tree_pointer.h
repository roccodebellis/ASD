#ifndef TREE_POINTER_H_
#define TREE_POINTER_H_


#include "tree.h"
#include<iostream>
#define MAXNODES 100

template<class item>
class Record {
	template <class T> friend class tree_list_pointer;
public:
	Record(){
		brother = NULL;
		parent = NULL;
		child = NULL;
	}
	void operator=(Record<item>& record2){
		brother = record2.brother;
		parent = record2.parent;
		child = record2.child;
	}
private:
	item e;
	Record<item>* brother;
	Record<item>* parent;
	Record<item>* child;
};

template<class I>
class tree_list_pointer : public tree<I, Record<I>* > {
public:

	typedef typename tree<I, Record<I>*>::item item;
	typedef typename tree<I, Record<I>*>::node node;

	// Costruttori e distruttore
	tree_list_pointer(){
		create();
	};
	tree_list_pointer(tree_list_pointer&);
	void create () ;
	bool empty () const ;
	void insertRoot (node) ;
	node root () const ;
	node parent (node) const ;
	bool leaf (node) const ;
	node firstChild (node) const ;
	bool lastSibling (node) const ;
	node nextSibling (node) const ;
	void copy(node, node);

	// DA IMPLEMENTARE
	void insertFirstSubTree (node, tree<item,node> &);
	void insertSubTree (node, tree<item,node> &);
	void removeSubTree (node) ;

	void insertFirst(node, item);
	void insert(node, item);

	void writeNode (node, item) ;
	item readNode (node) const ;

	void print() const;
	void print(node) const;
private:

	node _root;
	int _size;

};

template <class I>
void tree_list_pointer<I>::print() const{
	print(_root);
}

template <class I>
void tree_list_pointer<I>::print(node n) const{

	if(n != root())std::cout << n->e << "\t";
	if(n->brother != NULL){
		print(n->brother);
	}
	if(n->child != NULL){
		std::cout << std::endl;
		std::cout << n->e << ":";
		print(n->child);
	}
	if(n->child == NULL){
		std::cout << std::endl;
		std::cout << n->e << ":";
	}

}

template<class I>
tree_list_pointer<I>::tree_list_pointer(tree_list_pointer<I>& tree){
	_root = NULL;
	_root = new Record<I>();

	writeNode(_root, tree.readNode(tree.root()));
	copy(_root, tree.firstChild(tree.root()));
}

template <class I>
void tree_list_pointer<I>::copy(node pos, node posCopia){
	if(posCopia != NULL){
		if(posCopia->brother != NULL){
			copy(pos, posCopia->brother);

		}
		insertFirst(pos, posCopia->e);
		if(posCopia->child != NULL){
			copy(firstChild(pos),posCopia->child);

		}
	}
}

template<class I>
void tree_list_pointer<I>::insertFirstSubTree(node n, tree<item,node> &tree){
	node l = tree.root();
	l->brother = firstChild(n);
	n->child = l;
	l->parent = n;
	//_size FIXME
}

template<class I>
void tree_list_pointer<I>::insertSubTree(node n, tree<item,node> &tree){
	node l = tree.root();
	l->brother = n->brother;
	l->parent = n;
	n->brother = l;
	//_size+=tree.; FIXME
}


template <class I>
void tree_list_pointer<I>::create(){
	_root = NULL;
	_size = 0;
}

template <class I>
bool tree_list_pointer<I>::empty() const{
	return(_size == 0);
}

template <class I>
void tree_list_pointer<I>::insertRoot (node n){
	if (empty()){
		_root = n;
		_size++;
	}
}

template <class I>
typename tree_list_pointer<I>::node tree_list_pointer<I>::root () const{
	return _root;
}

template <class I>
typename tree_list_pointer<I>::node tree_list_pointer<I>::parent (node n) const{
	return n->parent;
}

template <class I>
bool tree_list_pointer<I>::leaf(node n) const{
	return (n->child == NULL);
}

template <class I>
typename tree_list_pointer<I>::node tree_list_pointer<I>::firstChild (node n) const{
	return(n->child);
}

template <class I>
bool tree_list_pointer<I>::lastSibling (node n) const {
	return (n->brother == NULL);
}

template <class I>
typename tree_list_pointer<I>::node tree_list_pointer<I>::nextSibling (node n) const{
	if (!lastSibling(n)){
		return n->brother;
	}
	return n;
}


// inserisce un node come firstChild di n
template <class I>
void tree_list_pointer<I>::insertFirst(node n, item el){
	// cerca una posizione libera
	node l = new Record<I>();
	l->brother = firstChild(n);
	n->child = l;
	l->parent = n;
	l->e = el;
	_size++;
}

// inserisce un node come fratello di n
template <class I>
void tree_list_pointer<I>::insert(node n, item el){
	node l = new Record<I>();
	l->e = el;
	l->brother = n->brother;
	l->parent = n;
	n->brother = l;
	_size++;
}

template <class I>
void tree_list_pointer<I>::removeSubTree (node n){
	if(n != root()){
		while (!leaf(n)){
			removeSubTree(firstChild(n));
		}
		std::cout << "n:" << n->e << std::endl;
		if(n->parent->child == n){
			n->parent ->child = n->brother;
		} else{
			node i = n->parent->child;
			while(i != NULL){
				if(i->brother == n) break;
				i = i->brother;
			}
			i->brother = n->brother;
		}
		delete n;
		_size--;
	}
}

template <class I>
void tree_list_pointer<I>::writeNode (node n, item el){
	n->e = el;
}

template <class I>
typename tree_list_pointer<I>::item tree_list_pointer<I>::readNode (node n) const{
	return n->e;
}

#endif /* TREE_POINTER_H_ */
