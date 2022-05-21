#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <regex>
#include <vector>

using namespace std;

typedef vector<int> 	v_int;
typedef vector<float> 	v_float;
typedef vector<string> 	v_string;

typedef enum {
	STRING,
	INT,
	FLOAT
} types_t;


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

vector<void *> read_csv(string file)
{
	// File pointer
	    fstream fin;

	    // Open an existing file
	    fin.open(file, ios::in);

	    vector<void*> result;
	    vector<string> row;
	    string line, word, temp;

	    while (fin >> temp) {

	        row.clear();

	        getline(fin, line);   	//Erasing first line.
	        getline(fin, line);		//Reading first line of data.

	        // used for breaking words
	        stringstream s(line);

	        while (getline(s, word, ',')) {

	        	switch(get_type(word)){
	        		case FLOAT:
	        			result.push_back(new vector<float>);
	        			((v_float)result[0]).push_back(stof(word));
	        			break;
	        		case INT:
	        			result.push_back(new vector<int>);
	        			((v_int)result[0]).push_back(stoi(word));
	        			break;
	        		case STRING:
	        			result.push_back(new vector<string>);
	        			((v_string)result[0]).push_back(word);
	        			break;
	        	}
	        }

	    }
	return result;
}

int main(int argc, char *argv[])
{
	cout << "Hola" << endl;
	

	return 0;
}
