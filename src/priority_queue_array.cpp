#include "priority_queue_array.h"
#include <iostream>
/* TEST */
int main(void) {
	priority_queue_array<int> C;



	C.insert (3);
	C.insert (5);

	C.insert (9);
	C.insert (6);
	C.insert (8);
	C.insert (13);
	C.insert (12);
	C.insert (11);
	C.insert (18);
	C.insert (10);





	std::cout << C << std::endl;

	std::cout << C.min() << std::endl;

	C.remove_min();

	//C.remove_min();
	//C.insert (4);


	C.print();

	//C.remove_min ();

	//std::cout << "Min: " << C.min() << std::endl;

}

