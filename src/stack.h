/*
 * stack.h
 *
 *  Created on: Jan 2, 2020
 *      Author: roccodebellis
 */

#ifndef STACK_H_
#define STACK_H_

template <class T>
class stack{
public:
	typedef T value_type;

	//constructors
	virtual void create()=0;
	virtual bool empty() const=0;
	virtual value_type top() const=0; //TODO value_type&
	virtual void push(const value_type)=0;
	virtual void pop()=0;

	//destructor
	//virtual ~stack()=0; //TODO

	//virtual std::ostream& operator<<(std::ostream&, const stack&) const=0;
};



#endif /* STACK_H_ */
