
#ifndef DESTREE_H_
#define DESTREE_H_

#include <vector>
#include "Attribute.hh"

class DecisionTree
{
private:
    /* data */
    vector<DecisionTree *> children;
    DecisionTree *parent;

    attribute_t attribute;
    string classValue;
    string branchValue;

public:
    DecisionTree(/* args */);
    ~DecisionTree();

    void print_representation();
    void store_tree();
};

#endif
