#include "jogo.hh"
#include <queue>
#include <chrono>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


#include "user.hh"

bool volatile timeOutFlag = false;

void sig_handler(int signum){

	// throw "Timeout";
	timeOutFlag = true;

}

Jogo::Jogo(t_player p1, t_player p2)
{
    t = new tabuleiro();
	ap1 = p1;
	ap2 = p2;
    // root = new no(nullptr,ini);

	signal(SIGALRM, sig_handler);
}

Jogo::~Jogo()
{
    delete t;
    //deleteTree(root);

}

/* void Jogo::printSolution(list<no *> &path)
{
	std::cout << "	SOLUTION PATH FOUND BY ALGORITHM " << std::to_string(this->statistics.al) << std::endl;
	for( no * n : path) {
		n->getData()->print_formatted();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
} */

void Jogo::printStatistics()
{
	printf("| Player |  Time  | Nodes Gen. | Bytes | Depth |");
	std::cout << std::endl;
	std::cout << "|" << this->statistics.p << "|" << statistics.time;
	std::cout << "|" << statistics.total_stored_nodes << "|" << statistics.total_stored_bytes;
	std::cout << "|" << statistics.steps+1 << std::endl;
}

void Jogo::play() {
	int turn = 1;

	switch (this->ap1)
	{ 
	case p_USER:
		p1 = new userPlayer();
		break;
	case p_MCTS:
		
		break;
	case p_MM:
		
		break;
	case p_AB:
		
		break;
	default:
		break;
	}

	switch (this->ap2)
	{
	case p_USER:
		p2 = new userPlayer();
		break;
	case p_MCTS:

		break;
	case p_MM:

		break;
	case p_AB:

		break;
	default:
		break;
	}

	while(!t->checkWinner()) {
		t->print_formatted();
		if(turn == 1) {

		}
	}
}

/* bool Jogo::frontNodeIsSolution(no * node) { //El node que se'ns mostra és el resultat?

	return tabuleiro::comparar_tabs((tabuleiro *)node->getData(), fin);
}

no* Jogo::generalSearchAlgorithm(Algorithm *A) {

	no * node;
	no * solution = nullptr;

	 // Register signal handler
	alarm(TIMEOUT);

	while (!A->is_empty()){
		if(timeOutFlag) {
			alarm(0);
			timeOutFlag = false;

			this->statistics.time 			  	 =	TIMEOUT;
			this->statistics.total_stored_nodes  =	A->getNodesGenerated();
			this->statistics.total_stored_bytes  =	A->getNodesGenerated() * (sizeof(no) + sizeof(tabuleiro));
			this->statistics.finished			 =  false;
			this->statistics.steps               =	A->pullTop()->getDepth(); //debug

			throw "Timeout";
		}
		node = A->pullTop();
		if (frontNodeIsSolution(node)){
			solution = node;
			break;
		}
		A->makeAndInsertDescendants(node); //Nodes created. Also marks node as visited.
//		if (node->isLeaf())
//		{
//			node->getParent()->notifyChildLeaf(node);
//			delete node;
//		}
	}
	alarm(0);

	delete A;
    return solution;
}

//Recursive delete tree
void Jogo::deleteTree(no * node) {
	for (int i = 0; i < 4; i++){
		if(node->getValidChilds() && node->getChildsNoCreate() and node->getChildsNoCreate()[i] != nullptr){
			deleteTree(node->getChildsNoCreate()[i]);
		}
	}
	if(node != root)  //we should not delete root node.
		delete node;
}

no* Jogo::search(t_algorithm algorithm)
{
	Algorithm * A;
	no * sol;

	if (!this->is_solvable()){
		return nullptr;
	}

	t_stat run_stats = {
		algorithm,
		-1,
		0,
		0,
		0,
		-1
	};

	this->statistics = run_stats;

	clock_t c_start = clock();

	switch(algorithm){ //First node will be added.
	case a_DFS:
		A = new DFS(root);
		sol = generalSearchAlgorithm(A);
		break;
	case a_BFS:
		A = new BFS(root);
		sol = generalSearchAlgorithm(A);
		break;
	case a_IDFS:
		for (int it = 0; it < MAX_DEPTH; it++){
			A = new IDFS(root,it);
			sol = generalSearchAlgorithm(A);
			if (sol){  //got solution
				break;
			}
		}
		break;
	case a_GULOSA:
		A = new GS(root,fin);
		sol = generalSearchAlgorithm(A);
		break;
	case a_A_ESTRELA:
		A = new AStar(root, fin);
		sol = generalSearchAlgorithm(A);
		break;
	default:
		break;
	}

	clock_t c_end = clock();

	this->statistics.time 			  	 =	1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
	this->statistics.total_stored_nodes  =	A->getNodesGenerated();
	this->statistics.total_stored_bytes  =	A->getNodesGenerated() * (sizeof(no) + sizeof(tabuleiro));
	this->statistics.finished			 =  true;
	this->statistics.steps               =  sol->getDepth() - 1;

	//deleteTree(root);

	// Update statistic

	return sol;
} */
