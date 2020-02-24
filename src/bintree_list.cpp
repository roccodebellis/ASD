#include "bintree_list.h"
/* TEST */
int main(void){
	bintree_list<char> albero;

	//std::cout << albero << std::endl;

	albero.insertRoot('h');
	//albero.insert_root(3);
	albero.insertRight(albero.root(),'c');
	albero.insertLeft(albero.root(),'a');
	albero.insertLeft(albero.left(albero.root()),'d');
	albero.insertRight(albero.left(albero.root()),'l');

	albero.insertLeft(albero.right(albero.root()),'p');
	albero.insertRight(albero.right(albero.root()),'s');

	albero.insertLeft(albero.right(albero.left(albero.root())),'o');
	albero.insertRight(albero.right(albero.left(albero.root())),'q');

	//albero.erase(albero.left(albero.root()));

	//std::cout << albero << std::endl;

	std::cout << std::endl << "preordine:" << std::endl;
	albero.pre_view(albero.root());
	std::cout << std::endl << "postordine:" << std::endl;
	albero.post_view(albero.root());
	std::cout << std::endl << "simmetrica:" << std::endl;
	albero.symmetric_view(albero.root());


	bintree_list<int> tree;

	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(10);
	tree.insert(11);
	tree.insert(12);

	std::cout << std::endl << "preordine:" << std::endl;
	tree.pre_view(tree.root());
	std::cout << std::endl << "postordine:" << std::endl;
	tree.post_view(tree.root());
	std::cout << std::endl << "simmetrica:" << std::endl;
	tree.symmetric_view(tree.root());
	std::cout << "minimum: " << tree.minimum(tree.root()) << std::endl;
	std::cout << "maximum: " << tree.maximum(tree.root()) << std::endl;
	auto cinque = tree.search(tree.root(),5);
	std::cout << "search: " << cinque << std::endl;
	std::cout << "successor: " << tree.successor(cinque) << std::endl;
	std::cout << "predecessor: " << tree.predecessor(cinque) << std::endl;



	return 0;
}

