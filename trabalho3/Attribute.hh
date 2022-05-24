
#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>
#include "ValueType.hh"

using namespace std;

typedef struct {
    string name;
    types_t type;
    int index;
} attribute_t;

#endif
