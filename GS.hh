/*
 * GS.hh
 *
 *  Created on: 23 de març 2022
 *      Author: quim
 */

#ifndef GS_HH_
#define GS_HH_

#include <queue>
#include <utility>
#include <vector>

#include "config.hh"
#include "Algorithm.hh"

using std::pair;
using std::priority_queue;
using std::vector;

class GS: public Algorithm {

private:
	typedef pair<int,no*> p_no;
	//bool cmp = [](p_no left, p_no right) { return (left.first) < (right.first); };
	priority_queue< p_no > q;
	tabuleiro * fin;


public:
	GS(no * node, tabuleiro * fin);
	virtual ~GS();

	bool is_empty();
	no * pullTop();
	void makeAndInsertDescendants(no * node); //lines 11 and 12 from general algorithm
};

#endif /* GS_HH_ */
