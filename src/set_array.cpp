#include "set_array.h"

/* TEST
int main(void){
	set_array<int> a;
	set_array<int> b;
	set_array<int> b2(20);

	std::cout << a << std::endl;

	for(int i=0; i<10; i++)
		a.insert(i);

	if(a.empty())
		std::cout << "Insieme vuoto!" << std::endl;
	else
		std::cout << "a: " << a << std::endl;

	for(int i=0; i<10; i++)
		b.insert(i);

	b.remove(5);
	//b.remove(11);

	if(b.empty())
		std::cout << "Insieme vuoto!" << std::endl;
	else
		std::cout << "b: " << b << std::endl;

	std::cout << "aUb: " << a.uni(b) << std::endl;
	std::cout << "bUa: " << b.uni(a) << std::endl;
	std::cout << "a intersezione b: " << a.intersection(b) << std::endl;
	std::cout << "b intersezione a: " << b.intersection(a) << std::endl;
	std::cout << "a-b: " << a.difference(b) << std::endl;
	std::cout << "b-a: " << b.difference(a) << std::endl;


} */
