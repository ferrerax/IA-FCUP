#include "jogo.hh"
#include <queue>
#include <chrono>

#include "Algorithm.hh"
#include "DFS.hh"
#include "IDFS.hh"
#include "BFS.hh"
#include "GS.hh"
#include "AStar.hh"

Jogo::Jogo(char *ini_nums, char *fin_nums)
{
    ini  = new tabuleiro(ini_nums);
    fin  = new tabuleiro(fin_nums);
    root = new no(nullptr,ini);

}

Jogo::~Jogo()
{
    delete ini;
    delete fin;
    deleteTree(root);

    //todo: Ha de recorrer tot l'arbre i borrar tots els nodes
}

bool Jogo::is_solvable() {
    int inv_i = ini->get_inversions();
    int inv_f = fin->get_inversions();

    int  blanc_row_i = N_ROW - (ini->busca_blanc()/N_ROW);  // Starts to count from bottom and index 1
    int  blanc_row_f = N_ROW - (fin->busca_blanc()/N_ROW);

    return ( (inv_i%2 == 0) == (blanc_row_i%2 == 1) ) 
                == ( (inv_f%2 == 0) == (blanc_row_f%2 == 1) );
}

bool Jogo::frontNodeIsSolution(no * node) { //El node que se'ns mostra és el resultat?

	return tabuleiro::comparar_tabs((tabuleiro *)node->getData(), fin);
}

void Jogo::printSolution() {

}

no* Jogo::generalSearchAlgorithm(Algorithm *A) {

	no * node;
	no * solution = nullptr;
	clock_t timeout = clock()/CLOCKS_PER_SEC;


	while (!A->is_empty()){
		if( (clock()/CLOCKS_PER_SEC) - timeout > TIMEOUT ){
			delete A;
			deleteTree(root);
			throw "Timeout";
		}
		node = A->pullTop();
		if (frontNodeIsSolution(node)){
			solution = node;
			break;
		}
		A->makeAndInsertDescendants(node); //Nodes created. Also marks node as visited.
		if (node->isLeaf())
		{
			node->getParent()->notifyChildLeaf(node);
			delete node;
		}
	}

	delete A;
    return solution;
}

//Recursive delete tree
void Jogo::deleteTree(no * node) {
//	delete node;
//	for (int i = 0; i < 4; i++){
//		if(node->getChildsNoCreate()[i] != nullptr){
//			deleteTree(node->getChildsNoCreate()[i]);
//		}
//	}
//	if(node != root)  //we should not delete root node.
//		delete node;
}

no* Jogo::search(t_algorithm algorithm)
{
	Algorithm * A;
	no * sol;

	if (!this->is_solvable()){
		return nullptr;
	}

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

	deleteTree(root);

	// Save statistics
	t_stat run_stats = {
		algorithm,
		1000.0*(c_end - c_start) / CLOCKS_PER_SEC,
		A->getNodesGenerated(),
		A->getNodesGenerated() * (sizeof(no) + sizeof(tabuleiro))
	};

	this->statistics.push_back(run_stats);

	return sol;
}
