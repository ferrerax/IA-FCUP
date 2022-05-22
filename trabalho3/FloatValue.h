/*
 * FloatValue.h
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#ifndef FLOATVALUE_H_
#define FLOATVALUE_H_

#include "ValueType.h"

class FloatValue: public ValueType {

private:
	float value;

public:
	FloatValue();
	FloatValue(float in);

	virtual ~FloatValue();

	float getValue() const {
		return value;
	}

	void setValue(float value) {
		this->value = value;
	}
};

#endif /* FLOATVALUE_H_ */
