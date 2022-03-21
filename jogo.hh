#include "tabuleiro.hh"
#include "no.hh"

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

    tabuleiro *ini;
    tabuleiro *fin;

    bool frontNodeIsSolution(no * node);

public:
    Jogo(char *, char *);
    ~Jogo();

    bool is_solvable();

    no* search(t_algorithm a);
};
