#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

template <class T>
class priority_queue {
public:
	typedef T value_type;

	virtual void create() = 0;
	virtual bool empty() const = 0;
	virtual void insert(value_type) = 0;
	virtual value_type min() const = 0;
	virtual void remove_min() = 0;
};


#endif /* PRIORITY_QUEUE_H_ */
