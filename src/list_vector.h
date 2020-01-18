#ifndef LIST_VECTOR_H_
#define LIST_VECTOR_H_

#include "linear_list.h"
#define DEFAULT_SIZE 10

template <class T>
class list_vector : public linear_list<T, int>{
public:
	//type
	typedef typename linear_list<T, int>::value_type value_type;
	typedef typename linear_list<T, int>::position position;

	//constructor
	list_vector();
	list_vector(int);

	//copy constructor
	list_vector(const list_vector<T> &);

	//destructor
	~list_vector();

	//operator
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const value_type &, position);
	void erase(position);

	int last() const;
	int search(const value_type &) const;
	void remove(position);
	void removeValue(const value_type &);
	void clear();
	void pushBack(const value_type &);
	void pushFront(const value_type &);
	void popBack();
	void popFront();

	list_vector<T> & operator=(const list_vector<T> &);
	bool operator==(const list_vector<T> &) const;

private:
	void _resize(int);
	size_t _size() const {return _dimension;}
	value_type * _elements;
	int _length;
	size_t _dimension;
};

template <class T>
list_vector<T>::list_vector(){
	_dimension = DEFAULT_SIZE;
	create();
}

template <class T>
list_vector<T>::list_vector(int dimension) : _dimension(dimension) {
	create();
}

template <class T>
list_vector<T>::list_vector(const list_vector<T> & copy_list){
	_dimension = copy_list._dimension;
	_length = copy_list._length;
	_elements = new T[_dimension];
	for(int i=0; i<copy_list._dimension; i++)
		_elements[i] = copy_list._elements[i];
}

template <class T>
list_vector<T>::~list_vector(){
	delete [] _elements;
}

template <class T>
void list_vector<T>::create(){
	_elements = new T[_dimension];
	_length = 0;
}

template <class T>
bool list_vector<T>::empty() const {
	return (_length==0);
}

template <class T>
typename list_vector<T>::value_type list_vector<T>::read(position pos) const{
	if((0 < pos) && (pos <= _length+1))
		return (_elements[pos-1]);
}

template <class T>
void list_vector<T>::write(const value_type & e, position pos){
	if((0 < pos) && (pos < _length+1))
		_elements[pos-1] = e;
}

template <class T>
typename list_vector<T>::position list_vector<T>::begin() const {
	return(1);
}

template <class T>
bool list_vector<T>::end(position pos) const {
	/*
	if((0 < pos) && (pos < _lenght+1))
		return (pos == _lenght+1);
	else
		return (false);
	 */
	return ((0 < pos) && (pos <= _length+1)) ? (pos == _length+1) : (false);
}

template <class T>
typename list_vector<T>::position list_vector<T>::next(position pos) const {
	/*
	 if((0 < pos) && (pos < _lenght+1))
		return (pos+1);
	else
		return (pos);
	 */
	return ((0 < pos) && (pos < _length+1)) ? (pos+1) : (pos);
}

template <class T>
typename list_vector<T>::position list_vector<T>::previous(position pos) const {
	/*
	if((1 < pos) && (pos < _lenght+1))
		return (pos-1);
	else
		return (pos);
	 */
	return ((1 < pos) && (pos < _length+1)) ? (pos-1) : (pos);
}

template <class T>
void list_vector<T>::insert(const value_type & e, position pos){
	if((0 < pos) && (pos <= _length+1)){
		if(_dimension == _length)
			_resize(_dimension*2);

		for(int i=0; i<_length; i++)
			_elements[i] = _elements[i-1];
		_elements[pos-1] = e;
		_length++;
	}
}

template <class T>
void list_vector<T>::erase(position pos){
	remove(pos);
}

template <class T>
int list_vector<T>::last() const{
	return (_length > 0) ? (_length-1) : _length;
}

template <class T>
int list_vector<T>::search(const value_type & e) const{
	int i = begin();
	while(!end(i)){
		if(_elements[i] == e)
			return i;
		i = next(i);
	}
	return -1;
}

template <class T>
void list_vector<T>::remove(position pos){
	if((0 < pos) && (pos < _length+1)){ //FIXME <_length
		for(int i=pos; i<_length-1; i++)
			_elements[i] = _elements[i+1];
		_length--;
	}

}

template <class T>
void list_vector<T>::removeValue(const value_type & e){
	remove(search(e));
}

template <class T>
void list_vector<T>::clear(){
	_length = 0; //FIXME
}

template <class T>
void list_vector<T>::pushBack(const value_type & e){
	if(_length >= _dimension)
		_resize(_dimension*2);
	_elements[_length] = e;
	_length++;
}

template <class T>
void list_vector<T>::pushFront(const value_type & e){
	if(_length >= _dimension)
		_resize(_dimension*2);
	for(int i=_length; i>0; i--)
		_elements[i] = _elements[i-1];
	_elements[0] = e;
	_length++;
}

template <class T>
void list_vector<T>::popBack(){
	if(!empty())
		_length--;
}

template <class T>
void list_vector<T>::popFront(){
	if(!empty()){
		for(int i=0; i<_length; i++)
			_elements[i] = _elements[i+1];
		_length--;
	}
}

template <class T>
list_vector<T> & list_vector<T>::operator=(const list_vector<T> & l){
	if(this != &l){
		_dimension = l._dimension;
		_length = l._length;
		delete _elements;
		_elements = new T[_dimension];
		for(int i=0; i<_dimension; i++)
			_elements[i] = l._elements[i];

	}
	return *this;
}

template <class T>
bool list_vector<T>::operator==(const list_vector<T> & l) const{
	if(l._length != _length)
		return false;
	for(int i=0; i<_length; i++) //FIXME maybe _dimension
		if(_elements[i] != l._elements[i])
			return false;
	return true;
}

template <class T>
void list_vector<T>::_resize(int new_size){
	T* tmp = new T[new_size];
	for(int i=0; i<_length; i++)
		tmp[i] = _elements[i];

	delete[] _elements;
	_elements = tmp;
	_dimension = new_size;
}


#endif /* LIST_VECTOR_H_ */
