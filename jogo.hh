#include "tabuleiro.h"
#include "no.hh"

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
};
