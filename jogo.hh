#include "tabuleiro.h"

class Jogo
{
private:
    /* data */

    tabuleiro *ini;
    tabuleiro *final;

public:
    Jogo(/* args */);
    ~Jogo();

    bool is_solvable();
};

Jogo::Jogo(char * ini, char * fin)
{
    ini = new tabuleiro(ini);
    final = new tabuleiro(final);   
}



Jogo::~Jogo()
{
    delete ini;
    delete final;
}
