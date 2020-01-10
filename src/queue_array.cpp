#import "queue_array.h"

/* TEST */
int main(void){
	queue_array<int> queue;
	queue_array<int> queue2(20);

	if(queue.empty())
		std::cout << "Pila vuota!" << std::endl;
	else
		std::cout << "Pila piena!" << std::endl;


	for(int i=0; i<10; i++)
		queue.enqueue(i);

	std::cout << "queue: " << queue << std::endl;


	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();

	std::cout << "queue: " << queue << std::endl;

	for(int i=0; i<10; i++)
			queue.enqueue(i);

	std::cout << "queue: " << queue << std::endl;

	std::cout << "===============" << std::endl;

	if(queue.empty())
		std::cout << "Pila vuota!" << std::endl;
	else
		std::cout << "Pila piena!" << std::endl;


	for(int i=0; i<10; i++)
		queue2.enqueue(i);

	std::cout << "queue2: " << queue2 << std::endl;

	queue2.enqueue(26);
	std::cout << "queue2: " << queue2 << std::endl;
	queue2.dequeue();
	std::cout << "queue2: " << queue2 << std::endl;
	queue2.dequeue();
	std::cout << "queue2: " << queue2 << std::endl;

	std::cout << "queue2.top() : " << queue2.top() << std::endl;

	queue_array<int> queue3(queue2);
	queue3.dequeue();
	queue3.dequeue();
	std::cout << "queue3: " << queue3 << std::endl;
	std::cout << "queue2: " << queue2 << std::endl;

	queue_array<char> fifo;
	fifo.enqueue('F'); std::cout << "1queue2: " << fifo << std::endl;
	fifo.enqueue('I');std::cout << "2queue2: " << fifo << std::endl;
	fifo.enqueue('R');std::cout << "3queue2: " << fifo << std::endl;
	fifo.enqueue('S');std::cout << "4queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "5queue2: " << fifo << std::endl;
	fifo.enqueue('T');std::cout << "6queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "7queue2: " << fifo << std::endl;
	fifo.enqueue('I');std::cout << "8queue2: " << fifo << std::endl;
	fifo.enqueue('N');std::cout << "9queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "10queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "11queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "12queue2: " << fifo << std::endl;
	fifo.enqueue('F');std::cout << "13queue2: " << fifo << std::endl;
	fifo.enqueue('I');std::cout << "14queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "15queue2: " << fifo << std::endl;
	fifo.enqueue('R');std::cout << "16queue2: " << fifo << std::endl;
	fifo.enqueue('S');std::cout << "17queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "18ueue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "19queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "20queue2: " << fifo << std::endl;
	fifo.enqueue('T');std::cout << "21queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "22queue2: " << fifo << std::endl;
	fifo.enqueue('O');std::cout <<"23queue2: " << fifo << std::endl;
	fifo.enqueue('U');std::cout << "24queue2: " << fifo << std::endl;
	fifo.enqueue('T');std::cout << "25queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "26queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "27queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "28queue2: " << fifo << std::endl;
	fifo.dequeue();std::cout << "29queue2: " << fifo << std::endl;


	queue_array<int> queue4;
	queue4 = queue;
	queue_array<int> queue5 = queue;

	std::cout << "queue: " << queue << std::endl;
	std::cout << "copia: " << queue5 << std::endl;
	std::cout << "asseg: " << queue4 << std::endl;

	//system("pause");
	//return EXIT_SUCCESS;
	return 0;
}



