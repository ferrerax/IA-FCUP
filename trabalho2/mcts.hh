#ifndef __MCTS_H__
#define __MCTS_H__

#include "tabuleiro.hh"
#include "player.hh"
#include "node.hh"

#include <vector>

class MCTSPlayer : public Player {

    private:
    void doIteration(tabuleiro *rootState, TreeNode *root);
    int search(tabuleiro *t, int iterations);
    TreeNode *select(std::vector<TreeNode *> * children);
    char invertPlayer(char t);

    public:
    MCTSPlayer(char token);

    int playRound(tabuleiro *t);
};
#endif // __MCTS_H__