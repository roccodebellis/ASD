#ifndef PAIR_H_
#define PAIR_H_

#include <iostream>

template <class K, class V>
class pair {
private:
	K key;
	V value;
public:
	pair(){}
	pair(const K key,const V value) {
		this->key = key;
		this->value = value;
	};
	K getKey() {
		return key;
	}
	void setKey(const K key) {
		this->key = key;
	}
	V getValue() {
		return value;
	}
	void setValue(const V value) {
		this->value = value;
	}

	template <class C, class E>
	friend std::ostream & operator<<(std::ostream &, const pair<C, E> &);

};

template <class K, class V>
std::ostream & operator<<(std::ostream & os, const pair<K, V> & p){
	os << "(" << p.key << ", " << p.value << ")";
	return os;
}


#endif /* PAIR_H_ */
