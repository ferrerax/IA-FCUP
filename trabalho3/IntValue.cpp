/*
 * IntValue.cpp
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#include "IntValue.hh"

IntValue::IntValue() {
	type 	= INT;
	value 	= 0;
}

IntValue::IntValue(int in) {
	type = INT;
	value = in;
}

IntValue::~IntValue() {
	// TODO Auto-generated destructor stub
}

