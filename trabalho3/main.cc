#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <regex>
#include <vector>
#include <utility>
#include <iostream>

#include "DecisionTree.hh"
#include "Attribute.hh"
#include "ValueType.hh"

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

dataset_t read_csv(string file)
{
	// File pointer
	    fstream fin;

	    // Open an existing file
	    fin.open(file, ios::in);

	    dataset_t result;
	    string line, word, temp;

	    //First time

	    getline(fin, line);   	//Erasing first line.
	    getline(fin, line);		//Reading first line of data.

	    // used for breaking words
	    stringstream s(line);

	    while (getline(s, word, ',')) {			//Setting values and types. TODO: missings
	    	switch(get_type(word)){
	    	case FLOAT:
	    		result.push_back(make_pair(FLOAT, vector<string>()));
	    		break;
	    	case INT:
	    		result.push_back(make_pair(INT, vector<string>()));
	    		break;
	    	case STRING:
	    		result.push_back(make_pair(STRING, vector<string>()));
	    		break;
	    	}
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

	return "";
}

DecisionTree *plurality_value(dataset_t examples)
{
}

float importance(attribute_t a, dataset_t examples)
{
}

DecisionTree *decision_tree_learning(dataset_t examples, vector<attribute_t> attributes, dataset_t parent_examples) {
	string classif;
	if(examples.empty()) return plurality_value(parent_examples);
	else if((classif = same_classification(examples)) != "") {

	}
	else if(attributes.empty()) return plurality_value(examples);
	else {

	}
	return nullptr;

}

int main(int argc, char *argv[])
{
	//Falta fer check de l'input.

	if(string(argv[1]).find("learn") != string::npos)
	{
		read_csv(argv[2]);
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
