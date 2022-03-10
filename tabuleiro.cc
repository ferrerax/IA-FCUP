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

int tabuleiro::get_inversions() {

    int inv_count = 0;
    for (int i = 0; i < N_NUMEROS - 1; i++)
        for (int j = i + 1; j < N_NUMEROS; j++)
            if (matriu[i] > matriu[j])
                inv_count++;
}