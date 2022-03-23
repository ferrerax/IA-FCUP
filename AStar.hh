#ifndef ASTAR_HH_
#define ASTAR_HH_

#include <queue>
#include <utility>
#include "config.hh"
#include "Algorithm.hh"

using std::priority_queue;

typedef std::pair<int, no *> t_pnos;

class AStar : public Algorithm
{

private:
    priority_queue<t_pnos> q;

public:
    AStar(no *node);
    virtual ~AStar();

    bool is_empty();
    no *pullTop();
    void makeAndInsertDescendants(no *node);
};

#endif /* ASTAR_HH_ */