/* *** ALBERI BINARI ***
 * è un particolare albero ordinato in cui ogni nodo ha al più due figli
 * si fa distinzione tra il figlio sx e il figlio dx di un nodo.
 * Questa proprietà è assai sottile, perchè impone che due alberi T e U aventi
 * gli stessi nodi, gli stessi figli per ogni nodo e la stessa radie, siano
 * distinti qualora un nodo u sia designato come figlio sx di un nodo v in T e
 * come figlio dx del medesimo nodo in U
 *
 */
#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>
#include "queue_pointer.h" //BFS(), _width(), kSubtree() ,maxSumSubtree()

template <class T, class N>
class binary_tree {
public:
	//type
	typedef T value_type;
	typedef N node;

	//operator
	virtual void create()=0;
	virtual bool empty() const=0;
	virtual node root() const=0;
	virtual node parent(const node) const =0; //padre
	virtual node child_sx(const node) const=0;
	virtual node child_dx(const node) const=0;
	virtual bool sx_empty(const node) const=0;
	virtual bool dx_empty(const node) const=0;
	//virtual void costr(bintree<T,N>); //TODO
	virtual void erase(const node) =0;
	virtual value_type read(const node) const =0;
	virtual void write(const node, const value_type)=0;

	virtual void insert_root(const value_type)=0;
	virtual void insert_sx(const node, const value_type)=0; //TODO non bisogna aggiungere anche delete?
	virtual void insert_dx(const node, const value_type)=0;

	//service function
	//virtual void pre_view(const node); //TODO
	//virtual void post_view(const node); //TODO
	//virtual void symmetric_view(const node); //TODO
	//virtual void BFS(node); //TODO
	//virtual int depth(node); //TODO use _depth()
	//virtual int width(node); //TODO use _width()

	int kSubtree(const node, const int) const; //TODO
	int sumSubtree(const node) const; //TODO
	int maxSumSubtree(const node) const; //TODO

private:
	//private service function
	//virtual int _width(node, int); //TODO: WTF
	//virtual int _depth(node, int); //TODO: WTF
	//virtual void printSubTree(std::ostream &, const node) const;
	//virtual void print(std::ostrem &) const;
};

/* //TODO
template <class T, class N>
void binary_tree<T,N>::pre_view(node n){
	//esamina nodo
	if(!sx_empty(n)) previus_view(child_sx(n));
	if(!dx_empty(n)) previus_view(child_dx(n));
}*/

/* //TODO
template <class T, class N>
void binary_tree<T,N>::post_view(node n){
	if(!sx_empty(n)) post_view(child_sx(n));
	if(!dx_empty(n)) post_view(child_dx(n));
	//esamina nodo
}
*/

/* //TODO
template <class T, class N>
void binary_tree<T,N>::symmetric_view(node n){
	if(!sx_empty(n)) symmetric_view(child_sx(n));
	//esamina nodo
	if(!dx_empty(n)) symmetric_view(child_dx(n));
}
*/

/* TODO:
template <class T, class N>
void binary_tree<T,N>::BFS(node n){
	queue<node> q;
	q.push(n);
	while(!q.empty()){
		//esamina q.top
		if(!sx_empty(q.top())) q.push(child_sx(q.top()));
		if(!dx_empty(q.top())) q.push(child_dx(q.top()));
		q.pop();
	}
}
 */

/*
template <class T, class N>
int binary_tree<T,N>::depth(node n){
	return _depth(n, 0);
}

template <class T, class N>
int binary_tree<T,N>::_depth(node n, int i){
	int depth = i;
	if(!sx_empty(n)){
		int tmp = _depth(child_sx(n),i);
		if(tmp>depth)
			depth = tmp;
	}
	if(!dx_empty(n)){
		int tmp = _depth(child_dx(n),i);
		if(tmp>depth)
			depth = tmp;
	}
	return depth+1;
}

template <class T, class N>
int binary_tree<T,N>::width(node n){
	if(!empty())
		return _width(n,0);
	return 0;
}

template <class T, class N>
int binary_tree<T,N>::_width(node n, int w){
	queue<node> q;
	q.push(n);

	while(!q.empty()){
		int i = q.size();
		if(i>w) w=i;

		int j=0;
		while(j<i){
			node top = q.top();
			if(!sx_empty(top)) q.push(child_sx(top));
			if(!dx_empty(top)) q.push(child_dx(top));
			q.pop();
			j++;
		}
	}
	return w;
}
 */

template <class T, class N>
int binary_tree<T,N>::kSubtree(const node n, const int k) const{
	int result = 0;
	queue<node> q;
	q.push(n);
	while(!q.empty()){
		node top = q.top();
		if(sumSubtree(top)==k) result++;
		if(!sx_empty(top)) q.push(child_sx(top));
		if(!dx_empty(top)) q.push(child_dx(top));
		q.pop();
	}
	return result;
}

template <class T, class N>
int binary_tree<T,N>::sumSubtree(const node n) const{
	int result = read(n);
	if(!sx_empty(n)) result+=sumSubtree(child_sx(n));
	if(!dx_empty(n)) result+=sumSubtree(child_dx(n));
	return result;
}

template <class T, class N>
int binary_tree<T,N>::maxSumSubtree(const node n) const{
	int result = sumSubtree(n);
	queue<node> q;

	if(!sx_empty(n)) q.push(child_sx(n));
	if(!dx_empty(n)) q.push(child_dx(n));

	while(!q.empty()){
		node top = q.top();
		int temp = sumSubtree(top);

		if(temp>result) result = temp;
		if(!sx_empty(n)) q.push(child_sx(top));
		if(!dx_empty(n)) q.push(child_dx(top));
		q.pop();
	}
	return result;
}

#endif /* BINARY_TREE_H_ */
