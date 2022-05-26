
#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>
#include <set>

using namespace std;

typedef enum
{
    STRING,
    INT,
    FLOAT,
    NO_TYPE
} types_t;

typedef struct {
    string name;
    types_t type;
    int index;
    set<string> possible_values;
} attribute_t;

#endif
