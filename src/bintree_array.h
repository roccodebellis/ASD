#ifndef BINTREE_ARRAY_H_
#define BINTREE_ARRAY_H_

#include <iostream>
#include "binary_tree.h"
#include "exceptions.h" //root()

#define MAX_DIMENSION 99;


template <class T>
class bintree_array : public binary_tree<T, int> {
public:
	static const int NIL=-1;
	//type
	typedef typename binary_tree<T, int>::value_type value_type;
	typedef typename binary_tree<T, int>::node node;

	struct _atom{
		node parent; //TODO: check name
		node sx;
		node dx;
		value_type value;
	};

	typedef struct _atom atom;

	//constructors
	bintree_array();
	bintree_array(int);

	//copy constructor
	bintree_array(const bintree_array<node> &);

	//destructor
	~bintree_array();

	//operators
	void create();
	bool empty() const;
	node root() const;
	node parent(const node) const;
	node child_sx(const node) const;
	node child_dx(const node) const;
	bool sx_empty(const node) const;
	bool dx_empty(const node) const;
	//void costr(bintree<T,N>); //TODO
	void erase(const node);
	value_type read(const node) const;
	void write(const node, const value_type);

	//service function
	void insert_root(const value_type);
	void insert_sx(const node, const value_type);
	void insert_dx(const node, const value_type);

	void pre_view(const node) const;
	void post_view(const node) const;
	void symmetric_view(const node) const;

	//virtual void BFS(node); //TODO
	//virtual int depth(node); //TODO use _depth()
	//virtual int width(node); //TODO use _width()

	//int kSubtree(const node, const int) const; //TODO
	//int sumSubtree(const node) const; //TODO
	//int maxSumSubtree(const node) const; //TODO

	template <class U>
	friend std::ostream & operator<<(std::ostream &, const bintree_array<U> &);

private:
	_atom * tree;
	node root_node;
	node free_node;
	int num_nodes;
	int max_length;

	void print(node, std::ostream &) const;
	node find_free() const;

};

template <class T>
bintree_array<T>::bintree_array(){
	max_length = MAX_DIMENSION;
	create();
}

template <class T>
bintree_array<T>::bintree_array(int nodes_numbers): max_length(nodes_numbers) {
	create();
}

template <class T>
void bintree_array<T>::create(){
	num_nodes = 0;
	free_node = 0;
	root_node = NIL; //include
	tree = new _atom[max_length];
	for(int i=0; i<max_length; i++){
		tree[i].parent = NIL;
		tree[i].sx = NIL;
		tree[i].dx = NIL;
		//tree[i].sx = (i+1)%max_length; //inizializza tutte le parti sx a succ pos libera
	}
}

template <class T>
bintree_array<T>::bintree_array(const bintree_array<node> & copy_bintree){
	max_length = copy_bintree.max_length;
	create();
	root_node = copy_bintree.root_node;
	free_node = copy_bintree.free_node;
	num_nodes = copy_bintree.num_nodes;
	for(int i=0; i<max_length; i++){
		tree[i].parent = copy_bintree.tree[i].parent;
		tree[i].sx = copy_bintree.tree[i].sx;
		tree[i].dx = copy_bintree.tree[i].dx;
		tree[i].value = copy_bintree.tree[i].value;
	}
}

template <class T>
bintree_array<T>::~bintree_array(){
	erase(root_node);
	delete[] tree;
}


template <class T>
bool bintree_array<T>::empty() const {
	return (num_nodes == 0);
}

template <class T>
typename bintree_array<T>::node bintree_array<T>::root() const {
	if(!empty())
		return root_node;
	else throw empty_bintree();
}

template <class T>
typename bintree_array<T>::node bintree_array<T>::parent(const node u_node) const {
	//PRE: !empty(), u_node appartine T, livello(u_node) > 0
	//TODO: non controllo l'appartenenenza di u_node a T
	//FIXME if(u_node>=0 && u_node<max_dimension) else throw node_not_valid();
	if(!empty())
		if (u_node != root_node)
			return tree[u_node].parent;
		else throw node_not_valid();
	else throw empty_bintree();
}

template <class T>
typename bintree_array<T>::node bintree_array<T>::child_sx(const node u_node) const {
	//PRE: !empty(), u_node appartine T, ha un figlio sx
	//TODO: non controllo l'appartenenenza di u_node a T
	//FIXME if(u_node>=0 && u_node<max_dimension) else throw node_not_valid();
	if(!empty())
		if (!sx_empty(u_node))
			return tree[u_node].sx;
		else throw node_not_valid();
	else throw empty_bintree();
}

template <class T>
typename bintree_array<T>::node bintree_array<T>::child_dx(const node u_node) const {
	//PRE: !empty(), u_node appartine T, ha un figlio dx
	//TODO: non controllo l'appartenenenza di u_node a T
	//FIXME if(u_node>=0 && u_node<max_dimension) else throw node_not_valid();
	if(!empty())
		if (!dx_empty(u_node))
			return tree[u_node].dx;
		else throw node_not_valid();
	else throw empty_bintree();
}

template <class T>
bool bintree_array<T>::sx_empty(const node u_node) const {
	//PRE: !empty(), u_node appartine T,
	//TODO: non controllo l'appartenenenza di u_node a T

	//FIXME if(u_node>=0 && u_node<max_dimension) else throw node_not_valid();
	if(!empty())
		return (tree[u_node].sx == NIL);
	else throw empty_bintree();
}

template <class T>
bool bintree_array<T>::dx_empty(const node u_node) const {
	//PRE: !empty(), u_node appartine T,
	//TODO: non controllo l'appartenenenza di u_node a T
	//FIXME if(u_node>=0 && u_node<max_dimension) else throw node_not_valid();
	if(!empty())
		return (tree[u_node].dx == NIL);
	else throw empty_bintree();
}

template <class T>
void bintree_array<T>::erase(const node u_node){
	//PRE: !empty(), u_node appartiene a N
	//POST: T' è ottenuto da T eliminando il sottoalbero di radice u_node
	//if(!empty()) jet in sx_empty() && dx_empty()
	if(u_node != NIL){
		if(!sx_empty(u_node))
			erase(tree[u_node].sx);
		if(!dx_empty(u_node))
			erase(tree[u_node].dx);
		if(u_node != root_node){
			if(tree[parent(u_node)].sx == u_node)
				tree[parent(u_node)].sx = NIL;
			else if(tree[parent(u_node)].dx == u_node)
				tree[parent(u_node)].dx = NIL;
			free_node = u_node; //??
			num_nodes--;
		} else {
			root_node = NIL;
			free_node = 0;
			num_nodes = 0;
		}
		tree[u_node].sx = NIL;
		tree[u_node].dx = NIL;
		tree[u_node].parent = NIL;
	} else throw node_not_valid();
	//else throw empty_bintree();
	return;
}

template <class T>
typename bintree_array<T>::value_type bintree_array<T>::read(const node u_node) const {
	//DELETE
	//std::cout << "\tread()" << std::endl;

	if(u_node != NIL) //FIXME: || (u_node>=0 && u_node<max_lenght))
		return tree[u_node].value;
	else throw node_not_valid();
}

template <class T>
void bintree_array<T>::write(const node u_node, const value_type u_value){
	//DELETE
	std::cout << "\twrite()" << std::endl;

	if(u_node != NIL) //FIXME: || (u_node>=0 && u_node<max_lenght))
		tree[u_node].value = u_value;
	else throw node_not_valid();
	return;
}

template <class T>
void bintree_array<T>::insert_root(const value_type u_value) {
	//PRE: !empty()
	//POST: T'=(N,A), N={u_node}, A={}. livello(u_node)=0
	if(empty())
		if(root_node == NIL){
			root_node = free_node;

			//tree[root_node].sx = NIL; //jet in crete()
			//tree[root_node].dx = NIL; //jet in crete()
			tree[root_node].value = u_value;

			free_node = (tree[(free_node+1) % max_length].parent==NIL) ? (free_node+1) % max_length : find_free();
			num_nodes++;
		} else throw node_not_valid();
	else throw root_exist();
	return;
}

template <class T>
void bintree_array<T>::insert_sx(const node u_node,const value_type u_value) {
	//PRE: !empty(), u appartiene N, sinistrovuoto(u,T)=true
	//POST: N'=Nu{v}, T' è ottenuto da T aggiungendo v come figlio sx di u
	//if(!empty()) jet in sx_empty()
	//DELETE

	if(u_node != NIL) //FIXME: || (u_node>=0 && u_node<max_lenght))
		if(num_nodes < max_length)
			if(sx_empty(u_node)){
				tree[u_node].sx = free_node;

				tree[free_node].parent = u_node;
				//tree[free_node].sx = NIL; //jet in crete()
				//tree[free_node].dx = NIL; //jet in crete()
				tree[free_node].value = u_value;

				free_node = (tree[(free_node+1) % max_length].parent==NIL) ? (free_node+1) % max_length : find_free();
				num_nodes++;
			} else throw node_exist();
		else throw full_bintree();
	else throw node_not_valid();
	//else throw empty_bintree();
	return;
}

template <class T>
void bintree_array<T>::insert_dx(const node u_node,const value_type u_value) {
	//PRE: !empty(), u appartiene N, sinistrovuoto(u,T)=true
	//POST: N'=Nu{v}, T' è ottenuto da T aggiungendo v come figlio sx di u
	//if(!empty()) jet in dx_empty
	if(u_node != NIL) //FIXME: || (u_node>=0 && u_node<max_lenght))
		if(num_nodes < max_length)
			if(dx_empty(u_node)){
				tree[u_node].dx = free_node;

				tree[free_node].parent = u_node;
				//tree[free_node].sx = NIL; //jet in crete()
				//tree[free_node].dx = NIL; //jet in crete()
				tree[free_node].value = u_value;

				free_node = (tree[(free_node+1) % max_length].parent==NIL) ? (free_node+1) % max_length : find_free();
				num_nodes++;
			} else throw node_exist();
		else throw full_bintree();
	else throw node_not_valid();
	//else throw empty_bintree();
	return;
}

template <class T>
void bintree_array<T>::print(node n, std::ostream & os) const {
	/*if(n == root_node){
		std::cout << num_nodes <<"\tsx\tp\tdx\tv" << std::endl;
		for(int i=0; i<num_nodes; i++){
			std::cout <<"\t" << tree[i].sx
					<<"\t" << tree[i].parent
					<<"\t" << tree[i].dx
					<<"\t" << tree[i].value
					<< std::endl;
		}
	}*/

	os << "[" << read(n);
	if(!(sx_empty(n) && dx_empty(n))){
		if(!sx_empty(n)){
			os << " , sx: ";
			print(child_sx(n),os);
		} else os << " , NIL";
		os << ",";
		if(!dx_empty(n)){
			os << "dx: ";
			print(child_dx(n),os);
		} else os << " , NIL";
	}
	os << "]";
	return;
}

template <class T>
typename bintree_array<T>::node bintree_array<T>::find_free() const {
	node index_free_node = NIL; //FIXME forse restituisco NIL
	for(int i=0; i<max_length; i++){
		//FIXME utilizzare num_node e %max_length
		if(tree[i].parent == NIL && tree[i].sx == NIL && tree[i].dx == NIL){
			if(num_nodes > 1)
				return i;
			else if(num_nodes==1 && root_node==0) //FIXME: no sense
				return 1;
		}
	}
	return index_free_node;
}


template <class T>
void bintree_array<T>::pre_view(const node n) const {
	std::cout << read(n) <<" ";
	if(!sx_empty(n)) pre_view(child_sx(n));
	if(!dx_empty(n)) pre_view(child_dx(n));
}

template <class T>
void bintree_array<T>::post_view(const node n) const {
	if(!sx_empty(n)) post_view(child_sx(n));
	if(!dx_empty(n)) post_view(child_dx(n));
	std::cout << read(n) <<" ";
}


template <class T>
void bintree_array<T>::symmetric_view(const node n) const {
	if(!sx_empty(n)) symmetric_view(child_sx(n));
	std::cout << read(n) <<" ";
	if(!dx_empty(n)) symmetric_view(child_dx(n));
}

template <class T>
std::ostream & operator<<(std::ostream & os, const bintree_array<T> & bt){
	if(bt.empty())
		os << "L'albero è vuoto";//os << "L'albero \212 vuoto";
	else bt.print(bt.root_node, os);
	return os;
}

#endif /* BINTREE_ARRAY_H_ */
