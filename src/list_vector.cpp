#include "list_vector.h"
/* TEST
int main(void){
	list_vector<int> list;

	for(int i=0; i<10; i++)
		list.pushBack(i);
	//list.insert(i,list.last());


	std::cout << "begin: " << list.begin() << std::endl;
	std::cout << "end: " << list.last() << std::endl;

	std::cout << "lista: " << list << std::endl;

	//list.remove(list.last());
	std::cout << "end: " << list.last() << std::endl;
	std::cout << "last: " << list.read(list.last()) << std::endl;
	list.insert(10,list.last()+1);
	list.insert(-1,list.begin());
	list.insert(-1,list.last());
	list.insert(-1,list.last()+1);
	list.insert(1,list.last());
	list.insert(3,list.last()+1);
	list.insert(1,list.last());
	list.insert(11,list.last()+1);
	list.insert(4,list.last());
	list.insert(2,list.last()+1);

	if(list.empty())
		std::cout << "lista vuota" << std::endl;
	else
		std::cout << "lista: " << list << std::endl;


	list.epurazione();
	//list.remove(list.begin());

	std::cout << "listaaa : [";
	int it = list.begin();
	while(!list.end(it)){
		std::cout << list.read(it) << " ";
		it = list.next(it);
	}
	std::cout << "]" << std::endl;

}
*/
