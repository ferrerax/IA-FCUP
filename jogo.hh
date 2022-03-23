#include "tabuleiro.hh"
#include "no.hh"
#include "Algorithm.hh"
#include <vector>

typedef enum {
    a_DFS,
    a_BFS,
    a_IDFS,
    a_A_ESTRELA,
    a_GULOSA
} t_algorithm;

struct t_stat {
    t_algorithm al;
    double time;
    int total_stored_nodes;
    size_t total_stored_bytes;
};

class Jogo
{
private:
    /* data */

    std::vector<t_stat> statistics;

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
