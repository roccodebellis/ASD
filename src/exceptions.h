/*
 * exceptions.h
 *
 *  Created on: Jan 3, 2020
 *      Author: roccodebellis
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>
#include <iostream>


struct empty_stack:public std::length_error {
	empty_stack():length_error("Empty stack!"){};
};

//QUEUE //PRIORITY_QUEUE
struct empty_queue:public std::length_error {
	empty_queue():length_error("Empty queue!"){};
};

class illegalParameterValue {
public:
	illegalParameterValue() : message("Illegal parameter value") {}
	illegalParameterValue(char * theMessage) {
		message = theMessage;
	}
	void outputMessage() {
		std::cout << message << std::endl;
	}
private:
	char * message;
};

//DICTIONARY
struct full_dictionary : public std::length_error {
	full_dictionary():length_error("Dictionary is full!"){};
};

struct key_not_exist : public std::invalid_argument {
	key_not_exist():invalid_argument("Key does not exist!"){};
};

//BINTREE //TREE
struct node_not_valid : public std::invalid_argument {
	node_not_valid() : invalid_argument("Node not valid!") {};
};

struct full_tree : public std::length_error {
	full_tree() : length_error("Full tree!") {};
};

struct root_exist : public std::invalid_argument {
	root_exist() : invalid_argument("Root already exist!") {};
};

struct empty_tree : public std::length_error {
	empty_tree() : length_error("Empty tree!") {};
};

struct node_exist : public std::invalid_argument {
	node_exist() : invalid_argument("Node already exist!") {};
};

//TREE
struct is_leaf : public std::invalid_argument {
	is_leaf() : invalid_argument("Node does not have child (is a leaf)!") {};
};

struct is_root : public std::invalid_argument {
	is_root() : invalid_argument("Node does not have parent (is the root)!") {};
};

#endif /* EXCEPTIONS_H_ */
