/*
 * IntValue.h
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#ifndef INTVALUE_H_
#define INTVALUE_H_

#include "ValueType.h"

class IntValue: public ValueType {
private:
	int value;

public:
	IntValue();
	virtual ~IntValue();
};

#endif /* INTVALUE_H_ */
