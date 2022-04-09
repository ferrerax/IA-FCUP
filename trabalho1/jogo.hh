#ifndef __JOGO_H__
#define __JOGO_H__

#include "tabuleiro.hh"
#include "no.hh"
#include "Algorithm.hh"
#include <vector>

typedef enum {
    a_DFS,
    a_BFS,
    a_IDFS,
    a_A_ESTRELA,
    a_GULOSA
} t_algorithm;

struct t_stat {
    t_algorithm al;
    double time;
    int total_stored_nodes;
    size_t total_stored_bytes;
    bool finished;
    int steps;
};

class Jogo
{
private:
    /* data */

    t_stat statistics;


    no * root;

    tabuleiro *ini;
    tabuleiro *fin;


    bool frontNodeIsSolution(no * node);
    no * generalSearchAlgorithm(Algorithm * A);
    void deleteTree(no * node);


public:
    
    Jogo(char *, char *);
    ~Jogo();

    bool is_solvable();
    void printSolution(list<no *> &path);
    void printStatistics();


    no* search(t_algorithm a);
};

#endif
