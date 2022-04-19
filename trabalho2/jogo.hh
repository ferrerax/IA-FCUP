#ifndef __JOGO_H__
#define __JOGO_H__

#include "tabuleiro.hh"
#include "player.hh"
#include <vector>

typedef enum {
    p_USER,
    p_MCTS,
    p_AB,
    p_MM
} t_player;

struct t_stat {
    t_player p;
    double time;
    int total_stored_nodes;
    size_t total_stored_bytes;
    int steps;
};

class Jogo
{
private:
    /* data */
    
    t_player ap1, ap2;
    Player *p1, *p2;

    t_stat statistics;


    // no * root;

    tabuleiro *t;

    //bool frontNodeIsSolution(no * node);
    //no * generalSearchAlgorithm(Algorithm * A);
    //void deleteTree(no * node);
    void round(Player * p, char token);


public:
    
    Jogo(t_player, t_player);
    ~Jogo();

    //void printSolution(list<no *> &path);
    void printStatistics();


    // no* search(t_algorithm a);
    void play();
};

#endif
