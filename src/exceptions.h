/*
 * exceptions.h
 *
 *  Created on: Jan 3, 2020
 *      Author: roccodebellis
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>

struct empty_stack:public std::length_error {
	empty_stack():length_error("Empty stack!"){};
};

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

struct full_dictionary : public std::length_error {
	full_dictionary():length_error("Dictionary is full!"){};
};

struct key_not_exist : public std::invalid_argument {
	key_not_exist():invalid_argument("Key does not exist!"){};
};

#endif /* EXCEPTIONS_H_ */
