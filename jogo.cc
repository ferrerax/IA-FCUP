#include "jogo.hh"
#include<queue>

#include "Algorithm.hh"
#include "DFS.hh"
Jogo::Jogo(char *ini_nums, char *fin_nums)
{
    ini = new tabuleiro(ini_nums);
    fin = new tabuleiro(fin_nums);
}

Jogo::~Jogo()
{
    delete ini;
    delete fin;
}

bool Jogo::is_solvable() {
    int inv_i = ini->get_inversions();
    int inv_f = fin->get_inversions();

    int  blanc_row_i = ini->busca_blanc()%N_ROW;
    int  blanc_row_f = fin->busca_blanc()%N_ROW;

    return ( (inv_i%2 == 0) == (blanc_row_i%2 == 1) ) 
                == ( (inv_f%2 == 0) == (blanc_row_f%2 == 1) );
}

bool Jogo::frontNodeIsSolution(no * node) { //El node que se'ns mostra és el resultat?
	return tabuleiro::comparar_tabs((tabuleiro *)node->getData(), fin);
}

no* Jogo::search(t_algorithm algorithm)
{
	Algorithm A;
	no * node;

	node = new no(ini);

	switch(algorithm){ //First node will be added.
	case a_DFS:
		A = DFS(node);
		break;
	default:
		break;
	}

    if (!this->is_solvable())
    {
        return nullptr;
    }
    

    while (!A.is_empty()){
    	node = A.pullTop();
    	if (frontNodeIsSolution(node)){
    		return A.returnSolution();
    	}
    	A.makeAndInsertDescendants();
    }

    return nullptr;
}
