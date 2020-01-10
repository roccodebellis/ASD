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


#endif /* EXCEPTIONS_H_ */
