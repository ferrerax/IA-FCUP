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
	return visitedNodes[node->getData()->getHash()]; //Sabrem si l'hem visitat.
}
