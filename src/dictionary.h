#ifndef DICTIONARY_H_
#define DICTIONARY_H_

template <class K, class V>
class dictionary {
public:
	typedef K key;
	typedef V value;

	virtual void create()=0;
	virtual bool empty() const=0;
	virtual bool contains(const key) const =0;
	virtual void insert(const key, const value)=0;
	virtual void erase(const key)=0;
	virtual value find(const key) const=0;
	virtual void modify(const key, const value)=0;

};



#endif /* DICTIONARY_H_ */
