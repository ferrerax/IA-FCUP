#include "DecisionTree.hh"
#include<string>
#include<stack>

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
        const auto sep = buff.find(' ', lineBegin);
        string f_token;
        if(sep == string::npos) {
            f_token = buff.substr(lineBegin);
        } else {
            f_token = buff.substr(lineBegin, sep-lineBegin);
        }

        if(f_token[0] == '<') {
            // Atribute!
            this->type = ATTRIBUTE_NODE;
            this->attribute.name = f_token.substr(1, f_token.size()-2); // strip the < >
        } else {
            // value description
            string s_token; // Per trobar el valor de la classe
            if(sep != string::npos) {
                s_token = buff.substr(sep+1);
                string className = s_token.substr(0, s_token.find(' '));
                attribute_t att;
                DecisionTree * child = new DecisionTree(att, className, LEAF_NODE);
                string count = s_token.substr(s_token.find('(')+1, s_token.size()-s_token.find('(')-2);
                child->setCount(stoul(count));
                this->addChild(child, f_token.substr(0, f_token.size()-1));
            } else {
                DecisionTree *child = new DecisionTree(is);
                this->addChild(child, f_token.substr(0, f_token.size()-1));
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
        string newtab = tab + "        ";
        children[i]->print_representation(os, newtab);
    }
    

}

void DecisionTree::assignAttributeIndexes(dataset_t &examples, vector<attribute_t> at_list)
{
    auto aux = at_list;
    stack<DecisionTree *> stack;
    stack.push(this);
    DecisionTree *node;

    while (!stack.empty())
    {
        node = stack.top();
        stack.pop();

        if (node->type == ATTRIBUTE_NODE)
        {
            for (auto &&a : aux)
            {
                if (node->attribute.name == a.name)
                    node->attribute.index = a.index;
            }
            for (size_t i = 0; i < node->children.size(); i++)
            {
                stack.push(children[i]);
            }
        }
    }
}



vector<string> DecisionTree::classify(dataset_t &examples, vector<attribute_t> at_list)
{
    vector<string> result;
    result.reserve(examples[0].second.size());

    // First, connect the tree attributes with dataset column indexes
    this->assignAttributeIndexes(examples, at_list);

    vector<string> aux_example;
    for (size_t i = 0; i < examples[0].second.size(); i++)
    {
        for (size_t j = 0; j < examples.size(); j++)
        {
            aux_example.clear();
            aux_example.push_back(examples[j].second[i]);
            result.push_back(evaluate(aux_example));
        }
    }
    return result;
}

string DecisionTree::evaluate(vector<string> ex)
{
    if(type == LEAF_NODE) return classValue;
    for (auto &&child : children)
    {
        if(child->branchValue == ex[attribute.index])
            return child->evaluate(ex);
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