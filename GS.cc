/*
 * GS.cc
 *
 *  Created on: 21 de març 2022
 *      Author: quim
 */

#include "tabuleiro.hh"
#include "GS.hh"
#include <utility>

using std::pair;

GS::GS(no * node, tabuleiro * fin) {
	q.push(pair<int,no*>(0,node));
	this->fin = fin;
}

GS::~GS() {
	// TODO Auto-generated destructor stub
}

bool GS::is_empty() {
	return q.empty();
}

no * GS::pullTop() {
	no * aux = q.top().second;
	q.pop();
	return aux;
}

void GS::makeAndInsertDescendants(no * node) {
	no ** childs = node->getChilds();
	//visitedNodes[node->getData()->getHash()] = true;
	for (int i = 0; i < 4; i++){
		if (childs[i] != nullptr /*and !visited(childs[i])*/) {

#if HEURISTIC == 1
			int h = childs[i]->getData()->getNumberPieces(fin);
#else
			int h = childs[i]->getData()->getManhattanDistance(fin);
#endif

			nodesGenerated++;
			q.push(pair<int,no*>(h,childs[i]));
		}
	}
}
