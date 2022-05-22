/*
 * StringValue.h
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#ifndef STRINGVALUE_H_
#define STRINGVALUE_H_

#include "ValueType.h"

class StringValue: public ValueType {

private:
	float value;

public:
	StringValue();
	virtual ~StringValue();
};

#endif /* STRINGVALUE_H_ */
