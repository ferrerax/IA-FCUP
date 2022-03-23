#include "tabuleiro.hh"
#include "no.hh"
#include "Algorithm.hh"

typedef enum {
    a_DFS,
    a_BFS,
    a_IDFS,
    a_A_ESTRELA,
    a_GULOSA
} t_algorithm;

class Jogo
{
private:
    /* data */

	no * root;

    tabuleiro *ini;
    tabuleiro *fin;

    bool frontNodeIsSolution(no * node);
    no * generalSearchAlgorithm(Algorithm * A);

public:
    Jogo(char *, char *);
    ~Jogo();

    bool is_solvable();
    void printSolution();
    no* search(t_algorithm a);
};
