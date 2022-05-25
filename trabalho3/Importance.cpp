/*
 * Importance.cpp
 *
 *  Created on: 25 May 2022
 *      Author: madmarx
 */


#include <unordered_map>
#include <map>

#include "Importance.hh"

using namespace std;

Importance::Importance(vector< pair< types_t,vector<string> > > & dataset, bool id) {

	this->dataset 	= dataset;
	this->size 		= dataset[0].second.size();
	this->classes	= this->dataset[this->dataset.size()-1].second;
	this->id 		= id;
}

int Importance::get_max_importance() {

	int result;
	double dataset_entropy;
	double info_gain;
	double max = 0;

	dataset_entropy = get_entropy(this->classes);

	for (int i = id ? 1: 0; i < dataset.size(); i++){
		info_gain = dataset_entropy-get_gain(dataset[i].second);
		if (info_gain > max){
			max = info_gain;
			result = i;
		}
	}

	return result;
}

int Importance::get_num_elems(vector<string> v) {

	return std::set<string>( v.begin(), v.end() ).size();
}

set<string> Importance::split_elems(vector<string> v) {
	return std::set<string>( v.begin(), v.end() );
}

double Importance::get_entropy(vector<string> v) {

	int num_elems;
	set<string> elems;
	double entropy = 0;
	double pi;

	num_elems = get_num_elems(v);
	elems = split_elems(v);

	for (string s : elems){
		int a = (double)count(v.begin(), v.end(), s);
		pi = (double)count(v.begin(), v.end(), s)/this->size;
		entropy -= pi * log2(pi);
	}

	return entropy;
}

double Importance::get_gain(vector<string> v) {

	double gain = 0, aux_gain = 0, pi;
	unordered_map<string,pair<int,vector<string>>> map;

	for (int i = 0; i < this->size; i++){
		map[v[i]].second.push_back(classes[i]);
		map[v[i]].first++;
	}

	for (pair<string,pair<int,vector<string>>> i : map){
		pi = ((double)map[i.first].first/size);		//value in total values
		gain += pi*get_entropy(i.second.second);
	}

	return gain;
}

Importance::~Importance() {
	// TODO Auto-generated destructor stub
}


