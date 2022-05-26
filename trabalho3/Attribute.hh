
#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>
#include <set>
#include "ValueType.hh"

using namespace std;

typedef struct {
    string name;
    types_t type;
    int index;
    set<string> possible_values;
} attribute_t;

#endif
