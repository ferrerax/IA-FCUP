#include "tabuleiro.h"
#include <iostream>
#include<string.h>

using namespace std;

tabuleiro::tabuleiro(/* args */)
{
    
}

tabuleiro::tabuleiro(char *numbs) {
    memcpy(matriu, numbs, N_NUMEROS);
}

int tabuleiro::busca_blanc(){
        for(int i = 0; i < N_NUMEROS; i++){
            if (matriu[i] == 0)
                return i;
        }
    return -1;
}

int tabuleiro::get_inversions() {
    unsigned int inv_count = 0;
    
    for (int i = 0; i < n; i ++){
        for (int j = i + 1; j < n; j++){
            if( (matriu[j] < matriu[i]) and (matriu[j] != 0) )
                inv_count++;
        }
    }

    return inv_count;
}
