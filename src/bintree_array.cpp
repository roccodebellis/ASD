#include <iostream>
#include "bintree_array.h"

int main(void){
	bintree_array<char> albero;

	//std::cout << albero << std::endl;

	albero.insert_root('h');
	//albero.insert_root(3);

	albero.insert_dx(albero.root(),'c');
	albero.insert_sx(albero.root(),'a');
	albero.insert_sx(albero.child_sx(albero.root()),'d');
	albero.insert_dx(albero.child_sx(albero.root()),'l');

	albero.insert_sx(albero.child_dx(albero.root()),'p');
	albero.insert_dx(albero.child_dx(albero.root()),'s');

	albero.insert_sx(albero.child_dx(albero.child_sx(albero.root())),'o');
	albero.insert_dx(albero.child_dx(albero.child_sx(albero.root())),'q');

	//albero.erase(albero.child_sx(albero.root()));

	std::cout << albero << std::endl;

	std::cout << std::endl << "preordine:" << std::endl;
	albero.pre_view(albero.root());
	std::cout << std::endl << "postordine:" << std::endl;
	albero.post_view(albero.root());
	std::cout << std::endl << "simmetrica:" << std::endl;
	albero.symmetric_view(albero.root());
	return 0;
}
