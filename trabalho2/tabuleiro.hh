#ifndef __TABULEIRO_H__
#define __TABULEIRO_H__

//#include "tabuleiro.hh"

#include <string>
#include <map>
#include <vector>
#include <random>

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
    int mov;
    int punts[5] = {0,1,10,50,512};  //Punctuation.

    std::vector<int> moves;
    std::mt19937 *randomEng;

    int calcUtility();


public:
    tabuleiro();
    tabuleiro(tabuleiro *t); // Clona.

    static bool comparar_tabs(tabuleiro *a, tabuleiro *b);
//    int busca_blanc();

    bool makeMove(int col, char player);

    string getHash();
    int getUtility();
    void getOptions(tabuleiro * t_array[], char player);
    void getOptionsMapMax(std::multimap<int,tabuleiro *,std::greater<int>> &m, char player);
    void getOptionsMapMin(std::multimap<int,tabuleiro *> &m, char player);
    int getMov();  //Obtenir el moviment que ha creat aquest tab.
    std::vector<int> getMoves();
    int getNumberMoves();
    int simulateMove();

        void
        print();
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
