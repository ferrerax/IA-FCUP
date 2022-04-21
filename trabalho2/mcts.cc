#include "mcts.hh"

MCTSPlayer::MCTSPlayer(char token)
{
    this->token = token;
}

int MCTSPlayer::playRound(tabuleiro *t)
{

    return search(t, MCTS_ITERATIONS);
}

int MCTSPlayer::search(tabuleiro *t, int iterations)
{

    TreeNode *rootNode = new TreeNode(-1, nullptr, t, 1.0, this->opponentToken());

    for (int i = 0; i < iterations; ++i)
    {
        doIteration(t, rootNode);

    }

    int score = 0, move = -1;
    std::vector<TreeNode *> potentialChild(*rootNode->getChildrenList());

    sort(begin(potentialChild), end(potentialChild), [](TreeNode* x, TreeNode* y)
         { return x->getScore() > y->getScore(); });
    return token == 'x' ? potentialChild[0]->getMove() : potentialChild.back()->getMove();
}

void MCTSPlayer::doIteration(tabuleiro *rootState, TreeNode *root)
{
    TreeNode *node = root;
    tabuleiro *state = new tabuleiro(rootState);

    // Select
    while (!node->hasMovesToTry() && node->hasChildren())
    {
        node = this->select(node->getChildrenList());
        state->makeMove(node->getMove(), invertPlayer(token));
    }

    // Expand
    if (node->hasMovesToTry())
    {
        int move = node->selectUntriedMove();
        state->makeMove(move, invertPlayer(node->getPlayerMoved()));
        node = node->addChild(move, state, invertPlayer(node->getPlayerMoved()));
    }

    // Rollout
    char lastPlayer = node->getPlayerMoved();

    int i = 0;
    while (state->getNumberMoves() != 0 && abs(state->getUtility()) != 512 && i < 20)
    {
        
        state->makeMove(state->simulateMove(), invertPlayer(lastPlayer));
        lastPlayer = invertPlayer(lastPlayer);
        i++;
    }

    // Backpropagate
    while (node != nullptr)
    {
        node->update(state->getUtility());
        node = node->getParent();
    }
}

TreeNode *MCTSPlayer::select(std::vector<TreeNode *> *children)
{
    TreeNode *nw;
    double cValue = 0;
    for (size_t i = 0; i < (*children).size(); i++)
    {
        double v = (*children)[i]->calcUCB1Value();
         if (v > cValue)
        {
            nw = (*children)[i];
            cValue = v;
        }
    }

    return nw;
}

char MCTSPlayer::invertPlayer(char t)
{
    return t == 'x' ? 'o' : 'x';
}