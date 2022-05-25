#ifndef DESTREE_H_
#define DESTREE_H_

#include <vector>
#include <string>
#include "Attribute.hh"
#include <ostream>
#include <istream>

using namespace std;

typedef enum {
    ATTRIBUTE_NODE,
    LEAF_NODE
} node_t;

typedef vector<pair<types_t, vector<string>>> dataset_t;

class DecisionTree
{
private:
    /* data */
    vector<DecisionTree *> children;
    DecisionTree *parent;

    attribute_t attribute;
    string classValue;
    int countClassification;
    string branchValue;
    node_t type; // 0 -> attribute, 1 -> class

public:
    DecisionTree(string branch, DecisionTree *parent);
    DecisionTree(attribute_t at, string classname, node_t type);
    DecisionTree(istream &is);
    ~DecisionTree();

    void print_representation(ostream &os, string tab = "");

    void assignAttributeIndexes(dataset_t &examples, vector<attribute_t> at_list);
    vector<string> classify(dataset_t &examples, vector<attribute_t> at_list);
    string evaluate(vector<string> ex);

    void addChild(DecisionTree * c, string branch);

    void setParent(DecisionTree * p);
    void setBranch(string branchName);
    void setCount(int count);
};

#endif
