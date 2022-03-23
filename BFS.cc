/*
 * BFS.cc
 *
 *  Created on: 21 de març 2022
 *      Author: quim
 */

#include "tabuleiro.hh"
#include "BFS.hh"

BFS::BFS(no * node) {
	q.push(node);
}

BFS::~BFS() {
	// TODO Auto-generated destructor stub
}

bool BFS::is_empty() {
	return q.empty();
}

no * BFS::pullTop() {
	no * aux = q.front();
	q.pop();
	return aux;
}



void BFS::makeAndInsertDescendants(no * node) {
	//debug
	char debug[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	tabuleiro t_debug(debug);
	//end debug

	no ** childs = node->getChilds();
	visitedNodes[node->getData()->getHash()] = true;
	for (int i = 0; i < 4; i++){
		//debug
		if (childs[i] != nullptr and tabuleiro::comparar_tabs((tabuleiro *)childs[i]->getData(),&t_debug)){ //debug
				throw "S'ha empilat la solució";
				return;
		    }
		//end debug
		if (childs[i] != nullptr and !visited(childs[i])) {
			q.push(childs[i]);
		}
	}
}
