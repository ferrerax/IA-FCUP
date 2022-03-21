#include "tabuleiro.hh"
#include <iostream>
#include<string.h>

using namespace std;

tabuleiro::tabuleiro(char *numbs) {
    memcpy(matriu, numbs, N_NUMEROS);
}

tabuleiro::~tabuleiro()
{
    
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
    
    for (int i = 0; i < N_NUMEROS; i ++){
        for (int j = i + 1; j < N_NUMEROS; j++){
            if( (matriu[j] < matriu[i]) and (matriu[j] != 0) )
                inv_count++;
        }
    }

    return inv_count;
}

tabuleiro* tabuleiro::right()
{
    int blanc = this->busca_blanc();
    if(blanc % N_ROW != N_ROW-1) {
        return new tabuleiro(this->matriu, RIGHT);
    } else {
        return NULL;
    }
}

tabuleiro *tabuleiro::left()
{
    int blanc = this->busca_blanc();
    if (blanc % N_ROW != 0)
    {
        return new tabuleiro(this->matriu, LEFT);
    }
    else
    {
        return NULL;
    }
}
tabuleiro *tabuleiro::top()
{
    int blanc = this->busca_blanc();
    if (blanc >= N_ROW)
    {
        return new tabuleiro(this->matriu, TOP);
    }
    else
    {
        return NULL;
    }
}
tabuleiro *tabuleiro::bot()
{
    int blanc = this->busca_blanc();
    if (blanc < N_ROW*(N_ROW-1))
    {
        return new tabuleiro(this->matriu, BOT);
    }
    else
    {
        return NULL;
    }
}
tabuleiro::tabuleiro(char *nums, t_dir dir)
{
    memcpy(matriu, nums, N_NUMEROS);
    int b = this->busca_blanc();

    switch (dir)
    {
    case RIGHT:
        matriu[b] = matriu[b+1];
        matriu[b+1] = 0;
        break;
    case LEFT:
        matriu[b] = matriu[b - 1];
        matriu[b - 1] = 0;
        break;
    case TOP:
        matriu[b] = matriu[b - N_ROW];
        matriu[b - N_ROW] = 0;
        break;
    case BOT:
        matriu[b] = matriu[b + N_ROW];
        matriu[b + N_ROW] = 0;
        break;
    default:
        break;
    }
}
