/*
 * stack_pointer.cpp
 *
 *  Created on: Jan 3, 2020
 *      Author: roccodebellis
 */

#include "stack_pointer.h"
/* TEST
int main(void){
	stack_pointer<int> stack;
	stack_pointer<int> stack2;

	//stack.pop();

	if(stack.empty())
		std::cout << "Pila vuota!" << std::endl;
	else
		std::cout << "Pila piena!" << std::endl;

	for(int i=0; i<10; i++)
		stack.push(i+1);

	if(stack.empty())
		std::cout << "Pila vuota!" << std::endl;
	else
		std::cout << "Pila piena!" << std::endl;

	std::cout << "stack: " << stack << std::endl;

	for(int i=0; i<20; i++)
		stack2.push(i+1);

	std::cout << "stack2: " << stack2 << std::endl;

	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();

	std::cout << "stack2: " << stack2 << std::endl;

	stack_pointer<int> stack3(stack2);
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	std::cout << "stack2: " << stack2 << std::endl;
	std::cout << "stack3: " << stack3 << std::endl;

	//std::cout << stack3.top();
	stack2 = stack3;
	std::cout << "stack2: " << stack2 << std::endl;
	std::cout << "stack3: " << stack3 << std::endl;
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();

	std::cout << "stack2: " << stack2 << std::endl;
	std::cout << "stack3: " << stack3 << std::endl;
	//system("pause");
	//return EXIT_SUCCESS;
	return 0;
}
*/
