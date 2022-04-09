#ifndef ASTAR_HH_
#define ASTAR_HH_

#include <queue>
#include <utility>
#include <vector>

#include "config.hh"
#include "Algorithm.hh"

using std::pair;
using std::priority_queue;
using std::vector;

class AStar : public Algorithm
{

private:
    typedef pair<int, no *> p_no;
    // bool cmp = [](p_no left, p_no right) { return (left.first) < (right.first); };
    priority_queue<p_no, vector<p_no>, std::greater<p_no>> q;

    tabuleiro *fin;

public:
    AStar(no *node, tabuleiro *fin);
    virtual ~AStar();

    bool is_empty();
    no *pullTop();
    void makeAndInsertDescendants(no *node); // lines 11 and 12 from general algorithm
};

#endif /* ASTAR_HH_ */