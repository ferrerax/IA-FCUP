#ifndef __TABULEIRO_H__
#define __TABULEIRO_H__

#include "tabuleiro.hh"

#include <string>

#include "config.hh"

using std::string;

//typedef enum {
//    RIGHT,
//    LEFT,
//    TOP,
//    BOT
//} t_dir;

class tabuleiro
{
private:
    /* data */
    char matriu[N_NUMEROS];
    int punts[4] = {0,10,50,512};  //Punctuation.


public:
    tabuleiro();

    static bool comparar_tabs(tabuleiro *a, tabuleiro *b);
//    int busca_blanc();

    bool makeMove(int col, int player);

    string getHash();

    void print();
    void print_formatted();

    int checkWinner();

//    int get_inversions();

//    tabuleiro* right();
//    tabuleiro* left();
//    tabuleiro* top();
//    tabuleiro* bot();

//	//Heuristics
//	int getNumberPieces(tabuleiro * t);
//	int getManhattanDistance(tabuleiro * t);

};



#endif // __TABULEIRO_H__
