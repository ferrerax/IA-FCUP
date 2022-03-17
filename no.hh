#include "tabuleiro.h"

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
