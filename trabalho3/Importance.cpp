/*
 * Importance.cpp
 *
 *  Created on: 25 May 2022
 *      Author: madmarx
 */



#include "Importance.hh"

using namespace std;

Importance::Importance(vector< pair< types_t,vector<string> > > & dataset, vector<attribute_t> & attributes ) {

	this->dataset 			= dataset;
	this->importance_map 	= unordered_map<string,pair<int,vector<string>>>();
	this->size 				= dataset[0].second.size();
	this->classes			= this->dataset[this->dataset.size()-1].second;
	this->split_point		= 0;
	this->attributes		= attributes;
	this->last_result		= -1;
}

int Importance::get_max_importance() {

	int result;
	double dataset_entropy;
	double info_gain = 0;
	double max = 0;

	dataset_entropy = get_entropy(this->classes);

	for (size_t i = 0; i < attributes.size(); i++){
		info_gain = dataset_entropy-get_gain(dataset[attributes[i].index].first, i, dataset[attributes[i].index].second);
		if (info_gain > max){
			max = info_gain;
			result = i;
		}
	}

	this->last_result = result;
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
	double size = (double)v.size();
	double entropy = 0;
	double pi;

	num_elems = get_num_elems(v);
	elems = split_elems(v);

	for (string s : elems){
		pi = (double)count(v.begin(), v.end(), s)/size;
		entropy -= pi * log2(pi);
	}

	return entropy;
}

double Importance::get_gain(types_t type, int attr_it, const vector<string> & v) {

	double gain = 0, pi;
	this->importance_map.clear();

	if(type == INT){
		vector<int> vec;
		for (string s : v){
			vec.push_back(stoi(s));
		}
		sort(vec.begin(), vec.end());
		split_point = vec[vec.size()/2];
	}
	else if(type == FLOAT) {
		vector<double> vec;
		for (string s : v){
			vec.push_back(stof(s));
		}
		sort(vec.begin(), vec.end());
		split_point = vec[vec.size()/2];
	}
	else {
		//No action
	}

	for (int i = 0; i < this->size; i++){
		if(type == INT) {
			string value = stoi(v[i]) > (int)split_point ? ">" + to_string(split_point) :"<=" + to_string(split_point);
			importance_map[value].second.push_back(classes[i]);
			importance_map[value].first++;
			discretizations[attr_it].push_back(value);
		}
		else if (type == FLOAT){
			string value = stof(v[i]) > split_point ? ">" + to_string(split_point):"<=" + to_string(split_point);
			importance_map[value].second.push_back(classes[i]);
			importance_map[value].first++;
			discretizations[attr_it].push_back(value);
		} else {
			importance_map[v[i]].second.push_back(classes[i]);
			importance_map[v[i]].first++;
		}
	}

	for (pair<string,pair<int,vector<string>>> i : importance_map){
		pi = ((double)importance_map[i.first].first/size);		//value in total values
		gain += pi*get_entropy(i.second.second);
	}

	return gain;
}

Importance::~Importance() {
	// TODO Auto-generated destructor stub
}

pair<double, vector<string>* > Importance::get_discretization() {

	return make_pair(this->split_point, &this->discretizations[last_result]);
}
