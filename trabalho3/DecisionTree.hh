
#include<vector>
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
};