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


#include "ValueType.hh"


using namespace std;


class Importance {

private:
	vector< pair< types_t,vector<string> > >  dataset;
	unordered_map<string,pair<int,vector<string>>> importance_map;
	double size;    //number of elements in dataset.
	vector<string> classes;
	bool id;
	double split_point;

	int get_num_elems(vector<string> v);
	set<string> split_elems(vector<string> v);
	double get_entropy(vector<string> v);
	double get_gain(types_t type, const vector<string> & v);


public:
	Importance(vector< pair< types_t,vector<string> > > & examples, bool id);
	virtual ~Importance();

	int get_max_importance();
	pair<double,vector<string>> get_discretization(int it);
};

#endif /* IMPORTANCE_HH_ */
