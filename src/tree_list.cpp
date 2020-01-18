#include "tree_list.h"
/* TEST
int main(void){
	tree_list<char> t;
	tree_list<char>::node n;

	t.insertRoot(n);
	t.writeNode(t.root(),'a');

	t.insertFirst(t.root(),'b');
	t.insertFirst(t.root(),'c');

	n = t.root();
	n = t.firstChild(n);

	t.insert(n,'d');

	n = t.root();
	n = t.firstChild(n);

	t.insertFirst(n,'e');
	t.insertFirst(n,'f');

	t.print();

	n = t.root();
	n = t.firstChild(n);

	t.removeSubTree(n);
	std::cout << "------" << std::endl;
	t.print();

}
*/
