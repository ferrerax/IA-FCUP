/*
 * FloatValue.cp
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#include "FloatValue.hh"

FloatValue::FloatValue() {
	type = FLOAT;
	value = 0.0;
}

FloatValue::FloatValue(float in) {
	type = FLOAT;
	value = in;
}

FloatValue::~FloatValue() {
	// TODO Auto-generated destructor stub
}

