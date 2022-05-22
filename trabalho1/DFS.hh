/*
 * DFS.hh
 *
 *  Created on: 21 de març 2022
 *      Author: quim
 */

#ifndef DFS_HH_
#define DFS_HH_

#include <stack>
#include "config.hh"
#include "Algorithm.hh"

using std::stack;

class DFS: public Algorithm {

private:
stack<no*> stck;

public:
	DFS(no * node);
	virtual ~DFS();

	bool is_empty();
	no * pullTop();
	void makeAndInsertDescendants(no * node); //lines 11 and 12 from general algorithm
};

#endif /* DFS_HH_ */
