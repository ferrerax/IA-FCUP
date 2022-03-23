/*
 * IDFS.hh
 *
 *  Created on: 21 de març 2022
 *      Author: quim
 */

#ifndef IDFS_HH_
#define IDFS_HH_

#define DEFAULT_DEPTH 50

#include <stack>
#include "config.hh"
#include "Algorithm.hh"

using std::stack;

class IDFS: public Algorithm {

private:
stack<no*> stck;


public:
	IDFS(no * node);
	virtual ~IDFS();

	bool is_empty();
	no * pullTop();
	void makeAndInsertDescendants(no * node); //lines 11 and 12 from general algorithm
};

#endif /* IDFS_HH_ */
