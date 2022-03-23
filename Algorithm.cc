/*
 * Algorithm.cpp
 *
 *  Created on: 21 de març 2022
 *      Author: quim
 */

#include "Algorithm.hh"

Algorithm::Algorithm() {
	//solution = nullptr;
}

Algorithm::~Algorithm() {
	// TODO Auto-generated destructor stub
}

bool Algorithm::is_empty() { //NO EDIT
	return true;
}

no * Algorithm::pullTop() { //NO EDIT
	return nullptr;
}


//no* Algorithm::getSolution() { //NO EDIT
//	//return this->solution;
//}

void Algorithm::makeAndInsertDescendants(no * node) {  //NO EDIT
	return;
}

bool Algorithm::visited(no * node) {
	//Tornar a fer el canvi.
	no * n = (no *)node->getParent();
	while(n->getParent()){
		if (node->getData()->getHash() == n->getData()->getHash()){
			return true;
		}
		n = (no *)n->getParent();
	}
	return false;
	//return visitedNodes.find(node->getData()->getHash()) != visitedNodes.end();//visitedNodes[node->getData()->getHash()]; //Sabrem si l'hem visitat.
}
