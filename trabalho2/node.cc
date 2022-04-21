#include "node.hh"

TreeNode::TreeNode(int move, TreeNode *parent, tabuleiro *state, double constant, char playerMoved) 
    : score(0), visits(0), parent(parent), state(state), move(move), constant(constant), playerMoved(playerMoved)
{
    std::random_device rndDevice;
    randomEng = new std::mt19937(rndDevice());

    untriedMoves = state->getMoves();
}

bool TreeNode::hasMovesToTry()
{
    return this->untriedMoves.size() != 0;
}

bool TreeNode::hasChildren()
{
    return this->childNodes.size() != 0;
}

int TreeNode::getMove()
{
    return move;
}

char TreeNode::getPlayerMoved()
{
    return playerMoved;
}

int TreeNode::getScore()
{
    return score;
}

double TreeNode::calcUCB1Value(char p)
{
    if(parent == nullptr) throw "calculant UCT del root";
    int nChildren = this->childNodes.size() > 0 ? this->childNodes.size() : 1;
    return p == 'x' ? (score / nChildren) + constant * sqrt((2 * log(parent->visits)) / visits)
                    : (score / nChildren) - constant * sqrt((2 * log(parent->visits)) / visits);
}

void TreeNode::update(double result)
{
    ++visits;
    score += result;
}

int TreeNode::selectUntriedMove()
{
    std::uniform_int_distribution<int> dist(0, untriedMoves.size() - 1);
    return untriedMoves[dist(*randomEng)];
}

TreeNode* TreeNode::addChild(int move, tabuleiro *state, char player)
{
    TreeNode * n = new TreeNode(move, this, state, constant, player);
    untriedMoves.erase(remove(untriedMoves.begin(), untriedMoves.end(), move), untriedMoves.end());
    childNodes.push_back(n);
    return n;
}

std::vector<TreeNode *> * TreeNode::getChildrenList() {
    return &(this->childNodes);
}

TreeNode * TreeNode::getParent() {
    return parent;
}