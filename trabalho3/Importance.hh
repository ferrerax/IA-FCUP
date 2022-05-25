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

#include "ValueType.hh"


using namespace std;


class Importance {

private:
	vector< pair< types_t,vector<string> > >  dataset;
	double size;    //number of elements in dataset.
	vector<string> classes;
	bool id;

	int get_num_elems(vector<string> v);
	set<string> split_elems(vector<string> v);
	double get_entropy(vector<string> v);
	double get_dataset_entropy();
	double get_gain(vector<string> v);


public:
	Importance(vector< pair< types_t,vector<string> > > & examples, bool id);
	virtual ~Importance();

	int get_max_importance();
};

#endif /* IMPORTANCE_HH_ */
