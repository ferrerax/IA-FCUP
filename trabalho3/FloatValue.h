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
	virtual ~FloatValue();

	virtual float getValue() = 0;

	virtual void setValue(float value) = 0;
};

#endif /* FLOATVALUE_H_ */
