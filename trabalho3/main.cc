#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <regex>
#include <vector>

#include "ValueType.h"
#include "FloatValue.h"
#include "IntValue.h"
#include "StringValue.h"
#include "DecisionTree.hh"
#include "Attribute.hh"

using namespace std;

typedef vector<int> 	v_int;
typedef vector<float> 	v_float;
typedef vector<string> 	v_string;

typedef vector<vector<ValueType>> dataset_t;

vector<attribute_t> att_list;

void Usage()
{
	std::cout << "Usage: ./trabalho3 <file.csv>" << std::endl;
	//std::cout << "	Player options: User | MCTS | MiniMax | AlphaBeta" << std::endl;
	exit(1);
}

types_t get_type(string s){

	types_t result;

	if(regex_match(s, regex("[+-]?([0-9]*[.])?[0-9]+")))
	{
		result = FLOAT;
	}
	else if(regex_match(s, regex("^[0-9]*$")))
	{
		result = INT;
	}
	else
	{
		result = STRING;
	}

	return result;
}

vector<vector<ValueType>> read_csv(string file)
{
	// File pointer
	    fstream fin;

	    // Open an existing file
	    fin.open(file, ios::in);

	    vector<vector<ValueType>> result;
	    string line, word, temp;

	    //First time

	    getline(fin, line);   	//Erasing first line.
	    getline(fin, line);		//Reading first line of data.

	    // used for breaking words
	    stringstream s(line);

	    while (getline(s, word, ',')) {			//Setting values and types. TODO: missings
	    	vector<ValueType> aux;
	    	switch(get_type(word)){
	    	case FLOAT:
	    		aux.push_back((ValueType)FloatValue((float)stof(word)));
	    		result.push_back(aux);
	    		break;
	    	case INT:
	    		aux.push_back((ValueType)IntValue(stoi(word)));
	    		result.push_back(aux);
	    		break;
	    	case STRING:
	    		aux.push_back((ValueType)StringValue(word));
	    		result.push_back(aux);
	    		break;
	    	}
	    }

	    int i = 0; //vector iterator

	    while (fin >> temp) {
	    	while (getline(s, word, ',')) {			//Setting values and types
	    		switch(get_type(word)){
	    		case FLOAT:
	    			result[i].push_back((ValueType)FloatValue((float)stof(word)));
	    			break;
	    		case INT:
	    			result[i].push_back((ValueType)IntValue((int)stoi(word)));
	    			break;
	    		case STRING:
	    			result[i].push_back((ValueType)StringValue(word));
	    			break;
	    		}
	    		i = (i+1)%result.size();
	    	}
	    }
	return result;
}



DecisionTree *decision_tree_learning(dataset_t examples, vector<attribute_t> attributes, dataset_t parent_examples) {
//	string classif;
//	if(examples.empty()) return plurality_value(parent_examples);
//	else if((classif = same_classification(examples)) != "") {
//
//	}
//	else if(attributes.empty()) return plurality_value(examples);
//	else {
//x
//	}
//	return nullptr;

}

string same_classification(dataset_t examples) {

	return "";
}

DecisionTree *plurality_value(dataset_t examples) {

}

float importance(attribute_t a, dataset_t examples) {

}

int main(int argc, char *argv[])
{
	cout << "Hola" << endl;


	return 0;
}
