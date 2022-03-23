/*
 * BFS.hh
 *
 *  Created on: 23 de març 2022
 *      Author: quim
 */

#ifndef BFS_HH_
#define BFS_HH_

#include <queue>
#include "config.hh"
#include "Algorithm.hh"

using std::queue;

class BFS: public Algorithm {

private:
queue<no*> q;

public:
	BFS(no * node);
	virtual ~BFS();

	bool is_empty();
	no * pullTop();
	void makeAndInsertDescendants(no * node); //lines 11 and 12 from general algorithm
};

#endif /* BFS_HH_ */
