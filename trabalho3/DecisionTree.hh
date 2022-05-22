
#include<vector>

class DecisionTree
{
private:
    /* data */
    vector<DecisionTree *> children;
    DecisionTree *parent;

    

public:
    DecisionTree(/* args */);
    ~DecisionTree();
};