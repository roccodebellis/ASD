#ifndef LINEAR_LIST_H_
#define LINEAR_LIST_H_

#include <iostream>

//abstract class linearList
template <class T, class P>
class linear_list {
public:
	//type
	typedef T value_type;
	typedef P position;

	//operators
	virtual void create() = 0;
	virtual bool empty() const = 0;
	virtual value_type read(position) const = 0;
	virtual void write(const value_type &, position) = 0;
	virtual position begin() const = 0;
	virtual bool end(position) const = 0;
	virtual position next(position) const = 0;
	virtual position previous(position) const = 0;
	virtual void insert(const value_type &, position) = 0;
	virtual void erase(position) = 0;

	//service function
	//friend std::ostream & operator<<(std::ostream &, const linear_list<T,P> &);
	int size() const;
	//virtual int size() const;
	//virtual void push_front(const value_type &);
	//virtual void push_back(const value_type &);
	//virtual void pop_front();
	//virtual void clear();
};

template <class T, class P>
std::ostream & operator<<(std::ostream & os, const linear_list<T,P> & list){
	typename linear_list<T,P>::position pos;
	pos = list.begin();
	os << "[";
	while(!list.end(pos)){
		if(pos != list.begin())
			os << ", " << list.read(pos);
		else
			std::cout << list.read(pos);
		pos = list.next(pos);
	}
	os << "]" << std::endl;
	return os;
}

template <class T, class P>
int linear_list<T,P>::size() const{
	int size = 0;
	position pos = begin();
	while(!end(pos)){
		size++;
	}
	pos = next(pos);
	return size;
}


#endif /* LINEAR_LIST_H_ */
