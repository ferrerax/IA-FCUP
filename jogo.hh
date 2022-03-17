#include "tabuleiro.h"
#include "no.hh"

typedef enum {
    DFS,
    BFS,
    IDFS,
    A_ESTRELA,
    GULOSA
} t_algorithm;

class Jogo
{
private:
    /* data */

    tabuleiro *ini;
    tabuleiro *fin;

public:
    Jogo(char *, char *);
    ~Jogo();

    bool is_solvable();

    no* search(t_algorithm a);
};
