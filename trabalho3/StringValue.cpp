/*
 * StringValue.cpp
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#include "StringValue.hh"

StringValue::StringValue() {
	type = STRING;
	value = "";
}

StringValue::StringValue(string s) {
	type = STRING;
	value = s;
}

StringValue::~StringValue() {
	// TODO Auto-generated destructor stub
}

