#include "DecisionTree.hh"
#include<string>
using namespace std;

DecisionTree::DecisionTree(string branch, DecisionTree *parent)
{
    
}

DecisionTree::DecisionTree(attribute_t at, string classname, node_t type) {
    this->type = type;
    if(type == ATTRIBUTE_NODE) {
        this->attribute = at;
        this->classValue = "";
    } else {
        this->classValue = classname;
    }
}

DecisionTree::DecisionTree(istream &is)
{
    
}

DecisionTree::~DecisionTree()
{
}

void DecisionTree::print_representation(ostream &os, string tab)
{
    if(type == ATTRIBUTE_NODE) {
        if(parent != nullptr) os << endl;
        os << tab << "<" << this->attribute.name << ">" << endl;
    } else {
        os << " " << this->classValue << " (" << countClassification << ")" << endl;
    }

    for (size_t i = 0; i < children.size(); i++)
    {
        os << tab << "    " << children[i]->branchValue << ":";
        children[i]->print_representation(os, tab+"        ");
    }
    

}

void DecisionTree::addChild(DecisionTree * c, string branch) {
    children.push_back(c);
    c->setParent(this);
    c->setBranch(branch);
}

void DecisionTree::setParent(DecisionTree *p) {
    this->parent = p;
}

void DecisionTree::setBranch(string branchName) {
    this->branchValue = branchName;
}

void DecisionTree::setCount(int count)
{
    countClassification = count;
}