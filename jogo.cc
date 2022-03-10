#include "jogo.hh"

bool Jogo::is_solvable() {
    int inv_i = inicial->get_inversions();
    int inv_f = final->get_inversions();

    int  blanc_row_i = inicial->busca_blanc()%N_ROW;
    int  blanc_row_f = final->busca_blanc()%N_ROW;

    return ( (inv_i%2 == 0) == (blanc_row_i%2 == 1) ) 
                == ( (inv_f%2 == 0) == (blanc_row_f%2 == 1) );
}