/*
 * Algorithm.h
 *
 *  Created on: 21 de març 2022
 *      Author: quim
 */

#ifndef ALGORITHM_HH_
#define ALGORITHM_HH_
#include <string>
#include <unordered_map>

#include "no.hh"

using std::string;
using std::unordered_map;

class Algorithm {   //Abstract

protected:
	unordered_map<string,bool> visitedNodes; //keep track of visited nodes

private:
	//no * solution;

public:
	Algorithm();
	virtual ~Algorithm() = default;

	virtual bool is_empty() = 0;
	virtual no * pullTop() = 0; //Pulls and sets node as visited.
	virtual void makeAndInsertDescendants(no * node) = 0; //lines 11 and 12 from general algorithm

	bool visited(no * node);


};

#endif /* ALGORITHM_HH_ */
