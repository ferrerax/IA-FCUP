#include "jogo.hh"

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