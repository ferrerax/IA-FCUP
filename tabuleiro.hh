#ifndef __TABULEIRO_H__
#define __TABULEIRO_H__

#include "config.hh"

typedef enum {
    RIGHT,
    LEFT,
    TOP,
    BOT
} t_dir;

class tabuleiro
{
private:
    /* data */
    char matriu[N_NUMEROS];
    tabuleiro(char *nums, t_dir dir);

public:
    tabuleiro(char * numbs);
    ~tabuleiro();

    char consulta_n(int n);
    static bool comparar_tabs(tabuleiro *a, tabuleiro *b);
    int busca_blanc();

    void print();
    void print_formatted();

    int get_inversions();

    tabuleiro* right();
    tabuleiro* left();
    tabuleiro* top();
    tabuleiro* bot();

    bool operator== (tabuleiro x){
    	return comparar_tabs(this, &x);
    }

};



#endif // __TABULEIRO_H__
