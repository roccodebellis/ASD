#include "tree_link.h"
#include <iostream>
/* TEST
int main(void){
	std::cout << "main()"<< std::endl; //DELETE
	tree_link<char> tree,traa;

	tree_link<char>::node root, node;

	tree.insertRoot('r');
	root = tree.root();
	tree.insertFirst(root,'a');
	node = tree.firstChild(root);
	tree.insert(node,'b');
	tree.insertFirst(node,'d');
	tree.insertFirst(node,'c');

	tree.print();

	std::cout << std::endl;
	traa.insertRoot('z');
	root = traa.root();
	traa.insertFirst(root,'x');
	node = traa.firstChild(root);
	traa.insert(node,'y');

	traa.print();


	std::cout << std::endl;
	tree.insertSubTree(tree.firstChild(tree.root()),traa);//tree.insertFirstSubTree(tree.firstChild(tree.root()),traa);
	tree.print();

	std::cout << "-main()"<< std::endl; //DELETE

	//int x;
	//std::cin >> x;
	//return 0;
}
*/
