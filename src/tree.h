#ifndef TREE_H_
#define TREE_H_

template <class I, class N>
class tree{
public:
	typedef I item;
	typedef N node;

	virtual void create() = 0;
	virtual bool empty() const = 0;
	virtual void insertRoot(node) = 0;
	virtual node root() const = 0;
	virtual node parent(node) const = 0;
	virtual bool leaf(node) const = 0;
	virtual node firstChild(node) const = 0;
	virtual bool lastSibiling(node) const = 0;
	virtual node nextSibiling(node) const = 0;
	//virtual void insertFirstSubTree(node, tree &) = 0;
	//virtual void insertSubTree(node, tree &) = 0;
	virtual void removeSubTree(node) = 0;

	virtual void writeNode(node, item) = 0;
	virtual item readNode(node) const = 0;

	//template <class V> void BFS(node); //TODO
	//template <class V> void preorder(node); //TODO
	//template <class V> void postorder(node); //TODO
};


#endif /* TREE_H_ */
