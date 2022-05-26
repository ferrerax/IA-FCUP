
#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>


typedef enum {
	STRING,
	INT,
	FLOAT,
	NO_TYPE
} types_t;

using namespace std;

typedef struct {
    string name;
    types_t type;
    int index;
} attribute_t;

#endif
