/*
 * DFS.cc
 *
 *  Created on: 21 de març 2022
 *      Author: quim
 */

#include "DFS.hh"

DFS::DFS(no * node) {
	queue.push(node);
}

DFS::~DFS() {
	// TODO Auto-generated destructor stub
}

bool DFS::is_empty() {
	return queue.empty();
}

no * DFS::pullTop() {
	no * aux = queue.top();
	queue.pop();
	visitedNodes[*aux->getData()] = true;
	return aux;
}



void DFS::makeAndInsertDescendants(no * node) {
	no ** childs = node->getChilds();
	for (int i = 0; i < 4; i++){
		queue.push(childs[i]);
	}
}
