/*
 * Importance.hh
 *
 *  Created on: 25 May 2022
 *      Author: madmarx
 */

#ifndef IMPORTANCE_HH_
#define IMPORTANCE_HH_

#include <utility>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <algorithm>


#include "Attribute.hh"
#include "ValueType.hh"



using namespace std;


class Importance {

private:
	vector< pair< types_t,vector<string> > >  dataset;
	vector<attribute_t> attributes;
	unordered_map<string,pair<int,vector<string>>> importance_map;
	map<int,vector<string>> discretizations;
	double size;    //number of elements in dataset.
	vector<string> classes;
	int last_result;
	double split_point;

	int get_num_elems(vector<string> v);
	set<string> split_elems(vector<string> v);
	double get_entropy(vector<string> v);
	double get_gain(types_t type, int attr_it, const vector<string> & v);


public:
	Importance(vector< pair< types_t,vector<string> > > & examples, vector<attribute_t> & attributes );
	virtual ~Importance();

	int get_max_importance();
	pair<double,vector<string>> get_discretization();
};

#endif /* IMPORTANCE_HH_ */
