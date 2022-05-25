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
    for (std::string buff; std::getline(is, buff); )
    {
        const auto lineBegin = buff.find_first_not_of(' '); // index to ignore leading spaces
        const auto sep = buff.find(' ');
        string f_token;
        if(sep == string::npos) {
            f_token = buff.substr(lineBegin);
        } else {
            f_token = buff.substr(lineBegin, sep-lineBegin);
        }

        if(f_token[0] == '<') {
            // Atribute!
            this->type = ATTRIBUTE_NODE;
            this->attribute.name = f_token.substr(f_token.at(1), f_token.back()-1); // strip the < >
        } else {
            // value description
            string s_token; // Per trobar el valor de la classe
            if(sep != string::npos) {
                s_token = buff.substr(sep+1);
                string className = s_token.substr(0, s_token.find_first_not_of(' '));
                attribute_t att;
                DecisionTree * child = new DecisionTree(att, className, LEAF_NODE);
                this->setCount(stoi(s_token.substr(s_token.find('('), s_token.back()-s_token.find('(')-1)));
                this->addChild(child, f_token.substr(f_token.at(0), f_token.back() - 1));
            } else {
                DecisionTree *child = new DecisionTree(is);
                this->addChild(child, f_token.substr(f_token.at(0), f_token.back() - 1));
            }
        }
    }
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