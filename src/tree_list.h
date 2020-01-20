#ifndef TREE_LIST_H_
#define TREE_LIST_H_

#include "tree.h"
#include "list_vector.h"
#include "exceptions.h"
#define MAX_NODES 100

template <class I>
class tree_list : public tree<I, int> {
public:
	typedef I item;
	typedef int node;

	tree_list();
	tree_list(const tree_list<I> &);

	~tree_list();

	void create();
	bool empty() const;
	void insertRoot(node);
	node root() const;
	node parent(node) const ;
	bool leaf(node) const;
	node firstChild(node) const;
	bool lastSibling(node) const;
	node nextSibling(node) const;
	//void insertFirstSubTree(node, tree_list<I> &);
	//void insertSubTree(node, tree_list<I> &);
	void removeSubTree(node);

	void insertFirst(node, item);
	void insert(node, item);

	void writeNode(node, item);
	item readNode(node) const;

	void print() const;
private:
	struct Record{
		item e;
		bool used;
		list_vector<int> childs;
		node parent;
	};
	typedef list_vector<int>::position position_list;

	Record _nodes[MAX_NODES];
	node _root;
	size_t _size;

	//size_t _size TODO:
};

template <class I>
tree_list<I>::tree_list(){
	create();
}

template <class I>
tree_list<I>::tree_list(const tree_list<I> &){
	//FIXME
	std::cout << "copycostructor not implemented!" << std::endl;
	create();

}

template <class I>
tree_list<I>::~tree_list(){
	//TODO
}

template <class I>
void tree_list<I>::create(){
	_size = 0;
	for(int i=0; i<MAX_NODES; i++){
		_nodes[i].used = false;
		_nodes[i].childs.create(); //TODO what ???
	}
}

template <class I>
bool tree_list<I>::empty() const {
	return (_size == 0);
}

template <class I>
void tree_list<I>::insertRoot(node root){
	if(empty()){
		_root = 0;
		_nodes[0].used = true;
		_size++;
	} else
		throw root_exist();
}

template <class I>
typename tree_list<I>::node tree_list<I>::root() const{
	if(empty())
		throw empty_tree();
	else return (_root);
}

template <class I>
typename tree_list<I>::node tree_list<I>::parent(node n) const {
	if(empty())
		throw empty_tree();
	else if(n!=root() && _nodes[n].used){
		return (_nodes[n].parent);
	}
}

template <class I>
bool tree_list<I>::leaf(node n) const {
	if(empty())
		throw empty_tree();
	else if (_nodes[n].used)
		return (_nodes[n].childs.empty());
}

template <class I>
typename tree_list<I>::node tree_list<I>::firstChild(node n) const {
	if(leaf(n))
		throw is_leaf();
	else return (_nodes[n].childs.read(_nodes[n].childs.begin()));//TODO check
}

template <class I>
bool tree_list<I>::lastSibling(node n) const {
	position_list child_itr;
	node n_parent = parent(n);
	child_itr = _nodes[n_parent].childs.begin();
	while(!_nodes[n_parent].childs.end(child_itr))
		child_itr = _nodes[n_parent].childs.next(child_itr);
	return (n == _nodes[n_parent].childs.read(child_itr));
}

template <class I>
typename tree_list<I>::node tree_list<I>::nextSibling(node n) const {
	if(!lastSibling(n)){
		position_list child_itr;
		node n_parent = parent(n);
		child_itr = _nodes[n_parent].childs.begin();
		while(!_nodes[n_parent].childs.end(child_itr))
			if(_nodes[n_parent].childs.read(child_itr) == n)
				return (_nodes[n_parent].childs.read(_nodes[n_parent].childs.next(child_itr)));
		child_itr = _nodes[n_parent].childs.next(child_itr);
	}
}

/* TODO
template <class I>
void tree_list<I>::insertFirstSubTree(node, tree_list<I> &) {
	std::cout << "insertFirstSubTree not implemented!" << std::endl;
}
*/

/* TODO
template <class I>
void tree_list<I>::insertSubTree(node, tree_list<I> &){

}
 */

template <class I>
void tree_list<I>::removeSubTree(node n){
	if(!leaf(n))
		while(!_nodes[n].childs.empty())
			removeSubTree(_nodes[n].childs.read(_nodes[n].childs.begin()));

	node n_parent = parent(n);

	position_list child_itr = _nodes[n_parent].childs.begin();
	while(_nodes[n_parent].childs.read(child_itr) != n)
		child_itr = _nodes[n_parent].childs.next(child_itr);

	_nodes[n_parent].childs.erase(child_itr);
	_nodes[n].used = false;
	_size--;
}

template <class I>
void tree_list<I>::insertFirst(node n, item e){
	//insert a node like firstChild of n
	if(_size == MAX_NODES)
		throw full_tree();
	int k;
	for(k=0;k < MAX_NODES && _nodes[k].used; k++);
	if(k < MAX_NODES){
		_nodes[k].used = true;
		_nodes[k].e = e;
		_nodes[k].parent = n; //FIXME maybe wrong
		_nodes[n].childs.pushFront(k); //_nodes[n].childs.insert(k,_nodes[n].childs.begin());
		_size++;
	}
}

template <class I>
void tree_list<I>::insert(node n, item e){
	//insert a node like sibiling of n
	if(_size == MAX_NODES)
		throw full_tree();
	int k;
	for(k=0;k < MAX_NODES && _nodes[k].used; k++);
	if(k < MAX_NODES){
		_nodes[k].used = true;
		_nodes[k].e = e;
		node n_parent = parent(n);
		_nodes[k].parent = n_parent;
		//_nodes[n_parent].childs.insert(k,n+1); //FIXME may not work
		bool found = false;
		//FIXME i don't like this, maybe i can do this better
		position_list child_itr = _nodes[n_parent].childs.begin();
		while(!_nodes[n_parent].childs.end(child_itr) && !found){
			if(_nodes[n_parent].childs.read(child_itr) == n)
				found = true;
			child_itr = _nodes[n_parent].childs.next(child_itr);
		}
		_nodes[n_parent].childs.insert(k,child_itr+1);
		_size++;
	}
}

template <class I>
void tree_list<I>::writeNode(node n, item e){
	_nodes[n].e = e; //maybe add some check if the node is used
}

template <class I>
typename tree_list<I>::item tree_list<I>::readNode(node n) const {
	return (_nodes[n].e);
}

template <class I>
void tree_list<I>::print() const {
	std::cout << "{";
	for(int i=0; i<_size; i++){
		if(_nodes[i].used == true){
			std::cout << readNode(i);
			if(!leaf(i)){
				std::cout << ": ";
				position_list child_itr = _nodes[i].childs.begin();
				while(!_nodes[i].childs.end(child_itr)){
					std::cout << readNode(_nodes[i].childs.read(child_itr)) << " ";
					child_itr = _nodes[i].childs.next(child_itr);
				}
			}
		}
		std::cout << std::endl;
	}
	std::cout << "}" << std::endl;
}




#endif /* TREE_LIST_H_ */
