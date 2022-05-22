/*
 * ValueType.h
 *
 *  Created on: 22 May 2022
 *      Author: madmarx
 */

#ifndef VALUETYPE_H_
#define VALUETYPE_H_

typedef enum {
	STRING,
	INT,
	FLOAT
} types_t;


class ValueType {

private:
	types_t type;

public:
	ValueType();
	virtual ~ValueType();
};

#endif /* VALUETYPE_H_ */
