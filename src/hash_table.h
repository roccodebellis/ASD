#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include "dictionary.h"
#include "pair.h"
#include <string>
#include "exceptions.h" //full_dictionary()
#include <iostream>
#include <cctype> //toupper()
#include <bitset> //bitset<>
#include <cmath> //floor

const int MAX_DIMENSION = 23;

template <class E>
class hash_table : public dictionary<std::string,E> {
public:
	//type
	typedef typename dictionary<std::string,E>::key key;
	typedef typename dictionary<std::string,E>::value element;

	//constructors
	hash_table();
	hash_table(int);

	//copy constructor
	hash_table(const hash_table<element> &);

	//destructor
	~hash_table();

	//operators
	void create();
	bool empty() const;
	bool contains(const key) const;
	void insert(const key, const element);
	void erase(const key);
	element find(const key) const;
	void modify(const key, const element);


	//service functions
	template <class F>
	friend std::ostream & operator<<(std::ostream &, const hash_table<F> &);
private:
	pair<key,element> * table;
	int dimension;
	int size;

	//private service functions
	void change_dimension(const int);
	int hash(const key) const;
	int search(const key) const;

};

template <class E>
hash_table<E>::hash_table() {
	dimension = MAX_DIMENSION;
	size = 0;
	create();
}

template <class E>
hash_table<E>::hash_table(int dimension) {
	this->dimension = dimension;
	size = 0;
	create();
}

template <class E>
hash_table<E>::hash_table(const hash_table<element> & copy_hash) {
	dimension = copy_hash.dimension;
	size = copy_hash.size;
	create();
	for(int i=0; i<dimension; i++){
		table[i].setKey(copy_hash.table[i].getKey());
		table[i].setValue(copy_hash.table[i].getValue());
	}
}

template <class E>
hash_table<E>::~hash_table() {
	delete[] table;
}

template <class E>
void hash_table<E>::create() {
	table = new pair<hash_table<E>::key, hash_table<E>::element>[dimension];
	for(int i=0; i<dimension; i++)
		table[i].getKey() = "";
	return;
}

template <class E>
bool hash_table<E>::empty() const {
	return size == 0;
}

template <class E>
bool hash_table<E>::contains(const hash_table<E>::key key) const{
	int i = search(key);
	return (table[i].getKey()==key) ? true : false;
}

template <class E>
void hash_table<E>::insert(const hash_table<E>::key key, const hash_table<E>::element element) {
	int i = search(key);
	if(table[i].getKey() == "") {
		table[i].setKey(key);
		table[i].setValue(element);
		size++;
	} else {
		if(table[i].getKey() == key)
			table[i].setValue(element);
		else
			throw full_dictionary();
	}
}

template <class E>
void hash_table<E>::erase(const hash_table<E>::key key) {
	int i = search(key);
	if(table[i].getKey() == key){
		table[i].getKey() == "";
		size--;
	}
	return;
}

template <class E>
typename hash_table<E>::element hash_table<E>::find(const hash_table<E>::key key) const{
	element el; //maybe sara errore TODO
	int i = search(key);
	if(table[i].getKey() == key)
		el = table[i].getValue();
	else
		throw key_not_exist();
	return el;
}

template <class E>
void hash_table<E>::modify(const hash_table<E>::key key, const hash_table<E>::element element){
	int i = search(key);
	if(table[i].getKey() == key)
		table[i].setValue(element);
	else
		throw key_not_exist();
	return;
}

template <class E>
void hash_table<E>::change_dimension(const int new_dimension) {
	if(new_dimension > dimension){
		pair<hash_table<E>::key, hash_table<E>::element> * temp = new pair<hash_table<E>::key, hash_table<E>::element>[new_dimension];
		for(int i=0; i<dimension; i++){
			temp[i].setKey(table[i].getKey());
			temp[i].setValue(table[i].getValue());
		}
		dimension = new_dimension;
		delete[] table;
		table = temp;
	}
	return;
}

template <class E>
int hash_table<E>::hash(const hash_table<E>::key key) const{
	/* hash-0
	int b = 0;
	int l = key.length();
	for(int i=0; i<l; i++)
		b += (int) key[i];

	std::cout << "hash: " << key << "->" << b << std::endl; //TODO delete
	return b;
	*/

	/* hash-3      (ha il vantaggio di essere indipendente dal valore m)
	 * i = int(bin(key))
	 * m = max_dimension
	 * C = (sqrt(5)-1)/2
	 * H(key) = floor(m(iC-floor(iC)))
	 */
	int bit = 6; //numero di bit per rapp ciascun carattere delle chiave
	int C = (sqrt(5)-1)/2;
	int i = 0;

	for(int j=0; j<key.length(); j++){
		std::bitset<8> ord(std::toupper(key[j]));//per caratteri e numeri fino al 6 bit sono uguali
		i += (2^bit^(key.length()-j))* std::stoi(ord.to_string(), nullptr, 2);
	}
	//return std::floor(dimension*(i*C - floor(i*C))); //hash-3
	/* hash-4
	 * presuppone che m sia dispari
	 * fornisce una migliore distribuzione se m è primo non troppo vicino
	 * ad una potenza di 2. Alcuni valori adeguati per m sono:
	 * 13, 23, 47, 97, 193, 383, 769, 1531, 3067, 6143, 12289, 24571
	 *
	 */
	return i/dimension  % dimension; //hash-4



}

template <class E>
int hash_table<E>::search(const hash_table<E>::key key) const{
	int i = hash(key) % dimension;
	int j = i;
	do {
		if(table[j].getKey() == "" || table[j].getKey()==key)
			break;//return j; //
		j = (j+1) % dimension;
	} while(j!=i);
	return j;
}

template <class E>
std::ostream & operator<<(std::ostream & os, const hash_table<E> & h){
	int cout = 0;
	int j;
	os << "[";
	for (int i=0; i<h.dimension && cout<h.size; i++){
		if(h.table[i].getKey() != ""){
			cout++;
			os << h.table[i];
			if(cout != h.size)
				os << ", ";
		}
	}
	os << "]";
	return os;
}


#endif /* HASH_TABLE_H_ */
