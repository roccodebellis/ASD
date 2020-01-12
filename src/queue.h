/*
 * queue.h
 *
 *  Created on: Jan 4, 2020
 *      Author: roccodebellis
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template <class T>
class queue {
public:
	typedef T value_type;

	//operators
	virtual void create()=0;
	virtual bool empty() const=0;
	virtual value_type top() const=0;
	virtual void dequeue()=0;
	virtual void enqueue(const value_type)=0;
};



#endif /* QUEUE_H_ */
