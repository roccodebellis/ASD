#include "list_vector.h"

int main(void){
	list_vector<int> list;

	for(int i=0; i<10; i++)
		list.pushFront(i);
		//list.insert(i,list.last());
	list.removeValue(10);

	if(list.empty())
		std::cout << "lista vuota" << std::endl;
	else
		std::cout << "lista: " << list << std::endl;
}
