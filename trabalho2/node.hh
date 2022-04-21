#ifndef __NODE_H__
#define __NODE_H__

#include "tabuleiro.hh"
#include <vector>
#include <random>

class TreeNode {
    private:
        tabuleiro *state;
        int move;
        TreeNode *parent;
        double constant;
        char playerMoved;

        int visits;
        int score;

        std::vector<TreeNode *> childNodes;
        std::vector<int> untriedMoves;

        std::mt19937 *randomEng;

    public:
        TreeNode(int move, TreeNode *parent, tabuleiro *state, double constant, char playerMoved);

        bool hasMovesToTry();
        bool hasChildren();

        std::vector<TreeNode *> * getChildrenList();
        TreeNode * getParent();
        int getMove();
        char getPlayerMoved();
        int getScore();

        double calcUCB1Value();
        void update(double result);
        int selectUntriedMove();
        TreeNode *addChild(int move, tabuleiro *state, char player);

};
#endif // __NODE_H__