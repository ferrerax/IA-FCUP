/*
 * IntValue.h
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#ifndef INTVALUE_HH_
#define INTVALUE_HH_

#include "ValueType.hh"

class IntValue: public ValueType {
private:
	int value;

public:
	IntValue();
	IntValue(int in);
	virtual ~IntValue();

	int getValue() const {
		return value;
	}

	void setValue(int value) {
		this->value = value;
	}
};

#endif /* INTVALUE_HH_ */
