/* *** ALBERI BINARI ***
 * è un particolare albero ordinato in cui ogni nodo ha al più due figli
 * si fa distinzione tra il figlio left e il figlio right di un nodo.
 * Questa proprietà è assai sottile, perchè impone che due alberi T e U aventi
 * gli stessi nodi, gli stessi figli per ogni nodo e la stessa radie, siano
 * distinti qualora un nodo u sia designato come figlio left di un nodo v in T e
 * come figlio right del medesimo nodo in U
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
	virtual node left(const node) const=0;
	virtual node right(const node) const=0;
	virtual bool left_empty(const node) const=0;
	virtual bool right_empty(const node) const=0;
	//virtual void costr(bintree<T,N>); //TODO
	virtual void erase(const node) =0;
	virtual value_type read(const node) const =0;
	virtual void write(const node, const value_type)=0;

	virtual void insert_root(const value_type)=0;
	virtual void insert_left(const node, const value_type)=0; //TODO non bisogna aggiungere anche delete?
	virtual void insert_right(const node, const value_type)=0;

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

/*
template <class T, class N>
void binary_tree<T,N>::pre_view(node n){
	//esamina nodo
	if(!left_empty(n)) previus_view(left(n));
	if(!right_empty(n)) previus_view(right(n));
}*/

/*
template <class T, class N>
void binary_tree<T,N>::post_view(node n){
	if(!left_empty(n)) post_view(left(n));
	if(!right_empty(n)) post_view(right(n));
	//esamina nodo
}
*/

/*
template <class T, class N>
void binary_tree<T,N>::symmetric_view(node n){
	if(!left_empty(n)) symmetric_view(left(n));
	//esamina nodo
	if(!right_empty(n)) symmetric_view(right(n));
}
*/

/* TODO:
template <class T, class N>
void binary_tree<T,N>::BFS(node n){
	queue<node> q;
	q.push(n);
	while(!q.empty()){
		//esamina q.top
		if(!left_empty(q.top())) q.push(left(q.top()));
		if(!right_empty(q.top())) q.push(right(q.top()));
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
	if(!left_empty(n)){
		int tmp = _depth(left(n),i);
		if(tmp>depth)
			depth = tmp;
	}
	if(!right_empty(n)){
		int tmp = _depth(right(n),i);
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
			if(!left_empty(top)) q.push(left(top));
			if(!right_empty(top)) q.push(right(top));
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
		if(!left_empty(top)) q.push(left(top));
		if(!right_empty(top)) q.push(right(top));
		q.pop();
	}
	return result;
}

template <class T, class N>
int binary_tree<T,N>::sumSubtree(const node n) const{
	int result = read(n);
	if(!left_empty(n)) result+=sumSubtree(left(n));
	if(!right_empty(n)) result+=sumSubtree(right(n));
	return result;
}

template <class T, class N>
int binary_tree<T,N>::maxSumSubtree(const node n) const{
	int result = sumSubtree(n);
	queue<node> q;

	if(!left_empty(n)) q.push(left(n));
	if(!right_empty(n)) q.push(right(n));

	while(!q.empty()){
		node top = q.top();
		int temp = sumSubtree(top);

		if(temp>result) result = temp;
		if(!left_empty(n)) q.push(left(top));
		if(!right_empty(n)) q.push(right(top));
		q.pop();
	}
	return result;
}

#endif /* BINARY_TREE_H_ */
