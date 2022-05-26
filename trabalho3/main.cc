#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <regex>
#include <vector>
#include <utility>
#include <iostream>
#include <map>

#include "DecisionTree.hh"
#include "Attribute.hh"
#include "ValueType.hh"
#include "Importance.hh"

using namespace std;

typedef vector<int> 	v_int;
typedef vector<float> 	v_float;
typedef vector<string> 	v_string;
typedef vector< pair< types_t, vector<string> > > dataset_t;

vector<attribute_t> att_list;

char *getCmdOption(char **begin, char **end, const std::string &option)
{
	char **itr = std::find(begin, end, option);
	if (itr != end && ++itr != end)
	{
		return *itr;
	}
	return 0;
}

void Usage()
{
	std::cout << "Usage: ./trabalho3 command <file.csv> [<tree.txt>]" << std::endl;
	std::cout << "Commands:" << endl <<
				 "    learn: creates a decision tree from dataset <file.csv>" << endl <<
				 "    test:  imports the decision tree in <tree.txt> and tests with the <file.csv> dataset" << endl;
	exit(1);
}

types_t get_type(string s){

	types_t result;


	if(regex_match(s, regex("^[0-9]*$")))
	{
		result = INT;
	}
	else if(regex_match(s, regex("[+-]?([0-9]*[.])?[0-9]+")))
	{
		result = FLOAT;
	}
	else
	{
		result = STRING;
	}

	return result;
}

dataset_t read_csv(string file, vector<attribute_t> & attributes, bool & id)
{
	// File pointer
	    fstream fin;
	    stringstream s;

	    // Open an existing file
	    fin.open(file, ios::in);

	    dataset_t result;
	    string line, word, temp;

	    //First time

	    getline(fin, line);
	    s = stringstream(line);
		int index_atts = 0;
		while(getline(s,word,',')){
	    	if(word == "ID"){
	    		id = true;
	    	}
			attribute_t at;
			at.name = word;
			at.index = index_atts;
	    	attributes.push_back(at);
			index_atts++;
	    }

	    getline(fin, line);		//Reading first line of data.

	    // used for breaking words
	    s = stringstream(line);
		index_atts = 0;
	    while (getline(s, word, ',')) {			//Setting values and types. TODO: missings
	    	vector<string> aux;
	    	switch(get_type(word)){
	    	case FLOAT:
	    		aux.push_back(word);
	    		result.push_back(make_pair(FLOAT, aux));
				attributes[index_atts].type = FLOAT;
	    		break;
	    	case INT:
	    		aux.push_back(word);
	    		result.push_back(make_pair(INT, aux));
				attributes[index_atts].type = INT;
				break;
	    	case STRING:
	    		aux.push_back(word);
	    		result.push_back(make_pair(STRING, aux));
				attributes[index_atts].type = STRING;
				break;
	    	}
			index_atts++;
	    }

	    int i = 0; //vector iterator

	    while (!fin.eof()) {
	    	getline(fin, line);
	    	stringstream f(line);
	    	while (getline(f, word, ',')) {			//Setting values and types
				result[i].second.push_back(word);
	    		i = (i+1)%result.size();
	    	}
	    }
	return result;
}

string same_classification(dataset_t examples)
{
	if(std::adjacent_find(examples.back().second.begin(), examples.back().second.end(), std::not_equal_to<string>()) == examples.back().second.end()) {
		return examples.back().second.front();
	} else return "";
}

DecisionTree *plurality_value(dataset_t examples)
{
	set<string> s = set<string>(examples.back().second.begin(), examples.back().second.end());
	int max = 0;
	string className;
	for (auto &&c : s)
	{
		int count = std::count(examples.back().second.begin(), examples.back().second.end(), c);
		if(count > max) {
			max = count;
			className = c;
		}
	}
	
	return new DecisionTree(attribute_t(), className, LEAF_NODE);
	
}

dataset_t subset_examples(dataset_t &examples, int attributeIndex, string value)
 {
	dataset_t sub = dataset_t(examples);  // Copia estructura de dades
	for (size_t i = 0; i < sub[attributeIndex].second.size(); i++)
	{
		string vk = sub[attributeIndex].second[i];
		if(vk != value) {
			// delete record
			for (size_t j = 0; j < sub.size(); j++)
			{
				sub[j].second.erase(sub[j].second.begin()+i);
			}
			
		}
	}
	return sub;
	
 }

 dataset_t subset_examples_continuous(dataset_t &examples, const vector<string> &discretizedAttribute, string value)
 {
	 dataset_t sub = dataset_t(examples); // Copia estructura de dades
	 for (size_t i = 0; i < discretizedAttribute.size(); i++)
	 {
		 string vk = discretizedAttribute[i];
		 if (vk != value)
		 {
			 // delete record
			 for (size_t j = 0; j < sub.size(); j++)
			 {
				 sub[j].second.erase(sub[j].second.begin() + i);
			 }
		 }
	 }
	 return sub;
 }

DecisionTree *decision_tree_learning(dataset_t examples, vector<attribute_t> attributes, dataset_t parent_examples, bool id_row) {
	string classif;
	if(examples.empty()) return plurality_value(parent_examples);
	else if((classif = same_classification(examples)) != "") {
		return new DecisionTree(attribute_t(), classif, LEAF_NODE);
	}
	else if(attributes.empty()) return plurality_value(examples);
	else {
		Importance imp = Importance(examples, attributes);
		int a_i = imp.get_max_importance();
		attribute_t a = attributes[a_i];
		DecisionTree * node = new DecisionTree(a, "", LEAF_NODE);
		set<string> values;
		if(a.type == STRING) {
			values = set<string>(examples[a_i].second.begin(), examples[a_i].second.end());
		}
		else {
			values = set<string>(imp.get_discretization(a.index).second.begin(), imp.get_discretization(a.index).second.end());
		}
		for (auto &&vk: values)
		{
			dataset_t subset;
			if(a.type == STRING) {
				subset = subset_examples(examples, a.index, vk);
			} else {
				subset = subset_examples_continuous(examples, imp.get_discretization(a.index).second, vk);
			}
			vector<attribute_t> sub_att = vector<attribute_t>(attributes);
			sub_att.erase(sub_att.begin()+a_i);
			DecisionTree * child = decision_tree_learning(subset, sub_att, examples, id_row);
			node->addChild(child, vk);
		}
		return node;
	}
	return nullptr;
}

int main(int argc, char *argv[])
{
	//Falta fer check de l'input.

	if(string(argv[1]).find("learn") != string::npos)
	{
		vector<attribute_t> attr_names;
		bool id;
		dataset_t dataset = read_csv(argv[2], attr_names, id);
		// Importance importance = Importance(dataset, id);
		// int i = importance.get_max_importance();
		attr_names.erase(attr_names.end()-1);  // delete attribute of class
		if(id) attr_names.erase(attr_names.begin());  // delete attribute of ID
		DecisionTree * dt = decision_tree_learning(dataset, attr_names, dataset, id);

		dt->print_representation(cout);
	}
	else if (string(argv[1]).find("test") != string::npos) {
		cout << "Testing with decision tree in " << string(argv[3]) << endl;

		ifstream treeFile;
		treeFile.open(argv[3]);
		DecisionTree * tree = new DecisionTree(treeFile);

		cout << "Tree read." << endl << endl;
		tree->print_representation(std::cout);
	}


	return 0;
}
