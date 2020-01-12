#ifndef SET_H_
#define SET_H_


template <class T>
class set {
public:
	typedef T value_type;

	//operators
	virtual void create()=0;
	virtual bool empty() const=0;
	virtual bool contains(const value_type) const=0;
	virtual void insert(const value_type)=0;
	virtual void remove(const value_type)=0;

};

#endif /* SET_H_ */
