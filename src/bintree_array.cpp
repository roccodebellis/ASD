#include <iostream>
#include "bintree_array.h"
/* TEST
int main(void){
	bintree_array<char> albero;

	//std::cout << albero << std::endl;

	albero.insert_root('h');
	//albero.insert_root(3);

	albero.insert_right(albero.root(),'c');
	albero.insert_left(albero.root(),'a');
	albero.insert_left(albero.left(albero.root()),'d');
	albero.insert_right(albero.left(albero.root()),'l');

	albero.insert_left(albero.right(albero.root()),'p');
	albero.insert_right(albero.right(albero.root()),'s');

	albero.insert_left(albero.right(albero.left(albero.root())),'o');
	albero.insert_right(albero.right(albero.left(albero.root())),'q');

	//albero.erase(albero.left(albero.root()));

	std::cout << albero << std::endl;

	std::cout << std::endl << "preordine:" << std::endl;
	albero.pre_view(albero.root());
	std::cout << std::endl << "postordine:" << std::endl;
	albero.post_view(albero.root());
	std::cout << std::endl << "simmetrica:" << std::endl;
	albero.symmetric_view(albero.root());
	return 0;
}
*/
