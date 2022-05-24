/*
 * StringValue.h
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#ifndef STRINGVALUE_HH_
#define STRINGVALUE_HH_

#include <string>
#include "ValueType.hh"

using namespace std;

class StringValue: public ValueType {

private:
	string value;

public:
	StringValue();
	StringValue(string s);
	virtual ~StringValue();

	const string& getValue() const {
		return value;
	}

	void setValue(const string &value) {
		this->value = value;
	}
};

#endif /* STRINGVALUE_HH_ */
