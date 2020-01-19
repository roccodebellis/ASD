#include "tree_pointer.h"
#include <iostream>
/* TEST
int main(void){
	tree_list_pointer<char> tree;

	tree_list_pointer<char>::node n = new Record<char>();

	tree.insertRoot(n);


	tree.writeNode(tree.root(),'a');

	tree.insertFirst(tree.root(), 'b');
	n = tree.firstChild(tree.root());
	tree.insertFirst(tree.root(), 'c');

	tree.insertFirst(tree.root(), 'd');
	n = tree.firstChild(tree.root());
	tree.insertFirst(tree.root(), 'e');
	tree.insertFirst(tree.firstChild(tree.root()), 'f');

	tree.insertFirst(tree.nextSibling(tree.firstChild(tree.root())),'h');
	tree.insertFirst(tree.nextSibling(tree.firstChild(tree.root())),'l');
	tree.insertFirst(tree.nextSibling(tree.firstChild((tree.nextSibling(tree.firstChild(tree.root()))))),'k');

	tree.print();
	std::cout << std::endl << std::endl;
	tree_list_pointer<char> Tree2 = tree;
	Tree2.print();
	std::cout << std::endl << std::endl;
	tree.insertSubTree(tree.firstChild(tree.root()),Tree2);
	tree.print();
	//std::cout << std::endl << std::endl;
	//Tree2.print();

	//int x;
	//cin>>x;
	//return 0;

}
*/
