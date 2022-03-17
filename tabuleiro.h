#ifndef __TABULEIRO_H__
#define __TABULEIRO_H__

#define N_ROW 4
#define N_NUMEROS N_ROW*N_ROW

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

};



#endif // __TABULEIRO_H__