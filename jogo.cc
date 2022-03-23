#include "jogo.hh"
#include<queue>

#include "Algorithm.hh"
#include "DFS.hh"
#include "IDFS.hh"
#include "BFS.hh"

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

no* Jogo::search(t_algorithm algorithm)
{
	Algorithm * A;
	no * node;
	no * solution = nullptr;
	static int i = 0;

	node = root;

	switch(algorithm){ //First node will be added.
	case a_DFS:
		A = new DFS(node);
		break;
	case a_BFS:
		A = new BFS(node);
		break;
	case a_IDFS:
		A = new IDFS(node);
		break;
	default:
		break;
	}

	if (this->is_solvable())
	{
		while (!A->is_empty()){
			i++;
			node = A->pullTop();
			if (frontNodeIsSolution(node)){
				solution = node;
				break;
			}
			//else if (!A->visited(node)) {
				A->makeAndInsertDescendants(node); //Nodes created. Also marks node as visited.
			//}
		}
		if (solution == nullptr){
			throw "Error Algoritme";
		}
		//TODO: Valorar sobre el problema d'haver arribat aqui i solution = nullptr.
	}

	delete A;
    return solution;
}
