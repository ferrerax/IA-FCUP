#include "tabuleiro.h"

class Jogo
{
private:
    /* data */

    tabuleiro *inicial;
    tabuleiro *final;

public:
    Jogo(/* args */);
    ~Jogo();

    bool is_solvable();
};

Jogo::Jogo(/* args */)
{
}

Jogo::~Jogo()
{
}
