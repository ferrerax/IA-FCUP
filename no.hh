#include "tabuleiro.hh"

class no
{
private:
    /* data */
    tabuleiro *data;

    no *filhos[4];

public:
    no(tabuleiro *t);
    ~no();
};
