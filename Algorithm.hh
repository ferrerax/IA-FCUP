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

class Algorithm {

protected:
	unordered_map<string,bool> visitedNodes; //keep track of visited nodes

private:
	//no * solution;

public:
	Algorithm();
	virtual ~Algorithm();

	bool is_empty();
	no * pullTop(); //Pulls and sets node as visited.
	bool visited(no * node);
	void makeAndInsertDescendants(no * node); //lines 11 and 12 from general algorithm


};

#endif /* ALGORITHM_HH_ */
