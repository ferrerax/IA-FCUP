/*
 * StringValue.h
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#ifndef STRINGVALUE_H_
#define STRINGVALUE_H_

#include "ValueType.h"
#include <string>

using namespace std;

class StringValue: public ValueType {

private:
	string value;

public:
	StringValue();
	virtual ~StringValue();

	virtual string getValue() = 0;
	virtual void setValue(string value) = 0;
};

#endif /* STRINGVALUE_H_ */
