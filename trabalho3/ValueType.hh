/*
 * ValueType.h
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#ifndef VALUETYPE_HH_
#define VALUETYPE_HH_

typedef enum {
	STRING,
	INT,
	FLOAT,
	NO_TYPE
} types_t;

class ValueType {

protected:
	types_t type;

public:
	ValueType();
	virtual ~ValueType();
};

#endif /* VALUETYPE_HH_ */
